#include "CommandHandler.hpp"

namespace CommandHandler
{
    void handlePrivmsg(const IResponseSender& sender, const IServerData& data,
                        IChannelService& channelManager, const Client& client, const Message& msg)
    {
        const std::string& target = msg.getParamByInd(0);
        if (target.empty())
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "PRIVMSG";
            MessageDispatcher::dispatchNumRpl(sender, client, "PRIVMSG", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }
        if (msg.paramCount() == 0 && msg.hasTrailing())
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "PRIVMSG";
            MessageDispatcher::dispatchNumRpl(sender, client, "", NumRpl::ERR_NORECIPIENT, markers);
            return ;
        }
        if (msg.paramCount() == 1 && !msg.hasTrailing())
        {
            MessageDispatcher::dispatchNumRpl(sender, client, "", NumRpl::ERR_NOTEXTTOSEND);
            return ;
        }

        if (target[0] == '#')
        {
            if (!Validation::isValidChannelName(target))
            {
                std::map<std::string, std::string> markers;
                markers["channel"] = target;
                MessageDispatcher::dispatchNumRpl(sender, client, target, NumRpl::ERR_BADCHANMASK, markers);
                return ;
            }
            if (!channelManager.channelExists(target))
            {
                std::map<std::string, std::string> markers;
                markers["channel name"] = target;
                MessageDispatcher::dispatchNumRpl(sender, client, target, NumRpl::ERR_NOSUCHCHANNEL, markers);
                return ;
            }

            std::map<std::string, Client*> map = channelManager.getClientsMap(target);
            map.erase(client.getNickname());
            MessageDispatcher::dispatchMulticastMessage(sender, client, msg, map);
        }
        else
        {
            if (!data.isNickInUse(target))
            {
                std::map<std::string, std::string> markers;
                markers["nickname"] = target;
                MessageDispatcher::dispatchNumRpl(sender, client, target, NumRpl::ERR_NOSUCHNICK, markers);
                return ;
            }

            MessageDispatcher::dispatchUnicastMessage
            (sender, client, msg, data.getClientSocketByNick(target));
        }

    }
}
