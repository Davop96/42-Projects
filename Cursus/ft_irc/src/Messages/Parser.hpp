#ifndef PARSER_HPP
#define PARSER_HPP

#include "Message.hpp"
#include <string>

class Parser 
{
	public:
		// Returns true if parsed successfully, false if invalid format
		bool parse(const std::string& raw, Message& outMsg) const;
};

#endif
