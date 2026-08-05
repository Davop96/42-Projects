#include "Client.hpp"

  // **************************************************** //
 //                     Constructor                      //
// **************************************************** //

    Client::Client(int socket_fd, const std::string& ip)
    : _socket(socket_fd), _ip(ip), _isRegistered(false), _passOk(false), _isOperator(false) {}


  // **************************************************** //
 //                      Getters                         //
// **************************************************** //

    int Client::getSocket() const { return _socket; }
	const std::string& Client::getIp() const { return _ip; }
    const std::string& Client::getNickname() const { return _nickname; }
    const std::string& Client::getUsername() const { return _username; }
	const std::string& Client::getRealname() const { return _realname; }
    const std::string& Client::getHostname() const { return _hostname; }
    const std::string& Client::getServer() const { return _server; }
    const std::string& Client::getPassword() const { return _password; }
    bool Client::isRegistered() const { return _isRegistered; }
    bool Client::isPassOk() const { return _passOk; }
    bool Client::isOperator() const { return _isOperator; }
    Client::channel_iterator Client::getChannelsBegin() const { return _channels.begin(); }
    Client::channel_iterator Client::getChannelsEnd() const { return _channels.end(); }


  // **************************************************** //
 //                      Setters                         //
// **************************************************** //

    void Client::setNickname(const std::string& nickname) { this->_nickname = nickname; }
    void Client::setUsername(const std::string& username) { this->_username = username; }
	void Client::setRealname(const std::string& realname) { this->_realname = realname; }
    void Client::setHostname(const std::string& hostname) { this->_hostname = hostname; }
    void Client::setServer(const std::string& server) { this->_server = server; }
    void Client::setPassword(const std::string& server) { this->_password = server; }
    void Client::setIsRegistered(bool isRegistered) { this->_isRegistered = isRegistered; }
    void Client::setPassOk(bool passOk) { this->_passOk = passOk; }
    void Client::setIsOperator(bool isOperator) { this->_isOperator = isOperator; }
    void Client::addChannel(const std::string& channel) { this->_channels.insert(channel); }
    void Client::removeChannel(const std::string& channel) { this->_channels.erase(channel); }
    