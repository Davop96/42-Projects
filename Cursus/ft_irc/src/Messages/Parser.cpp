#include "Parser.hpp"
#include "Tokens.hpp"

static const size_t IRC_MAX_PAYLOAD_LEN = 510;
static const size_t IRC_MAX_PARAMS = 15;

bool Parser::parse(const std::string& raw, Message& msg) const 
{
	// Reset output to avoid carrying data from previous parses.
	msg = Message();

	if (raw.size() == 0 || raw.size() > IRC_MAX_PAYLOAD_LEN)
	{
		return false;
	}

	std::string line = Tokens::trim(Tokens::normalizeLine(raw));
	if (line.size() == 0)
	{
		return false;
	}

	// Reject embedded CR/LF after normalization.
	if (line.find('\r') != std::string::npos || line.find('\n') != std::string::npos)
	{
		return false;
	}

	size_t pos = 0;

	// 1. Optional prefix (:...)
	if (line[0] == ':')
	{
		pos = line.find(' ', 1);
		if (pos == std::string::npos)
		{
			return false;
		}
		std::string prefix = line.substr(1, pos - 1);
		if (prefix.size() == 0)
		{
			return false;
		}
		msg.setPrefix(prefix);
		pos = Tokens::skipSpaces(line, pos + 1);
		if (pos >= line.size())
		{
			return false;
		}
	}

	// 2. Command (required)
	size_t nextSpace = Tokens::findFirstSpace(line, pos);
	if (nextSpace == std::string::npos) 
	{
		std::string command = line.substr(pos);
		if (command.size() == 0)
		{
			return false;
		}
		if (!Tokens::isValidCommandToken(command))
		{
			return false;
		}
		msg.setCommand(command);
		return true;
	}
	std::string command = line.substr(pos, nextSpace - pos);
	if (command.size() == 0)
	{
		return false;
	}
	if (!Tokens::isValidCommandToken(command))
	{
		return false;
	}
	msg.setCommand(command);
	pos = nextSpace + 1;
	size_t paramsCount = 0;

	// 3. Intermediate parameters (until finding : or end)
	while (pos < line.size()) 
	{
		pos = Tokens::skipSpaces(line, pos);
		if (pos >= line.size())
		{
			break ;
		}

		if (line[pos] == ':') 
		{
			if (paramsCount >= IRC_MAX_PARAMS)
			{
				return false;
			}
			msg.setTrailing(line.substr(pos + 1));
			msg.setHasTrailing(true);
			break ;
		}

		if (paramsCount >= IRC_MAX_PARAMS)
		{
			return false;
		}

		nextSpace = Tokens::findFirstSpace(line, pos);
		if (nextSpace == std::string::npos) 
		{
			std::string param = line.substr(pos);
			if (param.size() > 0)
			{
				msg.addParam(param);
				++paramsCount;
			}
			break ;
		}
		std::string param = line.substr(pos, nextSpace - pos);
		if (param.size() > 0)
		{
			msg.addParam(param);
			++paramsCount;
		}
		pos = nextSpace + 1;
	}
	return true;
}
