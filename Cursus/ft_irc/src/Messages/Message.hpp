#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <vector>

class Message 
{
	private:
		std::string					_prefix;			// optional: :nick!user@host
		std::string					_command;		// e.g.: PRIVMSG, JOIN, NICK...
		std::vector<std::string>	_params;			// intermediate parameters
		std::string					_trailing;		// the last parameter with : at the beginning
		bool						_hasTrailing;	// whether there was : at the end

	public:
		Message();
		Message(std::string prefix, std::string command, std::vector<std::string> params,
				std::string trailing);

		const std::string&		getPrefix() const;
		const std::string&		getCommand() const;
		std::string				getParamByInd(size_t ind) const;
		size_t					paramCount() const;
		const std::string&		getTrailing() const;
		bool					hasTrailing() const;

		void					setPrefix(const std::string& prefix);
		void					setCommand(const std::string& command);
		void					addParam(const std::string& param);
		void					setTrailing(const std::string& trailing);
		void					setHasTrailing(bool hasTrailing);

		// Utils
		void					print() const; // For debugging: prints the parsed message
		std::string				getFullCommand() const;	// rebuilds the original string (useful for forwarding)
};

#endif
