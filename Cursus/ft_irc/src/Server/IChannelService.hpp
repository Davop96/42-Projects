#ifndef ICHANNELSERVICE
#define ICHANNELSERVICE

#include "Channel.hpp"
#include "Client.hpp"
#include <string>

class IChannelService
{
    public:
        virtual ~IChannelService() {}

        virtual std::map<std::string, Client*> getClientsMap(const std::string& channelName) = 0;

        virtual bool channelExists(const std::string& channelName) const = 0;
        virtual bool hasMember(const std::string& channelName, const std::string& user) = 0;
        virtual void addMember(const std::string& channelName, Client& client) = 0;
        virtual void removeMember(const std::string& channelName, const std::string& user) = 0;
        
        virtual bool isInvitedOnly(const std::string& channelName) = 0;
        virtual void setInvitedOnly(const std::string& channelName, bool invitedOnly) = 0;
        virtual bool isUserInvited(const std::string& channelName, const std::string& user) = 0;
        virtual void addInvited(const std::string& channelName, const std::string& invited) = 0;
        virtual void removeInvited(const std::string& channelName, const std::string& user) = 0;

        virtual void addOperator(const std::string& channelName, const std::string& user) = 0;
        virtual bool isUserOperator(const std::string& channelName, const std::string& user) = 0;
        virtual void removeOperator(const std::string& channelName, const std::string& user) = 0;

        virtual bool hasKey(const std::string& channelName) = 0;
        virtual const std::string& getKey(const std::string& channelName) = 0;
        virtual bool doesKeyMatch(const std::string& channelName, const std::string& key) = 0;
        virtual void setKey(const std::string& channelName, const std::string key) = 0;

        virtual bool hasTopicRestrictions(const std::string& channelName) = 0;
        virtual void setTopicRestrictions(const std::string& channelName, bool topicRestrictions) = 0;
        virtual const std::string& getTopic(const std::string& channelName) = 0;
        virtual const std::string& getTopicSetter(const std::string& channelName) = 0;
        virtual void setTopic(const std::string& channelName, const std::string& topic) = 0;
        virtual void setTopicSetter(const std::string& channelName, const std::string& topicSetter) = 0;

        virtual bool hasLimit(const std::string& channelName) = 0;
        virtual int getLimit(const std::string& channelName) = 0;
        virtual void setLimit(const std::string& channelName, const size_t limit) = 0;
        virtual bool isLimitExceeded(const std::string& channelName) = 0;

        virtual void joinChannel(Client& client, const std::string& channelName,
                                    const std::string& key) = 0;

        virtual std::string getFormattedChannelMembers(const std::string& channelName) = 0;
};

#endif
