#include "MessageDispatcher.hpp"

namespace MessageDispatcher
{
    namespace
    {
        std::string buildClientPrefix(const Client& client)
        {
            std::string prefix = client.getNickname();
            prefix += "!";
            prefix += client.getUsername();
            prefix += "@";
            prefix += client.getIp();
            return prefix;
        }

        std::string interpolateMarkers(std::string text, const std::map<std::string, std::string>& markers)
        {
            for (std::map<std::string, std::string>::const_iterator it = markers.begin(); 
                 it != markers.end(); ++it)
            {
                const std::string& marker = it->first;
                const std::string& value = it->second;
                std::string placeholder = "<" + marker + ">";
                
                size_t pos = 0;
                while ((pos = text.find(placeholder, pos)) != std::string::npos)
                {
                    text.replace(pos, placeholder.length(), value);
                    pos += value.length();
                }
            }
            return text;
        }
    }

    void dispatchNumRpl(const IResponseSender& sender, const Client& client, const std::string& arg,
                        const NumRpl::NumRplType& type, 
                        const std::map<std::string, std::string>& markers)
    {
        std::vector<std::string> params;
        client.getNickname().empty() ? params.push_back("*") : params.push_back(client.getNickname());
        if (!arg.empty()) params.push_back(arg);

        const NumRpl::NumRpl_s& num = NumRpl::getNumRpl(type);

        std::string trailing = interpolateMarkers(num.trailing, markers);
        
        Message msg("ircserv", num.code, params, trailing);
        sender.sendMessage(client.getSocket(), msg.getFullCommand() + "\r\n");
    }

    void dispatchUnicastMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                int socketDest)
    {
        const std::string prefix = buildClientPrefix(client);
        const std::vector<std::string> params(1, input.getParamByInd(0));

        Message output(prefix, input.getCommand(), params, input.getParamByInd(1));
        sender.sendMessage(socketDest, output.getFullCommand() + "\r\n");
    }

    void dispatchMulticastMessage(const IResponseSender& sender, const Client& client,
                                    const Message& input, const std::map<std::string, Client*> dest)
    {
        const std::string prefix = buildClientPrefix(client);
        const std::vector<std::string> params(1, input.getParamByInd(0));

        Message output(prefix, input.getCommand(), params, input.getParamByInd(1));
        sender.sendBroadcast(dest, output.getFullCommand() + "\r\n");
    }

    void dispatchJoinMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest)
    {
        const std::string prefix = buildClientPrefix(client);
        const std::vector<std::string> params;

        Message output(prefix, input.getCommand(), params, input.getParamByInd(0));
        sender.sendBroadcast(dest, output.getFullCommand() + "\r\n");
    }

    void dispatchPartMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest)
    {
        const std::string prefix = buildClientPrefix(client);
        const std::vector<std::string> params(1, input.getParamByInd(0));

        Message output(prefix, input.getCommand(), params, input.getParamByInd(1));
        sender.sendBroadcast(dest, output.getFullCommand() + "\r\n");
    }

    void dispatchNickMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest)
    {
        const std::string prefix = buildClientPrefix(client);
        const std::vector<std::string> params;

        Message output(prefix, input.getCommand(), params, input.getParamByInd(0));
        sender.sendBroadcast(dest, output.getFullCommand() + "\r\n");
    }

    void dispatchModeMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest)
    {
        const std::string prefix = buildClientPrefix(client);
        std::vector<std::string> params;
        for (size_t i = 0; i < input.getParamByInd(i).size(); i++)
            params.push_back(input.getParamByInd(i));

        Message output(prefix, input.getCommand(), params, "");
        sender.sendBroadcast(dest, output.getFullCommand() + "\r\n");
    }

    void dispatchTopicMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest)
    {
        const std::string prefix = buildClientPrefix(client);
        const std::vector<std::string> params(1, input.getParamByInd(0));

        Message output(prefix, input.getCommand(), params, input.getParamByInd(1));
        sender.sendBroadcast(dest, output.getFullCommand() + "\r\n");
    }

    void dispatchKickMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                const std::map<std::string, Client*> dest)
    {
        const std::string prefix = buildClientPrefix(client);
        std::vector<std::string> params;
        params.push_back(input.getParamByInd(0));
        params.push_back(input.getParamByInd(1));

        Message output(prefix, input.getCommand(), params, input.getParamByInd(2));
        sender.sendBroadcast(dest, output.getFullCommand() + "\r\n");
    }

    void dispatchInviteMessage(const IResponseSender& sender, const Client& client, const Message& input,
                                int dest)
    {
        const std::string prefix = buildClientPrefix(client);
        const std::vector<std::string> params(1, input.getParamByInd(0));

        Message output(prefix, input.getCommand(), params, input.getParamByInd(1));
        sender.sendMessage(dest, output.getFullCommand() + "\r\n");
    }
}
