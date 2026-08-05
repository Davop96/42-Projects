#ifndef CLIENTBUFFER_HPP
#define CLIENTBUFFER_HPP

#include <string>

class ClientBuffer
{
public:
	ClientBuffer();

	// Appends raw received bytes to the internal per-client buffer.
	void appendChunk(const std::string& chunk);

	// If protocolError is not empty, the buffered data is invalid.
	bool extractNextMessage(std::string& outMessage, std::string& protocolError);

	// Clears buffered data (useful after a protocol error).
	void clear();

private:
	std::string _buffer;
};

#endif
