#include "ClientBuffer.hpp"

static const size_t IRC_MAX_PAYLOAD_LEN = 510;

namespace
{
	std::string stripEot(const std::string& chunk)
	{
		std::string cleaned;
		cleaned.reserve(chunk.size());
		for (size_t i = 0; i < chunk.size(); ++i)
		{
			if (chunk[i] != '\x04')
			{
				cleaned += chunk[i];
			}
		}
		return cleaned;
	}
}

ClientBuffer::ClientBuffer()
{
}

void ClientBuffer::appendChunk(const std::string& chunk)
{
	_buffer += stripEot(chunk);
}

bool ClientBuffer::extractNextMessage(std::string& outMessage, std::string& protocolError)
{
	protocolError.clear();
	outMessage.clear();

	size_t delimiterPos = _buffer.find("\n");

	// Incomplete frame: still waiting for end-of-line.
	if (delimiterPos == std::string::npos)
	{
		if (_buffer.size() > IRC_MAX_PAYLOAD_LEN)
		{
			protocolError = "Buffered data exceeds IRC payload limit (510 bytes)";
		}
		return false;
	}

	// Complete frame exists but exceeds max IRC line length.
	if (delimiterPos > IRC_MAX_PAYLOAD_LEN)
	{
		protocolError = "IRC message payload exceeds 510 bytes";
		return false;
	}

	outMessage = _buffer.substr(0, delimiterPos);
	if (!outMessage.empty() && outMessage[outMessage.size() - 1] == '\r')
	{
		outMessage.erase(outMessage.size() - 1);
	}
	_buffer.erase(0, delimiterPos + 1);
	return true;
}

void ClientBuffer::clear()
{
	_buffer.clear();
}
