#include "Validation.hpp"
#include "MessageDispatcher.hpp"
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <ctime>

namespace
{
    std::string getCurrentDateTime()
    {
        const std::time_t now = std::time(NULL);
        const std::tm* localTime = std::localtime(&now);
        if (localTime == NULL)
            return "unknown";

        char buffer[20];
        if (std::strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M:%S", localTime) == 0)
            return "unknown";
        return buffer;
    }
}

namespace Validation
{
    bool isValidNickname(const std::string& name)
    {
        if (name.size() >= MAX_NICKNAME_LENGHT || name.empty() || !isalpha(name[0]))
            return false;

        for (size_t i = 1; i < name.size(); i++)
        {
			if (!isalnum(name[i]) && SPECIAL_CHAR_NICK.find(name[i]) == std::string::npos)
                return false;
        }

		return true;
    }

    bool isValidChannelName(const std::string& name)
    {
        if (name.size() >= MAX_CHANNEL_LENGHT || name.size() < 2 || name[0] != '#')
            return false;

		for (size_t i = 1; i < name.size(); i++)
			if (isspace(name[i]) || name[i] == 7 || name[i] == 44) return false;

		return true;
    }

    bool isValidUsername(const std::string& name)
    {
        if (name.size() >= MAX_USERNAME_LENGHT || name.empty() || !isalpha(name[0]))
            return false;

        for (size_t i = 1; i < name.size(); i++)
			if (!isalnum(name[i]) && name[i] != '-' && name[i] != '_') return false;

		return true;
    }

    bool isValidRealname(const std::string& name)
    {
        if (name.size() >= MAX_REALNAME_LENGHT || name.empty()) return false;

        for (size_t i = 1; i < name.size(); i++)
			if (name[i] < 32) return false;

		return true;
    }

    bool isValidLimit(const char* str)
    {
        char* endptr;
        errno = 0;

        unsigned long val = std::strtoul(str, &endptr, 10);

        if (endptr == str || *endptr != '\0') return false;
        if (errno == ERANGE || val == ULONG_MAX) return false;

        return true;
    }

    void tryRegister(Client& client, const IResponseSender& sender, const IServerData& data)
    {
        if (client.getNickname().empty() || client.getUsername().empty()) return ;

        client.setIsRegistered(true);

        // Send numerics 001-004
        std::map<std::string, std::string> markers;
        markers["nick"] = client.getNickname();
        markers["user"] = client.getUsername();
        markers["host"] = "localhost";
        MessageDispatcher::dispatchNumRpl(sender, client, client.getNickname(), NumRpl::RPL_WELCOME, markers);

        markers.clear();
        markers["servername"] = data.getServername();
        markers["ver"] = "1.0";
        MessageDispatcher::dispatchNumRpl(sender, client, data.getServername(), NumRpl::RPL_YOURHOST, markers);

        markers.clear();
        markers["date"] = getCurrentDateTime();
        MessageDispatcher::dispatchNumRpl(sender, client, data.getServername(), NumRpl::RPL_CREATED, markers);

        markers.clear();
        markers["servername"] = data.getServername();
        markers["version"] = "1.0";
        markers["available channel modes"] = "itkol";
        MessageDispatcher::dispatchNumRpl(sender, client, data.getServername(), NumRpl::RPL_MYINFO, markers);
    }
}
