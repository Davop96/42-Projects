#include "Tokens.hpp"

namespace Tokens
{
	// IRC command must be uppercase alphabetic (e.g. PRIVMSG) or 3-digit numeric (e.g. 001).
	bool isValidCommandToken(const std::string& command)
	{
		if (command.size() == 0)
		{
			return false;
		}

		bool allDigits = true;
		for (size_t i = 0; i < command.size(); ++i)
		{
			const char c = command[i];
			if (c < '0' || c > '9')
			{
				allDigits = false;
				break;
			}
		}
		if (allDigits)
		{
			return command.size() == 3;
		}

		for (size_t i = 0; i < command.size(); ++i)
		{
			const char c = command[i];
			if (!(c >= 'A' && c <= 'Z'))
			{
				return false;
			}
		}
		return true;
	}

	// Removes a single IRC line ending (\r\n or \n or \r)
	std::string normalizeLine(const std::string& raw)
	{
		std::string line = raw;
		if (line.size() > 0 && line[line.size() - 1] == '\n')
		{
			line.erase(line.size() - 1, 1);
			if (line.size() > 0 && line[line.size() - 1] == '\r')
			{
				line.erase(line.size() - 1, 1);
			}
		}
		else if (line.size() > 0 && line[line.size() - 1] == '\r')
		{
			line.erase(line.size() - 1, 1);
		}
		return line;
	}

	// Skips spaces and tabs from a starting position
	size_t skipSpaces(const std::string& str, size_t start)
	{
		while (start < str.size() && (str[start] == ' ' || str[start] == '\t'))
		{
			++start;
		}
		return start;
	}

	// Trim spaces at the beginning/end
	std::string trim(const std::string& str)
	{
		size_t first = str.find_first_not_of(" \t");
		if (first == std::string::npos)
		{
			return "";
		}
		size_t last = str.find_last_not_of(" \t");
		return str.substr(first, last - first + 1);
	}

	size_t findFirstSpace(const std::string& str, size_t start)
	{
		return str.find_first_of(" \t", start);
	}
}
