#include "ServerData.hpp"
#include <stdexcept>

  // **************************************************** //
 //                    Constructor                       //
// **************************************************** //

    ServerData::ServerData() : _serverName("ircserv") {}


  // **************************************************** //
 //             Private Channel functions                //
// **************************************************** //

    Channel* ServerData::getChannel(const std::string& name)
    {
        std::map<std::string, Channel*>::iterator it = _channels.find(name);
        return it != _channels.end() ? it->second : NULL;
    }

    void ServerData::createChannel(const std::string& name, const std::string& key, Client& client)
    {
        Channel* channel = new Channel(name);

        channel->addOperator(client.getNickname());
        if (!key.empty()) { channel->setKey(key); }
        _channels.insert(std::make_pair(name, channel));
    }


  // **************************************************** //
 //                     Iterators                        //
// **************************************************** //

    ServerData::channel_iterator ServerData::getChannelsBegin() { return _channels.begin(); }
    ServerData::channel_iterator ServerData::getChannelsEnd() { return _channels.end(); }


  // **************************************************** //
 //                    Data Utils                        //
// **************************************************** //

    const std::string& ServerData::getServername() const { return _serverName; }

    Client* ServerData::getClient(const std::string& nick)
    {
        std::map<std::string, Channel*>::iterator it = _channels.begin();
        while (it != _channels.end())
        {
            Channel* channel = it->second;
            if (channel != NULL && channel->hasMember(nick))
            {
                const Client& member = channel->getMember(nick);
                return const_cast<Client*>(&member);
            }
            ++it;
        }
        return NULL;
    }

    void ServerData::addClientByNick(const std::string& nick, Client* client)
    { _clientsByNick.insert(std::make_pair(nick, client)); }

    void ServerData::removeClientByNick(const std::string& nick)
    { _clientsByNick.erase(nick); }

    bool ServerData::isNickInUse(const std::string& nick) const
    { return _clientsByNick.find(nick) != _clientsByNick.end(); }

    int ServerData::getClientSocketByNick(const std::string& nick) const
    {
        std::map<std::string, Client*>::const_iterator it = _clientsByNick.find(nick);

		if (it == _clientsByNick.end()) throw std::out_of_range("User not found");

		return it->second->getSocket();
    }

    void ServerData::addPendingInvitation(const std::string& channelName, const std::string& invited)
    { _pendingInvitations[channelName].insert(invited); }

    void ServerData::removePendingInvitation(const std::string& channelName, const std::string& invited)
    {
        std::map<std::string, std::set<std::string> >::iterator it = _pendingInvitations.find(channelName);
        if (it != _pendingInvitations.end())
        {
            it->second.erase(invited);

            if (it->second.empty())
                _pendingInvitations.erase(it);
        }
    }


  // **************************************************** //
 //           IChannelService implementation             //
// **************************************************** //

    // BASICS
    bool ServerData::channelExists(const std::string& channelName) const
    { return _channels.find(channelName) != _channels.end(); }

    std::map<std::string, Client*> ServerData::getClientsMap(const std::string& channelName)
    {
        Channel* channel = getChannel(channelName);

        if (channel != NULL)
            return channel->getClientsMap();

        return std::map<std::string, Client*>();
    }

    bool ServerData::hasMember(const std::string& channelName, const std::string& user)
    { return getChannel(channelName)->hasMember(user); }

    void ServerData::addMember(const std::string& channelName, Client& client)
    { getChannel(channelName)->addMember(client); }

    void ServerData::removeMember(const std::string& channelName, const std::string& user)
    {
        Channel* channel = getChannel(channelName);

        if (channel == NULL)
            return ;

        channel->removeMember(user);

        if (channel->memberCount() == 0)
        {
            delete channel;
            _channels.erase(channelName);
            _pendingInvitations.erase(channelName);
        }
    }
    
    // INVITED
    bool ServerData::isInvitedOnly(const std::string& channelName)
    { return getChannel(channelName)->isInvitedOnly(); }

    void ServerData::setInvitedOnly(const std::string& channelName, bool invitedOnly)
    { getChannel(channelName)->setInvitedOnly(invitedOnly); }

    bool ServerData::isUserInvited(const std::string& channelName, const std::string& user)
    { return getChannel(channelName)->isUserInvited(user); }
    
    void ServerData::addInvited(const std::string& channelName, const std::string& invited)
    { getChannel(channelName)->addInvited(invited); }

    void ServerData::removeInvited(const std::string& channelName, const std::string& user)
    { getChannel(channelName)->removeInvited(user); }

    // OPERATORS
    void ServerData::addOperator(const std::string& channelName, const std::string& user)
    { getChannel(channelName)->addOperator(user); }

    bool ServerData::isUserOperator(const std::string& channelName, const std::string& user)
    { return getChannel(channelName)->isUserOperator(user); }

    void ServerData::removeOperator(const std::string& channelName, const std::string& user)
    { getChannel(channelName)->removeOperator(user); }
    
    // KEY
    bool ServerData::hasKey(const std::string& channelName)
    { return getChannel(channelName)->hasKey(); }
    
    const std::string& ServerData::getKey(const std::string& channelName)
    { return getChannel(channelName)->getKey(); }

    bool ServerData::doesKeyMatch(const std::string& channelName, const std::string& key)
    { return key == getChannel(channelName)->getKey(); }

    void ServerData::setKey(const std::string& channelName, const std::string key)
    { getChannel(channelName)->setKey(key); }

    // TOPIC
    bool ServerData::hasTopicRestrictions(const std::string& channelName)
    { return getChannel(channelName)->hasTopicRestrictions(); }

    void ServerData::setTopicRestrictions(const std::string& channelName, bool topicRestrictions)
    { getChannel(channelName)->setTopicRestrictions(topicRestrictions); }

    const std::string& ServerData::getTopic(const std::string& channelName)
    { return getChannel(channelName)->getTopic(); }

    const std::string& ServerData::getTopicSetter(const std::string& channelName)
    { return getChannel(channelName)->getTopicSetter(); }

    void ServerData::setTopic(const std::string& channelName, const std::string& topic)
    { getChannel(channelName)->setTopic(topic); }

    void ServerData::setTopicSetter(const std::string& channelName, const std::string& topicSetter)
    { getChannel(channelName)->setTopicSetter(topicSetter); }

    // LIMIT
    bool ServerData::hasLimit(const std::string& channelName)
    { return getChannel(channelName)->hasLimit(); }

    int ServerData::getLimit(const std::string& channelName)
    { return getChannel(channelName)->getLimit(); }

    void ServerData::setLimit(const std::string& channelName, const size_t limit)
    { getChannel(channelName)->setLimit(limit); }

    bool ServerData::isLimitExceeded(const std::string& channelName)
    { return getChannel(channelName)->memberCount() >= getChannel(channelName)->getLimit(); }

    // JOIN
    void ServerData::joinChannel(Client& client, const std::string& channelName,
                                    const std::string& key)
    {
        if (!channelExists(channelName)) createChannel(channelName, key, client);
        client.addChannel(channelName);
        getChannel(channelName)->addMember(client);
        getChannel(channelName)->removeInvited(client.getNickname());
    }

    std::string ServerData::getFormattedChannelMembers(const std::string& channelName)
    {
        return getChannel(channelName)->getFormattedMembers();
    }
