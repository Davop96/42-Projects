#include "Message.hpp"
#include <iostream>

  // **************************************************** //
 //                    Constructors                      //
// **************************************************** //

	Message::Message() : _hasTrailing(false) {}

	Message::Message(std::string prefix, std::string command, std::vector<std::string> params,
				std::string trailing)
	: _prefix(prefix), _command(command), _params(params), _trailing(trailing)
	{ _hasTrailing = !_trailing.empty(); }


  // **************************************************** //
 //                     Getters                          //
// **************************************************** //

	const std::string& Message::getPrefix() const { return _prefix; }
	const std::string& Message::getCommand() const { return _command; }

	std::string Message::getParamByInd(size_t ind) const 
	{
		if (ind == _params.size() && _hasTrailing) return _trailing;
		if (ind >= _params.size()) return "";
		return _params[ind];
	}

	size_t Message::paramCount() const { return _params.size(); }
	const std::string& Message::getTrailing() const { return _trailing; }
	bool Message::hasTrailing() const { return _hasTrailing; }


  // **************************************************** //
 //                     Setters                          //
// **************************************************** //

	void Message::setPrefix(const std::string& prefix) { _prefix = prefix; }
	void Message::setCommand(const std::string& command) { _command = command; }
	void Message::addParam(const std::string& param) { _params.push_back(param); }
	void Message::setTrailing(const std::string& trailing) { _trailing = trailing; }
	void Message::setHasTrailing(bool hasTrailing) { _hasTrailing = hasTrailing; }


  // **************************************************** //
 //                      Utils                           //
// **************************************************** //

	// Prints all components of the parsed message for debugging purposes
	void Message::print() const 
	{
		std::cout << "Prefix:    [" << _prefix << "]\n";
		std::cout << "Command:   [" << _command << "]\n";
		std::cout << "Params:    ";
		for (size_t i = 0; i < _params.size(); ++i) 
		{
			std::cout << "[" << _params[i] << "] ";
		}
		std::cout << "\n";
		if (_hasTrailing)
		{
			std::cout << "Trailing:  [" << _trailing << "]\n";
		}
		std::cout << std::endl;
	}

	// Reconstructs the original IRC message format from its parsed components
	// Useful for forwarding messages or logging
	std::string Message::getFullCommand() const 
	{
		std::string res;
		if (_prefix.size() > 0)
		{
			res += ":" + _prefix + " ";
		}
		res += _command;
		for (size_t i = 0; i < _params.size(); ++i) 
		{
			res += " " + _params[i];
		}
		if (_hasTrailing)
		{
			res += " :" + _trailing;
		}
		return res;
	}
