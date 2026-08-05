#ifndef COMMANDHANDLER_HPP
#define COMMANDHANDLER_HPP

#include "Client.hpp"
#include "Channel.hpp"
#include "ServerData.hpp"
#include "Validation.hpp"
#include "Message.hpp"
#include "IResponseSender.hpp"
#include "IServerData.hpp"
#include "IChannelService.hpp"
#include "MessageDispatcher.hpp"
#include "NumRpl.hpp"
#include <string>

namespace CommandHandler
{
    void handlePass(const IResponseSender& sender, Client& client,
                    const std::string& serverPass, const Message& msg);

    void handleNick(const IResponseSender& sender, IServerData& data, IChannelService& channelManager,
                    Client& client, const Message& msg);

    void handleUser(const IResponseSender& sender, const IServerData& data, Client& client,
                    const Message& msg);

    void handleJoin(const IResponseSender& sender, IServerData& data, IChannelService& channelManager,
                    Client& client, const Message& msg);

    void handlePart(const IResponseSender& sender, IChannelService& channelManager,
                    Client& client, const Message& msg);

    void handleKick(const IResponseSender& sender, IServerData& data,
                    IChannelService& channelManager, const Client& kicker,
                    const Message& msg);

    void handleInvite(const IResponseSender& sender, IServerData& data,
                        IChannelService& channelManager, const Client& inviter, const Message& msg);

    void handleTopic(const IResponseSender& sender, IChannelService& channelManager,
                        const Client& client, const Message& msg);

    void handleMode(const IResponseSender& sender, const IServerData& data,
                    IChannelService& channelManager, const Client& client, const Message& msg);

    void handlePrivmsg(const IResponseSender& sender, const IServerData& data,
                        IChannelService& channelManager, const Client& client, const Message& msg);

    void handleNotice(const IResponseSender& sender, const IServerData& data,
                        IChannelService& channelManager, const Client& client, const Message& msg);
};

#endif
