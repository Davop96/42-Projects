#include "Channel.hpp"
#include "Client.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

  // **************************************************** //
 //               Constructor & getters                  //
// **************************************************** //

    Channel::Channel(const std::string& name)
	: _name(name), _members(), _invitedUsers(), _operators(), _invitedOnly(false),
	_topicRestrictions(false), _topic(), _key(), _limit(0) {}

	const std::string& Channel::getName() const { return _name; }
	const std::map<std::string, Client*> Channel::getClientsMap() const { return _members; }


  // **************************************************** //
 //                 Members funtions                     //
// **************************************************** //

    const Client& Channel::getMember(const std::string& nick) const
	{
		std::map<std::string, Client*>::const_iterator it = _members.find(nick);

		if (it == _members.end()) throw std::out_of_range("User not found");

		return *(it->second);
	}

	bool Channel::hasMember(const std::string& nick) const
	{ return _members.find(nick) != _members.end(); }

	void Channel::addMember(Client& client)
	{ _members.insert(std::make_pair(client.getNickname(), &client)); }

	void Channel::removeMember(const std::string& nick)
	{
		_operators.erase(nick);
		_members.erase(nick);
	}

	size_t Channel::memberCount() { return _members.size(); }


  // **************************************************** //
 //                 Invited functions                    //
// **************************************************** //

	bool Channel::isInvitedOnly() const { return _invitedOnly; }
	void Channel::setInvitedOnly(bool invitedOnly) { _invitedOnly = invitedOnly; }
	void Channel::addInvited(const std::string& nick) { _invitedUsers.insert(nick); }
	void Channel::removeInvited(const std::string& nick) { _invitedUsers.erase(nick); }

	bool Channel::isUserInvited(const std::string& nick) const
	{ return _invitedUsers.find(nick) != _invitedUsers.end(); }

	size_t Channel::invitedCount() const { return _invitedUsers.size(); }


  // **************************************************** //
 //                 Operators functions                  //
// **************************************************** //

	void Channel::addOperator(const std::string& nick) { _operators.insert(nick); }

	bool Channel::isUserOperator(const std::string& nick) const
	{ return _operators.find(nick) != _operators.end(); }

	void Channel::removeOperator(const std::string& nick) { _operators.erase(nick); }

	size_t Channel::OperatorCount() const { return _operators.size(); }


  // **************************************************** //
 //                  Topic functions                     //
// **************************************************** //

	bool Channel::hasTopicRestrictions() const { return _topicRestrictions; }

	void Channel::setTopicRestrictions(bool topicRestrictions)
	{ _topicRestrictions = topicRestrictions; }

	const std::string& Channel::getTopic() const { return _topic; }
	const std::string& Channel::getTopicSetter() const { return _topicSetter; }
	void Channel::setTopic(const std::string& topic) { _topic = topic; }
	void Channel::setTopicSetter(const std::string& topicSetter) { _topicSetter = topicSetter; }


  // **************************************************** //
 //                  Key functions                       //
// **************************************************** //

    bool Channel::hasKey() const { return !_key.empty(); }
    const std::string& Channel::getKey() const { return _key; }
    void Channel::setKey(const std::string key) { _key = key; }


  // **************************************************** //
 //                  Limit functions                     //
// **************************************************** //

	bool Channel::hasLimit() const { return _limit > 0; }
	size_t Channel::getLimit() const { return _limit; }
	void Channel::setLimit(const size_t limit) { _limit = limit; }

	std::string Channel::getFormattedMembers() const
	{
		std::string result;
		for (std::map<std::string, Client*>::const_iterator it = _members.begin();
			 it != _members.end(); ++it)
		{
			if (!result.empty())
				result += " ";
			
			if (_operators.count(it->first) > 0)
				result += "@";
			
			result += it->second->getNickname();
		}
		return result;
	}
