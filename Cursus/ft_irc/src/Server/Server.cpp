#include "Server.hpp"
#include <cerrno>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/socket.h>
#include <unistd.h>

// Utility: local helper function, not exported to other files.
// Sets non-blocking mode on a file descriptor so slow clients do not block the server.
namespace
{
	int setNonBlocking(int fd)
	{
        return (fcntl(fd, F_SETFL, O_NONBLOCK));
	}
}

// Constructor and initialization
Server::Server(int port, const std::string &password)
    : _port(port), _password(password), _listenFd(-1), _running(false), _events(NULL)
{
    signal(SIGPIPE, SIG_IGN);
}

// Destructor: closes the listening socket and all valid client fds.
Server::~Server()
{
    if (_listenFd >= 0)
	{
        close(_listenFd);
    }
    std::vector<struct pollfd>::iterator it = _pfds.begin();
    while (it != _pfds.end())
	{
        if (it->fd >= 0 && it->fd != _listenFd)
		{
            close(it->fd);
        }
        ++it;
    }
}

// Stores the object implementing IServerEvents.
void Server::setEvents(IServerEvents *events)
{
    _events = events;
}

// Returns a reference to the server password.
const std::string &Server::getPassword() const
{
    return (_password);
}

// Creates an IPv4 TCP socket.
// Leaves the server listening for incoming connections.
void Server::initListenSocket()
{
    _listenFd = socket(AF_INET, SOCK_STREAM, 0);
    if (_listenFd < 0)
	{
        throw std::runtime_error("socket() failed");
    }
    int opt = 1;
    if (setsockopt(_listenFd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
	{
        close(_listenFd);
        _listenFd = -1;
        throw std::runtime_error("setsockopt(SO_REUSEADDR) failed");
    }
// Sets the listening fd to non-blocking mode; throws on failure.
    if (setNonBlocking(_listenFd) < 0)
	{
        close(_listenFd);
        _listenFd = -1;
        throw std::runtime_error("fcntl(O_NONBLOCK) failed on listen socket");
    }
    struct sockaddr_in addr;
    std::memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(static_cast<unsigned short>(_port));
    if (bind(_listenFd, reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr)) < 0)
	{
        const std::string reason = std::strerror(errno);
        close(_listenFd);
        _listenFd = -1;
        throw std::runtime_error("bind() failed: " + reason);
    }
    if (listen(_listenFd, SOMAXCONN) < 0)
	{
        const std::string reason = std::strerror(errno);
        close(_listenFd);
        _listenFd = -1;
        throw std::runtime_error("listen() failed: " + reason);
    }
    struct pollfd pfd;
    pfd.fd = _listenFd;
    pfd.events = POLLIN;
    pfd.revents = 0;
    _pfds.push_back(pfd);
}

// Single-threaded server loop.
void Server::run()
{
    if (_listenFd < 0)
	{
        initListenSocket();
    }

    std::cout << "[server] connected" << std::endl;
    _running = true;
    while (_running)
	{
        int ret = poll(&_pfds[0], _pfds.size(), -1);
        if (ret < 0)
		{
            if (errno == EINTR)
			{
                continue;
            }
            std::cerr << "[error] poll: " << std::strerror(errno) << std::endl;
            continue;
        }
        for (std::size_t i = 0; i < _pfds.size(); ++i)
		{
            short revents = _pfds[i].revents;
            if (revents == 0)
			{
                continue;
            }
            int fd = _pfds[i].fd;
            if (fd == _listenFd)
			{
                if (revents & POLLIN)
				{
                    acceptNewClients();
                }
                continue;
            }
            if (revents & (POLLERR | POLLHUP | POLLNVAL))
			{
                disconnectClient(fd);
                --i;
                continue;
            }
            if (revents & POLLIN)
			{
                if (!handleClientRead(fd))
				{
                    disconnectClient(fd);
                    --i;
                    continue;
                }
            }
            if (revents & POLLOUT)
			{
                if (!handleClientWrite(fd))
				{
                    disconnectClient(fd);
                    --i;
                    continue;
                }
            }
        }
    }
}

// Signals the end of the main loop.
void Server::stop()
{
    _running = false;
}

// Loop to accept new clients.
void Server::acceptNewClients()
{
    struct sockaddr_in clientAddr;
    socklen_t addrLen = sizeof(clientAddr);
    int clientFd = accept(_listenFd, reinterpret_cast<struct sockaddr *>(&clientAddr), &addrLen);
    if (clientFd < 0)
	{
        return;
	}
    if (setNonBlocking(clientFd) < 0)
	{
        close(clientFd);
        return;
	}
    char ipBuffer[INET_ADDRSTRLEN];
    const char *ip = inet_ntop(AF_INET, &clientAddr.sin_addr, ipBuffer, sizeof(ipBuffer));
    if (ip == NULL)
	{
        _clientIps[clientFd] = "unknown";
    }
	else
	{
        _clientIps[clientFd] = ip;
    }
    addPollFd(clientFd);
    _writeBuffers[clientFd] = "";
    if (_events != NULL)
	{
        _events->onClientConnected(clientFd, _clientIps[clientFd]);
	}
}

// Incoming bytes for IRC commands.
bool Server::handleClientRead(int fd)
{
    char buffer[4096];
    ssize_t bytes = recv(fd, buffer, sizeof(buffer), 0);

    if (bytes == 0)
	{
        return (false);
    }
    if (bytes < 0)
	{
        return (false);
    }
    if (_events != NULL)
	{
        _events->onBytesReceived(fd, buffer, static_cast<std::size_t>(bytes));
    }
    return (true);
}

// Implements non-blocking writes and partial sends.
bool Server::handleClientWrite(int fd)
{
    std::map<int, std::string>::iterator it = findWriteBuffer(fd);
    if (it == _writeBuffers.end())
	{
        return (false);
    }
    if (it->second.empty())
	{
        updateClientPollEvents(fd);
        return (true);
    }
    ssize_t sent = send(fd, it->second.data(), it->second.size(), 0);
    if (sent == 0)
	{
		return (false);
	}
    if (sent < 0)
	{
        return (false);
    }
    it->second.erase(0, static_cast<std::size_t>(sent));
    updateClientPollEvents(fd);
    return (true);
}

// Server response to a client.
bool Server::sendToClient(int fd, const std::string &rawBytes)
{
    std::map<int, std::string>::iterator it = findWriteBuffer(fd);
    if (it == _writeBuffers.end())
	{
        return (false);
    }
    it->second += rawBytes;
    updateClientPollEvents(fd);
    return (true);
}

// Disconnects a client and cleans internal structures.
void Server::disconnectClient(int fd)
{
    if (_events != NULL)
	{
        _events->onClientDisconnected(fd);
    }
    close(fd);
    removePollFd(fd);
    _writeBuffers.erase(fd);
    _clientIps.erase(fd);
}

// Registers a new fd.
void Server::addPollFd(int fd)
{
    struct pollfd pfd;
    pfd.fd = fd;
    pfd.events = POLLIN;
    pfd.revents = 0;
    _pfds.push_back(pfd);
}

// Removes a closed client fd.
void Server::removePollFd(int fd)
{
    for (std::vector<struct pollfd>::iterator it = _pfds.begin(); it != _pfds.end(); ++it) {
        if (it->fd == fd)
		{
            _pfds.erase(it);
            return;
        }
    }
}

// Avoids waking poll when there is nothing to send, improving performance.
void Server::updateClientPollEvents(int fd)
{
    std::map<int, std::string>::iterator it = findWriteBuffer(fd);
    if (it == _writeBuffers.end())
	{
        return;
    }

    for (std::vector<struct pollfd>::iterator pit = _pfds.begin(); pit != _pfds.end(); ++pit)
	{
        if (pit->fd == fd)
		{
            pit->events = POLLIN;
            if (!it->second.empty())
			{
                pit->events = static_cast<short>(pit->events | POLLOUT);
            }
            return;
        }
    }
}

// Returns an iterator to the per-fd write-buffer map and reuses the lookup.
std::map<int, std::string>::iterator Server::findWriteBuffer(int fd)
{
    return (_writeBuffers.find(fd));
}
