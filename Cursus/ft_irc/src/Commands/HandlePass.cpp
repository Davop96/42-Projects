#include "CommandHandler.hpp"

namespace CommandHandler
{
    void handlePass(const IResponseSender& sender, Client& client,
                    const std::string& serverPass, const Message& msg)
    {
        const std::string& password = msg.getParamByInd(0);
        if (password.empty())
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "PASS";
            MessageDispatcher::dispatchNumRpl(sender, client, "PASS", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }
        if (client.isRegistered())
        {
            MessageDispatcher::dispatchNumRpl(sender, client, "", NumRpl::ERR_ALREADYREGISTERED);
            return ;
        }

        client.setPassword(password);
        client.setPassOk(password == serverPass);
    }
}
