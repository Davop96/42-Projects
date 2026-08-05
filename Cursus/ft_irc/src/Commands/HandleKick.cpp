#include "CommandHandler.hpp"

namespace CommandHandler
{
    void handleKick(const IResponseSender& sender, IServerData& data,
                    IChannelService& channelManager, const Client& kicker,
                    const Message& msg)
    {
        const std::string& channelName = msg.getParamByInd(0);
        const std::string& target = msg.getParamByInd(1);
        if (channelName.empty() || target.empty())
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "KICK";
            MessageDispatcher::dispatchNumRpl(sender, kicker, "KICK", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }
        if (!Validation::isValidChannelName(channelName))
        {
            std::map<std::string, std::string> markers;
            markers["channel name"] = channelName;
            MessageDispatcher::dispatchNumRpl(sender, kicker, channelName, NumRpl::ERR_NOSUCHCHANNEL, markers);
            return ;
        }

        if (!data.isNickInUse(target))
        {
            std::map<std::string, std::string> markers;
            markers["nickname"] = target;
            MessageDispatcher::dispatchNumRpl(sender, kicker, target, NumRpl::ERR_NOSUCHNICK, markers);
            return ;
        }
        if (!channelManager.channelExists(channelName))
        {
            std::map<std::string, std::string> markers;
            markers["channel name"] = channelName;
            MessageDispatcher::dispatchNumRpl(sender, kicker, channelName, NumRpl::ERR_NOSUCHCHANNEL, markers);
            return ;
        }

		if (!channelManager.hasMember(channelName, kicker.getNickname()))
		{
            std::map<std::string, std::string> markers;
            markers["channel"] = channelName;
			MessageDispatcher::dispatchNumRpl(sender, kicker, channelName, NumRpl::ERR_NOTONCHANNEL, markers);
			return ;
		}
        if (!channelManager.hasMember(channelName, target))
        {
            std::map<std::string, std::string> markers;
            markers["nick"] = target;
            markers["channel"] = channelName;
            MessageDispatcher::dispatchNumRpl(sender, kicker, target + " " + channelName, NumRpl::ERR_USERNOTINCHANNEL, markers);
            return ;
        }
        if (!channelManager.isUserOperator(channelName, kicker.getNickname()))
        {
            std::map<std::string, std::string> markers;
            markers["channel"] = channelName;
            MessageDispatcher::dispatchNumRpl(sender, kicker, channelName, NumRpl::ERR_CHANOPRIVSNEEDED, markers);
            return ;
        }

        Client* targetClient = data.getClient(target);
        if (targetClient)
            targetClient->removeChannel(channelName);
        channelManager.removeMember(channelName, target);
        MessageDispatcher::dispatchKickMessage(sender, kicker, msg,
                              channelManager.getClientsMap(channelName));
    }
}
