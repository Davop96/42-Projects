#include "CommandHandler.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

namespace CommandHandler
{
    namespace
    {
        struct handlerUtils
        {
            const IResponseSender& sender;
            const IServerData& data;
            IChannelService& channelManager;

            const Client& client;
            const Message& msg;

            const std::string& channel;
            const std::string& modestring;

            std::string resultMessage;
            std::string paramsConsumed;
            char actOp;

            handlerUtils(const IResponseSender& s, const IServerData& d, IChannelService& cm,
                            const Client& cl, const Message& m, const std::string& ch,
                            const std::string& ms)
            : sender(s), data(d), channelManager(cm), client(cl), msg(m), channel(ch), modestring(ms),
                actOp(0) {}
        };

        const std::string buildChannelmodes(IChannelService& channelManager,
                                            const std::string& channel)
        {
            std::string channelmodes = "+";

            if (channelManager.isInvitedOnly(channel)) channelmodes.push_back('i');
            if (channelManager.hasTopicRestrictions(channel)) channelmodes.push_back('t');
            if (channelManager.hasKey(channel)) channelmodes.push_back('k');
            if (channelManager.hasLimit(channel)) channelmodes.push_back('l');

            if (channelManager.hasKey(channel))
                channelmodes.append(" " + channelManager.getKey(channel));

            if (channelManager.hasLimit(channel))
            {
                int l = channelManager.getLimit(channel);
                std::ostringstream oss;
                oss << l;
                channelmodes.append(" " + oss.str());
            }

            return channelmodes;
        }

        void addExecMode(char mode, char op, handlerUtils& utils, const std::string& arg = "")
        {
            if (utils.actOp != op) utils.resultMessage.push_back(op);
            utils.resultMessage.push_back(mode);

            if (!arg.empty()) utils.paramsConsumed.append(" " + arg);
        }

        void execMode(char mode, char op, handlerUtils& utils, const std::string& arg = "")
        {
            switch (mode)
            {
                case 'i':
                    utils.channelManager.setInvitedOnly(utils.channel, op == '+');
                    addExecMode(mode, op, utils);
                    break ;

                case 't':
                    utils.channelManager.setTopicRestrictions(utils.channel, op == '+');
                    addExecMode(mode, op, utils);
                    break ;

                case 'k':
                    utils.channelManager.setKey(utils.channel, arg);
                    if(op == '+') addExecMode(mode, op, utils, arg);
                    else addExecMode(mode, op, utils);
                    break ;

                case 'o':
                    if (op == '+')
                        utils.channelManager.addOperator(utils.channel, arg);
                    else
                        utils.channelManager.removeOperator(utils.channel, arg);
                    addExecMode(mode, op, utils, arg);
                    break ;

                case 'l':
                    if (op == '+')
                    {
                        utils.channelManager.setLimit(utils.channel, static_cast<size_t>(std::strtoul(arg.c_str(), NULL, 10)));
                        addExecMode(mode, op, utils, arg);
                    }
                    else
                    {
                        utils.channelManager.setLimit(utils.channel, 0);
                        addExecMode(mode, op, utils);
                    }
                    break ;

                default:
                    break ;
            }
        }

        void handleModestring(handlerUtils& utils)
        {
            const char modesArray[] = { 'i', 't', 'k', 'o', 'l' };
            std::set<char> avModes(modesArray, modesArray + 5);

            char op = utils.modestring[0];
            size_t j = 2;

            for (size_t i = 1; i < utils.modestring.size(); i++)
            {
                if (utils.modestring[i] == '+' || utils.modestring[i] == '-')
                {
                    op = utils.modestring[i];
                    continue ;
                }
                else if (avModes.find(utils.modestring[i]) == avModes.end())
                {
                    std::map<std::string, std::string> markers;
                    markers["char"] = std::string(1, utils.modestring[i]);
                    markers["channel"] = utils.channel;
                    MessageDispatcher::dispatchNumRpl(utils.sender, utils.client, std::string(1, utils.modestring[i]), NumRpl::ERR_UNKNOWNMODE, markers);
                    return ;
                }

                const std::string& arg = utils.msg.getParamByInd(j);
                if (op == '+' && std::string("kl").find(utils.modestring[i]) != std::string::npos)
                {
                    if (arg.empty())
                    {
                        std::map<std::string, std::string> markers;
                        markers["command"] = "MODE";
                        MessageDispatcher::dispatchNumRpl(utils.sender, utils.client, "MODE", NumRpl::ERR_NEEDMOREPARAMS, markers);
                        return ;
                    }
                    if (utils.modestring[i] == 'k' && utils.channelManager.hasKey(utils.channel))
                    {
                        std::map<std::string, std::string> markers;
                        markers["channel"] = utils.channel;
                        MessageDispatcher::dispatchNumRpl(utils.sender, utils.client, utils.channel, NumRpl::ERR_KEYSET, markers);
                        return ;
                    }
                    if (utils.modestring[i] == 'l' && !Validation::isValidLimit(arg.c_str()))
                    {
                        MessageDispatcher::dispatchNumRpl(utils.sender, utils.client, utils.channel, NumRpl::ERR_INVALIDMODEPARAM);
                        return ;
                    }

                    execMode(utils.modestring[i], op, utils, arg);
                    j++;
                }
                else if (utils.modestring[i] == 'o')
                {
                    if (arg.empty())
                    {
                        std::map<std::string, std::string> markers;
                        markers["command"] = "MODE";
                        MessageDispatcher::dispatchNumRpl(utils.sender, utils.client, "MODE", NumRpl::ERR_NEEDMOREPARAMS, markers);
                        return ;
                    }
                    if (!utils.data.isNickInUse(arg))
                    {
                        std::map<std::string, std::string> markers;
                        markers["nickname"] = arg;
                        MessageDispatcher::dispatchNumRpl(utils.sender, utils.client, arg, NumRpl::ERR_NOSUCHNICK, markers);
                        return ;
                    }
                    if (!utils.channelManager.hasMember(utils.channel, arg))
                    {
                        std::map<std::string, std::string> markers;
                        markers["nick"] = arg;
                        markers["channel"] = utils.channel;
                        MessageDispatcher::dispatchNumRpl(utils.sender, utils.client, arg + " " + utils.channel, NumRpl::ERR_USERNOTINCHANNEL, markers);
                        return ;
                    }

                    execMode(utils.modestring[i], op, utils, arg);
                }
                else execMode(utils.modestring[i], op, utils);
                utils.actOp = op;
            }
        }
    }

    void handleMode(const IResponseSender& sender, const IServerData& data,
                    IChannelService& channelManager, const Client& client, const Message& msg)
    {
        const std::string& channel = msg.getParamByInd(0);
        if (channel.empty())
        {
            std::map<std::string, std::string> markers;
            markers["command"] = "MODE";
            MessageDispatcher::dispatchNumRpl(sender, client, "MODE", NumRpl::ERR_NEEDMOREPARAMS, markers);
            return ;
        }
        if (!Validation::isValidChannelName(channel))
        {
            std::map<std::string, std::string> markers;
            markers["channel"] = channel;
            MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::ERR_BADCHANMASK, markers);
            return ;
        }
        if (!channelManager.channelExists(channel))
        {
            std::map<std::string, std::string> markers;
            markers["channel name"] = channel;
            MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::ERR_NOSUCHCHANNEL, markers);
            return ;
        }

        const std::string& modestring = msg.getParamByInd(1);
        if (modestring.empty())
        {
            const std::string channelmodes = buildChannelmodes(channelManager, channel);
            
            std::map<std::string, std::string> markers;
            markers["channel"] = channel;
            markers["mode"] = channelmodes;
            markers["mode params"] = "";
            
            MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::RPL_CHANNELMODEIS, markers);
            return ;
        }
        if ((modestring[0] != '+' && modestring[0] != '-'))
        {
            std::map<std::string, std::string> markers;
            markers["char"] = std::string(1, modestring[0]);
            markers["channel"] = channel;
            MessageDispatcher::dispatchNumRpl(sender, client, std::string(1, modestring[0]), NumRpl::ERR_UNKNOWNMODE, markers);
            return ;
        }

        if (!channelManager.hasMember(channel, client.getNickname()))
        {
            std::map<std::string, std::string> markers;
            markers["channel"] = channel;
            MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::ERR_NOTONCHANNEL, markers);
            return ;
        }
        if (!channelManager.isUserOperator(channel, client.getNickname()))
        {
            std::map<std::string, std::string> markers;
            markers["channel"] = channel;
            MessageDispatcher::dispatchNumRpl(sender, client, channel, NumRpl::ERR_CHANOPRIVSNEEDED, markers);
            return ;
        }

        handlerUtils utils(sender, data, channelManager, client, msg, channel, modestring);
        handleModestring(utils);
        utils.resultMessage.append(utils.paramsConsumed);

        std::vector<std::string> params;
        params.push_back(channel);
        params.push_back(utils.resultMessage);

        Message modeMsg("", "MODE", params, "");
        MessageDispatcher::dispatchMulticastMessage(sender, client, modeMsg,
                                                    channelManager.getClientsMap(channel));
    }
}
