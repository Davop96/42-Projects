#ifndef MESSAGEDISPATCHER_HPP
#define MESSAGEDISPATCHER_HPP

#include "Client.hpp"
#include "IResponseSender.hpp"
#include "NumRpl.hpp"
#include "Message.hpp"
#include <string>
#include <map>

namespace MessageDispatcher
{
    void dispatchNumRpl(const IResponseSender& sender, const Client& client, const std::string& arg,
                        const NumRpl::NumRplType& type, 
                        const std::map<std::string, std::string>& markers = std::map<std::string, std::string>());

    void dispatchUnicastMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                int socketDest);

    void dispatchMulticastMessage(const IResponseSender& sender, const Client& client,
                                    const Message& input, const std::map<std::string, Client*> dest);
    
    void dispatchJoinMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest);

    void dispatchPartMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest);

    void dispatchNickMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest);

    void dispatchModeMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest);

    void dispatchTopicMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest);

    void dispatchKickMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest);

    void dispatchInviteMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                int dest);
}

// namespace ClientMessageDispatcher
// {
//     std::string buildClientMessage(const Client& client, const std::string& cmd,
//                         const std::string& dest, const std::string& trailing);
// }

#endif
