#include "CommandHandler.hpp"

namespace CommandHandler
{
    void handleNotice(const IResponseSender& sender, const IServerData& data,
                        IChannelService& channelManager, const Client& client, const Message& msg)
    {
        const std::string& target = msg.getParamByInd(0);
        if (target.empty()) return ;
        if (msg.paramCount() == 1 && msg.hasTrailing()) return ;
        if (msg.paramCount() == 1) return ;

        if (target[0] == '#')
        {
            if (!Validation::isValidChannelName(target)) return ;
            if (!channelManager.channelExists(target)) return ;

            std::map<std::string, Client*> map = channelManager.getClientsMap(target);
            map.erase(client.getNickname());
            MessageDispatcher::dispatchMulticastMessage(sender, client, msg, map);
        }
        else
        {
            if (!data.isNickInUse(target)) return ;

            MessageDispatcher::dispatchUnicastMessage
            (sender, client, msg, data.getClientSocketByNick(target));
        }
    }
}
