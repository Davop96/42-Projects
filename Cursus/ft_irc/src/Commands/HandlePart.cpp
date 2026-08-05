#include "CommandHandler.hpp"

namespace CommandHandler
{
    void handlePart(const IResponseSender& sender, IChannelService& channelManager,
                    Client& client, const Message& msg)
    {
        const std::string& channelName = msg.getParamByInd(0);
        if (channelName.empty())
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "PART";
            MessageDispatcher::dispatchNumRpl(sender, client, "PART", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }
        if (!Validation::isValidChannelName(channelName))
        {
            std::map<std::string, std::string> markers;
            markers["channel name"] = channelName;
            MessageDispatcher::dispatchNumRpl(sender, client, channelName, NumRpl::ERR_NOSUCHCHANNEL, markers);
            return ;
        }
        const std::string& userMsg = msg.getParamByInd(1);

        if (!channelManager.channelExists(channelName))
        {
            std::map<std::string, std::string> markers;
            markers["channel name"] = channelName;
            MessageDispatcher::dispatchNumRpl(sender, client, channelName, NumRpl::ERR_NOSUCHCHANNEL, markers);
            return ;
        }
        if (!channelManager.hasMember(channelName, client.getNickname()))
        {
            std::map<std::string, std::string> markers;
            markers["channel"] = channelName;
            MessageDispatcher::dispatchNumRpl(sender, client, channelName, NumRpl::ERR_NOTONCHANNEL, markers);
            return ;
        }

        channelManager.removeMember(channelName, client.getNickname());
        client.removeChannel(channelName);

        std::vector<std::string> params;
        params.push_back(channelName);

        Message partMsg("", "PART", params, userMsg);
        MessageDispatcher::dispatchPartMessage(sender, client, partMsg,
                                                    channelManager.getClientsMap(channelName));
    }
}
