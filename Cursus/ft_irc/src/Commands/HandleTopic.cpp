#include "CommandHandler.hpp"
#include <ctime>

namespace CommandHandler
{
    void handleTopic(const IResponseSender& sender, IChannelService& channelManager,
                    const Client& client, const Message& msg)
    {
        bool twoArgs = msg.paramCount() + msg.hasTrailing() >= 2;
        
        const std::string& channel = msg.getParamByInd(0);
        if (channel.empty())
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "TOPIC";
            MessageDispatcher::dispatchNumRpl(sender, client, "TOPIC", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }
        if (!Validation::isValidChannelName(channel))
        {
            std::map<std::string, std::string> markers;
            markers["channel"] = channel;
            MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::ERR_BADCHANMASK, markers);
            return ;
        }
        if (!channelManager.channelExists(channel))
        {
            std::map<std::string, std::string> markers;
            markers["channel name"] = channel;
            MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::ERR_NOSUCHCHANNEL, markers);
            return ;
        }

        if (!channelManager.hasMember(channel, client.getNickname()))
        {
            std::map<std::string, std::string> markers;
            markers["channel"] = channel;
            MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::ERR_NOTONCHANNEL, markers);
            return ;
        }

        const std::string& topic = msg.getParamByInd(1);
        if (topic.empty() && !twoArgs)
        {
            const std::string& channelTopic = channelManager.getTopic(channel);
            
            std::map<std::string, std::string> markers;
            markers["channel"] = channel;
            
            if (channelTopic.empty())
            {
                MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::RPL_NOTOPIC, markers);
            }
            else
            {
                markers["topic"] = channelTopic;
                MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::RPL_TOPIC, markers);
                
                markers["nick"] = channelManager.getTopicSetter(channel);
                const std::time_t now = std::time(NULL);
                const std::tm* localTime = std::localtime(&now);
                char buffer[20];
                if (localTime != NULL && std::strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M:%S", localTime) != 0)
                    markers["setat"] = buffer;
                else
                    markers["setat"] = "unknown";
                MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::RPL_TOPICWHOTIME, markers);
            }
            return ;
        }

        if (channelManager.hasTopicRestrictions(channel) &&
            !channelManager.isUserOperator(channel, client.getNickname()))
        {
            std::map<std::string, std::string> markers;
            markers["channel"] = channel;
            MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::ERR_CHANOPRIVSNEEDED, markers);
            return ;
        }
        
        channelManager.setTopic(channel, topic);
        channelManager.setTopicSetter(channel, client.getNickname());
        
        MessageDispatcher::dispatchTopicMessage
        (sender, client, msg, channelManager.getClientsMap(channel));
    }
}
