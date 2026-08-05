#ifndef SERVER_HPP
#define SERVER_HPP
#include <map>
#include <string>
#include <vector>
#include <poll.h>
#include "IServerEvents.hpp"

class Server
{
	public:
		Server(int port, const std::string &password);
		~Server();

		void setEvents(IServerEvents *events);
		void run();
		void stop();

		bool sendToClient(int fd, const std::string &rawBytes);
		const std::string &getPassword() const;

	private:
		Server(const Server &);
		Server &operator=(const Server &);

		void initListenSocket();
		void acceptNewClients();

		bool handleClientRead(int fd);
		bool handleClientWrite(int fd);

		void disconnectClient(int fd);
		void addPollFd(int fd);
		void removePollFd(int fd);
		void updateClientPollEvents(int fd);

		std::map<int, std::string>::iterator findWriteBuffer(int fd);

		int _port;
		std::string _password;
		int _listenFd;
		bool _running;
		bool _stdinTestModeEnabled;

		IServerEvents *_events;
		std::vector<struct pollfd> _pfds;
		std::map<int, std::string> _writeBuffers;
		std::map<int, std::string> _clientIps;
};

#endif
