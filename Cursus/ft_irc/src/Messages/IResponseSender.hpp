#ifndef IRESPONSESENDER_HPP
#define IRESPONSESENDER_HPP

#include <map>
#include <string>

class Client;

class IResponseSender
{
    public:
        virtual ~IResponseSender() {}
        virtual void sendMessage(int fd, const std::string& msg) const = 0;
        virtual void sendBroadcast(const std::map<std::string, Client*>& clients,
                                   const std::string& message) const = 0;
};

#endif
