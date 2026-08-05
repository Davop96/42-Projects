#include "NumRpl.hpp"

namespace NumRpl
{
	NumRpl_s::NumRpl_s()
	{
	}

	NumRpl_s::NumRpl_s(const std::string& codeValue, const std::string& trailingValue)
		: code(codeValue), trailing(trailingValue)
	{
	}

	static NumRplMap_t buildNumRplMap()
	{
		NumRplMap_t map;

		map[RPL_WELCOME] = NumRpl_s("001", "Welcome to the Internet Relay Network <nick>!<user>@<host>");
		map[RPL_YOURHOST] = NumRpl_s("002", "Your host is <servername>, running version <ver>");
		map[RPL_CREATED] = NumRpl_s("003", "This server was created <date>");
		map[RPL_MYINFO] = NumRpl_s("004", "<version> <available channel modes>");

		map[RPL_CHANNELMODEIS] = NumRpl_s("324", "<mode> <mode params>");
		map[RPL_NOTOPIC] = NumRpl_s("331", "No topic is set");
		map[RPL_TOPIC] = NumRpl_s("332", "<topic>");
		map[RPL_TOPICWHOTIME] = NumRpl_s("333", "<nick> <setat>");
		map[RPL_INVITING] = NumRpl_s("341", "<nick>");
		map[RPL_NAMREPLY] = NumRpl_s("353", "<nicks>");
		map[RPL_ENDOFNAMES] = NumRpl_s("366", "End of NAMES list");
		
		map[ERR_NOSUCHNICK] = NumRpl_s("401", "No such nick/channel");
		map[ERR_NOSUCHCHANNEL] = NumRpl_s("403", "No such channel");
		map[ERR_NORECIPIENT] = NumRpl_s("411", "No recipient given (<command>)");
		map[ERR_NOTEXTTOSEND] = NumRpl_s("412", "No text to send");
		map[ERR_UNKNOWNCOMMAND] = NumRpl_s("421", "Unknown command");
		map[ERR_NONICKNAMEGIVEN] = NumRpl_s("431", "No nickname given");
		map[ERR_ERRONEUSNICKNAME] = NumRpl_s("432", "Erroneous nickname");
		map[ERR_NICKNAMEINUSE] = NumRpl_s("433", "Nickname is already in use");
		map[ERR_USERNOTINCHANNEL] = NumRpl_s("441", "They aren't on that channel");
		map[ERR_NOTONCHANNEL] = NumRpl_s("442", "You're not on that channel");
		map[ERR_USERONCHANNEL] = NumRpl_s("443", "is already on channel");
		map[ERR_NOTREGISTERED] = NumRpl_s("451", "You have not registered");
		map[ERR_NEEDMOREPARAMS] = NumRpl_s("461", "Not enough parameters");
		map[ERR_ALREADYREGISTERED] = NumRpl_s("462", "Unauthorized command (already registered)");
		map[ERR_PASSWDMISMATCH] = NumRpl_s("464", "Password incorrect");
		map[ERR_KEYSET] = NumRpl_s("467", "Channel key already set");
		map[ERR_CHANNELISFULL] = NumRpl_s("471", "Cannot join channel (+l)");
		map[ERR_UNKNOWNMODE] = NumRpl_s("472", "is unknown mode char to me for <channel>");
		map[ERR_INVITEONLYCHAN] = NumRpl_s("473", "Cannot join channel (+i)");
		map[ERR_BADCHANNELKEY] = NumRpl_s("475", "Cannot join channel (+k)");
		map[ERR_BADCHANMASK] = NumRpl_s("476", "Bad Channel Mask");
		map[ERR_CHANOPRIVSNEEDED] = NumRpl_s("482", "You're not channel operator");
		map[ERR_INVALIDMODEPARAM] = NumRpl_s("696", "Invalid mode parameter");
		
		return map;
	}

	const NumRplMap_t& getMap()
	{
		static const NumRplMap_t map = buildNumRplMap();
		return map;
	}

	const NumRpl_s& getNumRpl(NumRplType type)
	{
		const NumRplMap_t& map = getMap();
		return map.find(type)->second;
	}
}
