#include "CommandHandler.hpp"
#include "IChannelService.hpp"
#include <ctime>
#include <string>

namespace CommandHandler
{
    void handleJoin(const IResponseSender& sender, IServerData& data, IChannelService& channelManager,
                    Client& client, const Message& msg)
    {
        const std::string& channelName = msg.getParamByInd(0);
        if (channelName.empty())
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "JOIN";
            MessageDispatcher::dispatchNumRpl(sender, client, "JOIN", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }
        if (!Validation::isValidChannelName(channelName))
        {
            std::map<std::string, std::string> markers;
            markers["channel"] = channelName;
            MessageDispatcher::dispatchNumRpl(sender, client, channelName, NumRpl::ERR_BADCHANMASK, markers);
            return ;
        }

        const std::string& key = msg.getParamByInd(1);

        if (channelManager.channelExists(channelName))
        {
            if (channelManager.hasMember(channelName, client.getNickname())) return ;
            
            if (channelManager.hasLimit(channelName) && channelManager.isLimitExceeded(channelName))
            {
                std::map<std::string, std::string> markers;
                markers["channel"] = channelName;
                MessageDispatcher::dispatchNumRpl(sender, client, channelName, NumRpl::ERR_CHANNELISFULL, markers);
                return ;
            }
        
            if (channelManager.isInvitedOnly(channelName) &&
                !channelManager.isUserInvited(channelName, client.getNickname()))
            {
                std::map<std::string, std::string> markers;
                markers["channel"] = channelName;
                MessageDispatcher::dispatchNumRpl(sender, client, channelName, NumRpl::ERR_INVITEONLYCHAN, markers);
                return ;
            }

            if (channelManager.hasKey(channelName) &&
                !channelManager.doesKeyMatch(channelName, key))
            {
                std::map<std::string, std::string> markers;
                markers["channel"] = channelName;
                MessageDispatcher::dispatchNumRpl(sender, client, channelName, NumRpl::ERR_BADCHANNELKEY, markers);
                return ;
            }
        }

        data.removePendingInvitation(channelName, client.getNickname());
        channelManager.joinChannel(client, channelName, key);

        const std::string& topic = channelManager.getTopic(channelName);
        
        std::map<std::string, std::string> markers;
        markers["channel"] = channelName;

        MessageDispatcher::dispatchJoinMessage(sender, client, msg,
                               channelManager.getClientsMap(channelName));
        
        if (!topic.empty())
        {
            markers["topic"] = topic;
            MessageDispatcher::dispatchNumRpl(sender, client, channelName, NumRpl::RPL_TOPIC, markers);
            
            markers["nick"] = channelManager.getTopicSetter(channelName);
            const std::time_t now = std::time(NULL);
            const std::tm* localTime = std::localtime(&now);
            char buffer[20];
            if (localTime != NULL && std::strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M:%S", localTime) != 0)
                markers["setat"] = buffer;
            else
                markers["setat"] = "unknown";
            MessageDispatcher::dispatchNumRpl(sender, client, channelName, NumRpl::RPL_TOPICWHOTIME, markers);
        }
        else
        {
            MessageDispatcher::dispatchNumRpl(sender, client, channelName, NumRpl::RPL_NOTOPIC, markers);
        }
        
        std::string formattedMembers = channelManager.getFormattedChannelMembers(channelName);
        markers["nicks"] = formattedMembers;

        std::string arg = "= ";
        arg += channelName;
        MessageDispatcher::dispatchNumRpl(sender, client, arg, NumRpl::RPL_NAMREPLY, markers);
        MessageDispatcher::dispatchNumRpl(sender, client, channelName, NumRpl::RPL_ENDOFNAMES, markers);
    }
}
