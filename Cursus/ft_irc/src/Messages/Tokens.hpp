#ifndef TOKENS_HPP
#define TOKENS_HPP

#include <string>

namespace Tokens
{
	bool		isValidCommandToken(const std::string& command);
	std::string	normalizeLine(const std::string& raw);
	size_t		skipSpaces(const std::string& str, size_t start);
	std::string	trim(const std::string& str);
	size_t		findFirstSpace(const std::string& str, size_t start);
}

#endif
