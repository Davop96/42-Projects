#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <set>

class Client
{
    private:
        int _socket;

        std::string _ip;

        std::string _nickname;
        std::string _username;
        std::string _realname;

        std::string _hostname;
        std::string _server;
        std::string _password;

        bool _isRegistered;
        bool _passOk;
        bool _isOperator;

        std::set<std::string> _channels;

    public:
        Client(int socket_fd, const std::string& ip);

        typedef std::set<std::string>::const_iterator channel_iterator;

        int getSocket() const;
        const std::string& getIp() const;
        const std::string& getNickname() const;
        const std::string& getUsername() const;
        const std::string& getRealname() const;
        const std::string& getHostname() const;
        const std::string& getServer() const;
        const std::string& getPassword() const;
        bool isRegistered() const;
        bool isPassOk() const;
        bool isOperator() const;
        channel_iterator getChannelsBegin() const;
        channel_iterator getChannelsEnd() const;

        void setNickname(const std::string& nickname);
        void setUsername(const std::string& username);
        void setRealname(const std::string& realname);
        void setHostname(const std::string& hostname);
        void setServer(const std::string& server);
        void setPassword(const std::string& password);
        void setIsRegistered(bool isRegistered);
        void setPassOk(bool passOk);
        void setIsOperator(bool isOperator);
        void addChannel(const std::string& channel);
        void removeChannel(const std::string& channel);
};

#endif
