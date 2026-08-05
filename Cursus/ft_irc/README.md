### *This project has been created as part of the 42 curriculum by dvacas-h, dbohoyo-, jsanz-bo.*

# ft_irc

## Description

ft_irc is a 42 project focused on building an IRC server in **C++ 98**. The goal is to implement a server that can handle multiple clients at the same time, using non-blocking I/O and a single `poll()`-based event loop, while respecting the behavior expected by a standard IRC client.

The server supports authentication with a password, nickname and username registration, channel management, private messages, and the core channel operator commands required by the subject, such as `KICK`, `INVITE`, `TOPIC`, and `MODE`.

### Main features

- TCP/IP server compatible with IPv4 or IPv6.
- Multiple clients handled simultaneously without forking.
- Non-blocking input and output.
- Authentication with a server password.
- Nickname and username registration.
- Channel join and leave flow.
- Private messages between users.
- Message broadcasting inside channels.
- Channel operator and regular user roles.
- Operator commands: `KICK`, `INVITE`, `TOPIC`, and channel modes `i`, `t`, `k`, `o`, `l`.

## Instructions

### Compilation

Build the project from the repository root with:

```bash
make
```

### Execution

Run the server with:

```bash
./ircserv <port> <password>
```

- `port`: listening port for incoming IRC connections.
- `password`: connection password required by clients.

### Testing with netcat

You can test the server quickly using `nc` (netcat):

```bash
nc -C 127.0.0.1 6667
```

### Notes

- The project must follow the instructions of the 42 subject: no IRC client implementation and no server-to-server communication.
- The server should correctly handle partial messages and low-bandwidth scenarios by aggregating incoming data before processing commands.

## Resources

### Official and technical references

- RFC 1459 - Internet Relay Chat Protocol
- RFC 2812 - Internet Relay Chat: Client Protocol
- RFC 2813 - Internet Relay Chat: Server Protocol
- cppreference - C++98 language and standard library reference
- man pages for `poll`, `select`, `socket`, `bind`, `listen`, `accept`, `recv`, and `send`

### IRC and networking references

- IRC documentation and client manuals for reference command behavior.
- Articles about non-blocking sockets and event-driven network programming.
- Tutorials on TCP/IP communication, client/server architecture, and socket handling.

### Use of artificial intelligence

Artificial intelligence was used strictly as a supporting tool for:

- Clarifying and studying concepts.