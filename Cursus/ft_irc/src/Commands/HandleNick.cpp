#include "CommandHandler.hpp"
#include "Server.hpp"
#include "MessageDispatcher.hpp"

namespace CommandHandler
{
    namespace
    {
        void updateNickIndex(IServerData& data, IChannelService& channelManager, Client& client,
                                const std::string& newNick)
        {
            data.removeClientByNick(client.getNickname());
            data.addClientByNick(newNick, &client);

            for (Client::channel_iterator it = client.getChannelsBegin(); it != client.getChannelsEnd();
                    ++it)
            {
                channelManager.removeMember(*it, client.getNickname());
                channelManager.addMember(*it, client);
            }
        }
    }

    void handleNick(const IResponseSender& sender, IServerData& data, IChannelService& channelManager,
                    Client& client, const Message& msg)
    {
        const std::string& nick = msg.getParamByInd(0);
        if (nick.empty())
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "NICK";
            MessageDispatcher::dispatchNumRpl(sender, client, "NICK", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }
        if (!Validation::isValidNickname(nick))
        {
            std::map<std::string, std::string> markers;
            markers["nick"] = nick;
            MessageDispatcher::dispatchNumRpl(sender, client, nick, NumRpl::ERR_ERRONEUSNICKNAME, markers);
            return ;
        }

        if (data.isNickInUse(nick))
        {
            std::map<std::string, std::string> markers;
            markers["nick"] = nick;
            MessageDispatcher::dispatchNumRpl(sender, client, nick, NumRpl::ERR_NICKNAMEINUSE, markers);
            return ;
        }

        updateNickIndex(data, channelManager, client, nick);
        client.setNickname(nick);
        if (client.isRegistered())
        {
            for (Client::channel_iterator it = client.getChannelsBegin(); it != client.getChannelsEnd();
                    ++it)
            {
                MessageDispatcher::dispatchNickMessage
                (sender, client, msg, channelManager.getClientsMap(*it));
            }
        }
        else Validation::tryRegister(client, sender, data);
    }
}
