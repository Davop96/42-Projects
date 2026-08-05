#include "CommandHandler.hpp"

namespace CommandHandler
{
    void handleInvite(const IResponseSender& sender, IServerData& data,
                        IChannelService& channelManager, const Client& inviter, const Message& msg)
    {
        const std::string& target = msg.getParamByInd(0);
        const std::string& channel = msg.getParamByInd(1);
        if (target.empty() || channel.empty())
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "INVITE";
            MessageDispatcher::dispatchNumRpl(sender, inviter, "INVITE", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }
        if (!data.isNickInUse(target))
        {
            std::map<std::string, std::string> markers;
            markers["nickname"] = target;
            MessageDispatcher::dispatchNumRpl(sender, inviter, target, NumRpl::ERR_NOSUCHNICK, markers);
            return ;
        }
        if (!Validation::isValidChannelName(channel))
        {
            std::map<std::string, std::string> markers;
            markers["channel name"] = channel;
            MessageDispatcher::dispatchNumRpl(sender, inviter, channel, NumRpl::ERR_NOSUCHCHANNEL, markers);
            return ;
        }

        if (!channelManager.channelExists(channel))
            data.addPendingInvitation(channel, target);
        else
        {
            if (!channelManager.hasMember(channel, inviter.getNickname()))
            {
                std::map<std::string, std::string> markers;
                markers["channel"] = channel;
                MessageDispatcher::dispatchNumRpl(sender, inviter, channel, NumRpl::ERR_NOTONCHANNEL, markers);
                return ;
            }
            if (channelManager.isInvitedOnly(channel))
            {
                if (!channelManager.isUserOperator(channel, inviter.getNickname()))
                {
                    std::map<std::string, std::string> markers;
                    markers["channel"] = channel;
                    MessageDispatcher::dispatchNumRpl(sender, inviter, channel, NumRpl::ERR_CHANOPRIVSNEEDED, markers);
                    return ;
                }
            }

            channelManager.addInvited(channel, target);
        }
        
        std::map<std::string, std::string> markers;
        markers["channel"] = channel;
        markers["nick"] = target;
        MessageDispatcher::dispatchNumRpl(sender, inviter, channel, NumRpl::RPL_INVITING, markers);

        int targetSock = data.getClientSocketByNick(target);
        MessageDispatcher::dispatchInviteMessage(sender, inviter, msg, targetSock);
    }
}
