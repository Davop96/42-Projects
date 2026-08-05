#include "CommandHandler.hpp"

namespace CommandHandler
{
    void handleUser(const IResponseSender& sender, const IServerData& data, Client& client,
                    const Message& msg)
    {
        if (msg.paramCount() < 4 && !msg.hasTrailing())
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "USER";
            MessageDispatcher::dispatchNumRpl(sender, client, "USER", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }

        const std::string& user = msg.getParamByInd(0);
        const std::string& name = msg.getParamByInd(3);
        
        if (client.isRegistered())
        {
            MessageDispatcher::dispatchNumRpl(sender, client, "", NumRpl::ERR_ALREADYREGISTERED);
            return ;
        }
        if (!Validation::isValidUsername(user))
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "USER";
            MessageDispatcher::dispatchNumRpl(sender, client, "USER", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }
        if (!Validation::isValidRealname(name))
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "USER";
            MessageDispatcher::dispatchNumRpl(sender, client, "USER", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }

        client.setUsername(user);
        client.setHostname(client.getIp());
        client.setServer(data.getServername());
        client.setRealname(name);

        Validation::tryRegister(client, sender, data);
    }
}
