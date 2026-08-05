#ifndef ISERVERDATA_HPP
#define ISERVERDATA_HPP

#include <string>
//#include <map>

//class Client;

class IServerData
{
    public:
        virtual ~IServerData() {}
        virtual Client* getClient(const std::string& nick) = 0;
        virtual const std::string& getServername() const = 0;
        virtual void addClientByNick(const std::string& nick, Client* client) = 0;
        virtual void removeClientByNick(const std::string& nick) = 0;
        virtual bool isNickInUse(const std::string& nick) const = 0;
        virtual int getClientSocketByNick(const std::string& nick) const = 0;

        virtual void addPendingInvitation(const std::string& channelName,
                                            const std::string& invited) = 0;

        virtual void removePendingInvitation(const std::string& channelName,
                                                const std::string& invited) = 0;
};

#endif
