#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "Client.hpp"
#include <string>
#include <set>
#include <exception>
#include <map>

class Channel
{
    private:
        std::string _name;

        std::map<std::string, Client*> _members;
        std::set<std::string> _invitedUsers;
        std::set<std::string> _operators;

        bool _invitedOnly;
        bool _topicRestrictions;
        std::string _topic;
        std::string _topicSetter;
        std::string _key;
        size_t _limit;

    public:
        Channel(const std::string& name);

        const std::string& getName() const;
        const std::map<std::string, Client*> getClientsMap() const;
        
        const Client& getMember(const std::string& nick) const;
        bool hasMember(const std::string& nick) const;
        void addMember(Client& member);
        void removeMember(const std::string& nick);
        size_t memberCount();
        
        bool isInvitedOnly() const;
        void setInvitedOnly(bool invitedOnly);
        void addInvited(const std::string& nick);
        void removeInvited(const std::string& nick);
        bool isUserInvited(const std::string& nick) const;
        size_t invitedCount() const;

        void addOperator(const std::string& nick);
        bool isUserOperator(const std::string& nick) const;
        void removeOperator(const std::string& nick);
        size_t OperatorCount() const;  
        
        bool hasTopicRestrictions() const;
        void setTopicRestrictions(bool topicRestrictions);
        const std::string& getTopic() const;
        const std::string& getTopicSetter() const;
        void setTopic(const std::string& topic);
        void setTopicSetter(const std::string& topicSetter);
        
        bool hasKey() const;
        const std::string& getKey() const;
        void setKey(const std::string key);

        bool hasLimit() const;
        size_t getLimit() const;
        void setLimit(const size_t limit);

        std::string getFormattedMembers() const;
};

#endif
