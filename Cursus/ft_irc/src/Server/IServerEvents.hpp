#ifndef ISERVEREVENTS_HPP
#define ISERVEREVENTS_HPP

#include <string>

class IServerEvents
{
	public:
		virtual ~IServerEvents() {}
		virtual void onClientConnected(int fd, const std::string &ip) = 0; // when a client connects
		virtual void onClientDisconnected(int fd) = 0;	// when a client leaves or drops
		virtual void onBytesReceived(int fd, const char *data, std::size_t len) = 0; // when bytes arrive from a client
};

#endif
