#include "Dispatcher.hpp"
#include "CommandHandler.hpp"
#include "Message.hpp"
#include "Validation.hpp"
#include <iostream>

namespace
{
    static bool hasCsvList(const std::string& value)
    {
        return value.find(',') != std::string::npos;
    }

    static bool isStdinClient(int fd)
    {
        return (fd == 0);
    }

    static void logParseError(int fd, const std::string& message)
    {
        if (isStdinClient(fd))
            std::cout << "[error] parse: " << message << std::endl;
        else
            std::cout << "[error] parse fd=" << fd << ": " << message << std::endl;
    }

    static void logCommandError(int fd, const std::string& message)
    {
        if (isStdinClient(fd))
            std::cout << "[error] command: " << message << std::endl;
        else
            std::cout << "[error] command fd=" << fd << ": " << message << std::endl;
    }

    static void logParsedOk(int fd, const Message& msg)
    {
        if (isStdinClient(fd))
            std::cout << "[ok] command accepted: " << msg.getCommand() << std::endl;
        else
            std::cout << "[ok] command accepted fd=" << fd << ": " << msg.getCommand() << std::endl;
    }
}

Dispatcher::Dispatcher(Server& server, ServerData& data) : _server(server), _ircServer(data)
{
    const std::string validCommands[] =
    { "PASS", "NICK", "USER", "JOIN", "PRIVMSG", "NOTICE", "TOPIC", "INVITE",
        "KICK", "MODE", "PART" };

    size_t nCommands = sizeof(validCommands) / sizeof(validCommands[0]);
    _validCommands.insert(validCommands, validCommands + nCommands);
}

Dispatcher::~Dispatcher()
{
    std::map<int, Client*>::iterator it = _clients.begin();
    while (it != _clients.end())
    {
        delete it->second;
        ++it;
    }
    std::map<std::string, Channel*>::iterator cit = _ircServer.getChannelsBegin();
    std::map<std::string, Channel*>::iterator cend = _ircServer.getChannelsEnd();
    while (cit != cend)
    {
        delete cit->second;
        ++cit;
    }
}

void Dispatcher::sendMessage(int fd, const std::string& msg) const
{ _server.sendToClient(fd, msg); }

void Dispatcher::sendBroadcast(const std::map<std::string, Client*>& clients,
                               const std::string& message) const
{
    for (std::map<std::string, Client*>::const_iterator it = clients.begin();
         it != clients.end(); ++it)
    {
        Client* client = it->second;
        if (client != NULL)
        {
            sendMessage(client->getSocket(), message);
        }
    }
}

const std::string& Dispatcher::getServername() const
{ return _ircServer.getServername(); }

Client* Dispatcher::getClient(const std::string& nick)
{ return _ircServer.getClient(nick); }

void Dispatcher::addClientByNick(const std::string& nick, Client* client)
{ _ircServer.addClientByNick(nick, client); }

void Dispatcher::removeClientByNick(const std::string& nick)
{ _ircServer.removeClientByNick(nick); }

bool Dispatcher::isNickInUse(const std::string& nick) const
{ return _ircServer.isNickInUse(nick); }

int Dispatcher::getClientSocketByNick(const std::string& nick) const
{ return _ircServer.getClientSocketByNick(nick); }

void Dispatcher::addPendingInvitation(const std::string& channelName, const std::string& invited)
{ _ircServer.addPendingInvitation(channelName, invited); }

void Dispatcher::removePendingInvitation(const std::string& channelName, const std::string& invited)
{ _ircServer.removePendingInvitation(channelName, invited); }

Client* Dispatcher::getOrCreateClient(int fd, const std::string &ip)
{
    std::map<int, Client*>::iterator it = _clients.find(fd);
    if (it != _clients.end())
        return (it->second);

    Client *client = new Client(fd, ip);
    _clients.insert(std::make_pair(fd, client));
    return (client);
}

void Dispatcher::onClientConnected(int fd, const std::string &ip)
{
    std::cout << "[client] connected fd=" << fd << " ip=" << ip << std::endl;
    getOrCreateClient(fd, ip);
    _clientBuffers[fd] = ClientBuffer();
}

void Dispatcher::onClientDisconnected(int fd)
{
    std::cout << "[client] disconnected fd=" << fd << std::endl;
    std::map<int, Client*>::iterator it = _clients.find(fd);
    if (it != _clients.end())
    {
        std::string nick = it->second->getNickname();
        std::string username = it->second->getUsername();
        
        std::map<std::string, Channel*>::iterator cit = _ircServer.getChannelsBegin();
        std::map<std::string, Channel*>::iterator cend = _ircServer.getChannelsEnd();
        while (cit != cend)
        {
            if (cit->second != NULL && cit->second->hasMember(username))
            {
                std::string channelName = cit->first;
                ++cit;
                _ircServer.removeMember(channelName, username);
            }
            else
                ++cit;
        }
        
        if (!nick.empty())
            removeClientByNick(nick);
        delete it->second;
        _clients.erase(it);
    }
    _clientBuffers.erase(fd);
}

void Dispatcher::onBytesReceived(int fd, const char *data, std::size_t len)
{
    std::map<int, ClientBuffer>::iterator bit = _clientBuffers.find(fd);
    if (bit == _clientBuffers.end())
    {
        _clientBuffers[fd] = ClientBuffer();
        bit = _clientBuffers.find(fd);
        if (bit == _clientBuffers.end())
        {
            return;
        }
    }

    bit->second.appendChunk(std::string(data, len));

    while (true)
    {
        std::string rawMessage;
        std::string protocolError;
        if (!bit->second.extractNextMessage(rawMessage, protocolError))
        {
            if (protocolError.size() > 0)
            {
                logParseError(fd, protocolError);
                bit->second.clear();
            }
            break;
        }

        Message msg;
        if (!_parser.parse(rawMessage, msg))
        {
            logParseError(fd, "invalid IRC message format (command must be uppercase A-Z or 3-digit numeric)");
            continue;
        }

        if (isStdinClient(fd))
            getOrCreateClient(fd, "stdin");

        std::map<int, Client*>::iterator cit = _clients.find(fd);
        if (cit == _clients.end() || cit->second == NULL)
        {
            logParseError(fd, "client context not found");
            continue;
        }

        if (!dispatchParsedMessage(*cit->second, msg))
        {
            logCommandError(fd, "Bad use from the user");
            continue;
        }
        logParsedOk(fd, msg);
    }
}

bool Dispatcher::dispatchParsedMessage(Client& client, const Message& msg)
{
    if (_validCommands.find(msg.getCommand()) == _validCommands.end())
    {
        std::map<std::string, std::string> markers;
        markers["command"] = msg.getCommand();
        MessageDispatcher::dispatchNumRpl(*this, client, "", NumRpl::ERR_UNKNOWNCOMMAND, markers);
        return false;
    }

    if (msg.getCommand() == "PASS")
    {
        CommandHandler::handlePass(*this, client, _server.getPassword(), msg);
        return true;
    }
    
    if (client.isPassOk())
    {
        if (msg.getCommand() == "NICK")
        {
            CommandHandler::handleNick(*this, *this, _ircServer, client, msg);
            return true;
        }

        if (msg.getCommand() == "USER")
        {
            CommandHandler::handleUser(*this, *this, client, msg);
            return true;
        }

        if (client.isRegistered())
        {
            if (msg.getCommand() == "JOIN")
            {
                if (hasCsvList(msg.getParamByInd(0)))
                {
                    sendMessage(client.getSocket(), "JOIN multiple channels are not supported yet (use one channel per command)\n");
                    return true;
                }

                if (hasCsvList(msg.getParamByInd(1)))
                {
                    sendMessage(client.getSocket(), "JOIN multiple keys are not supported yet (use one key)\n");
                    return true;
                }

                CommandHandler::handleJoin(*this, *this, _ircServer, client, msg);
                return true;
            }

            if (msg.getCommand() == "PART")
            {
                if (hasCsvList(msg.getParamByInd(0)))
                {
                    sendMessage(client.getSocket(), "PART multiple channels are not supported yet (use one channel per command)\n");
                    return true;
                }

                CommandHandler::handlePart(*this, _ircServer, client, msg);
                return true;
            }

            if (msg.getCommand() == "KICK")
            {
                CommandHandler::handleKick(*this, *this, _ircServer, client, msg);
                return true;
            }

            if (msg.getCommand() == "INVITE")
            {
                CommandHandler::handleInvite(*this, *this, _ircServer, client, msg);
                return true;
            }

            if (msg.getCommand() == "TOPIC")
            {
                CommandHandler::handleTopic(*this, _ircServer, client, msg);
                return true;
            }

            if (msg.getCommand() == "MODE")
            {
                CommandHandler::handleMode(*this, *this, _ircServer, client, msg);
                return true;
            }

            if (msg.getCommand() == "PRIVMSG")
            {
                if (hasCsvList(msg.getParamByInd(0)))
                {
                    sendMessage(client.getSocket(), "PART multiple channels are not supported yet (use one channel per command)\n");
                    return true;
                }

                CommandHandler::handlePrivmsg(*this, *this, _ircServer, client, msg);
                return true;
            }

            if (msg.getCommand() == "NOTICE")
            {
                if (hasCsvList(msg.getParamByInd(0)))
                {
                    sendMessage(client.getSocket(), "PART multiple channels are not supported yet (use one channel per command)\n");
                    return true;
                }

                CommandHandler::handlePrivmsg(*this, *this, _ircServer, client, msg);
                return true;
            }
        }

        MessageDispatcher::dispatchNumRpl(*this, client, "", NumRpl::ERR_NOTREGISTERED);
        return true;
    }

    MessageDispatcher::dispatchNumRpl(*this, client, "", NumRpl::ERR_PASSWDMISMATCH);
    return true;
}
