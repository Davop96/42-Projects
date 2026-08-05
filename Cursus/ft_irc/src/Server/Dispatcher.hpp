#ifndef DISPATCHER_HPP
#define DISPATCHER_HPP

#include "Server.hpp"
#include "ServerData.hpp"
#include "Client.hpp"
#include "ClientBuffer.hpp"
#include "Parser.hpp"
#include "IResponseSender.hpp"
#include "IServerData.hpp"
#include <string>
#include <map>

class Server;

class Dispatcher : public IServerEvents, public IResponseSender, public IServerData
{
    private:
        Server& _server;
        ServerData& _ircServer;
        std::map<int, Client*> _clients;
        std::map<int, ClientBuffer> _clientBuffers;
        Parser _parser;
        std::set<std::string> _validCommands;

        Client* getOrCreateClient(int fd, const std::string &ip);
        bool dispatchParsedMessage(Client& client, const Message& msg);

    public:
        Dispatcher(Server& server, ServerData& data);
        ~Dispatcher();

        virtual void onClientConnected(int fd, const std::string &ip);
        virtual void onClientDisconnected(int fd);
        virtual void onBytesReceived(int fd, const char *data, std::size_t len);

        void sendMessage(int fd, const std::string& msg) const;
        void sendBroadcast(const std::map<std::string, Client*>& clients,
                   const std::string& message) const;

        const std::string& getServername() const;
        Client* getClient(const std::string& nick);
        void addClientByNick(const std::string& nick, Client* client);
        void removeClientByNick(const std::string& nick);
        bool isNickInUse(const std::string& nick) const;
        int getClientSocketByNick(const std::string& nick) const;
        void addPendingInvitation(const std::string& channelName, const std::string& invited);
        void removePendingInvitation(const std::string& channelName, const std::string& invited);
};

#endif
