#ifndef SERVERDATA_HPP
#define SERVERDATA_HPP

#include "Client.hpp"
#include "Channel.hpp"
#include "IChannelService.hpp"
#include <string>
#include <map>

class ServerData : public IChannelService
{
    private:
        std::string _serverName;

        std::map<std::string, Client*> _clientsByNick;
        std::map<std::string, Channel*> _channels;
        std::map<std::string, std::set<std::string> > _pendingInvitations;

        Channel* getChannel(const std::string& channelName);
        void createChannel(const std::string& channelName, const std::string& key, Client& client);

    public:
        ServerData();

        typedef std::map<std::string, Channel*>::iterator channel_iterator;

        const std::string& getServername() const;
        Client* getClient(const std::string& nick);
        
        channel_iterator getChannelsBegin();
        channel_iterator getChannelsEnd();

        void addClientByNick(const std::string& nick, Client* client);
        void removeClientByNick(const std::string& nick);
        bool isNickInUse(const std::string& nick) const;
        int getClientSocketByNick(const std::string& nick) const;

        void addPendingInvitation(const std::string& channelName, const std::string& invited);
        void removePendingInvitation(const std::string& channelName, const std::string& invited);

        // IChannelService Implementation
        bool channelExists(const std::string& channelName) const;
        std::map<std::string, Client*> getClientsMap(const std::string& channelName);
        bool hasMember(const std::string& channelName, const std::string& user);
        void addMember(const std::string& channelName, Client& client);
        void removeMember(const std::string& channelName, const std::string& user);
        
        bool isInvitedOnly(const std::string& channelName);
        void setInvitedOnly(const std::string& channelName, bool invitedOnly);
        bool isUserInvited(const std::string& channelName, const std::string& user);
        void addInvited(const std::string& channelName, const std::string& invited);
        void removeInvited(const std::string& channelName, const std::string& user);

        void addOperator(const std::string& channelName, const std::string& user);
        bool isUserOperator(const std::string& channelName, const std::string& user);
        void removeOperator(const std::string& channelName, const std::string& user);

        bool hasKey(const std::string& channelName);
        const std::string& getKey(const std::string& channelName);
        bool doesKeyMatch(const std::string& channelName, const std::string& key);
        void setKey(const std::string& channelName, const std::string key);

        bool hasTopicRestrictions(const std::string& channelName);
        void setTopicRestrictions(const std::string& channelName, bool topicRestrictions);
        const std::string& getTopic(const std::string& channelName);
        const std::string& getTopicSetter(const std::string& channelName);
        void setTopic(const std::string& channelName, const std::string& topic);
        void setTopicSetter(const std::string& channelName, const std::string& topicSetter);

        bool hasLimit(const std::string& channelName);
        int getLimit(const std::string& channelName);
        void setLimit(const std::string& channelName, const size_t limit);
        bool isLimitExceeded(const std::string& channelName);

        void joinChannel(Client& client, const std::string& channelName,
                            const std::string& key);

        std::string getFormattedChannelMembers(const std::string& channelName);
};

#endif
