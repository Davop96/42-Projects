#include "Server.hpp"
#include "Dispatcher.hpp"
#include "ServerData.hpp"

#include <csignal>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

namespace
{
	Server* g_serverInstance = NULL;

	void handleShutdownSignal(int)
	{
		if (g_serverInstance != NULL)
		{
			g_serverInstance->stop();
		}
	}
}

// Parses a decimal port string and validates the 1..65535 range.
static bool parsePort(const std::string& portText, int& outPort)
{
	std::istringstream iss(portText);
	int port = 0;
	char extra = 0;

	if (!(iss >> port) || (iss >> extra))
	{
		return false;
	}
	if (port < 1 || port > 65535)
	{
		return false;
	}
	outPort = port;
	return true;
}

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		std::cerr << "Usage: ./ircserv <port> <password>" << std::endl;
		return 1;
	}

	int port = 0;
	if (!parsePort(argv[1], port))
	{
		std::cerr << "Invalid port: " << argv[1] << std::endl;
		return 1;
	}

	const std::string password = argv[2];
	try
	{
		Server server(port, password);
		ServerData data;
		Dispatcher dispatcher(server, data);
		g_serverInstance = &server;
		std::signal(SIGINT, handleShutdownSignal);
		std::signal(SIGTERM, handleShutdownSignal);
		server.setEvents(&dispatcher);
		server.run();
		g_serverInstance = NULL;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Fatal server error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
