#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include "Client.hpp"
#include "IResponseSender.hpp"
#include "IServerData.hpp"
#include <string>

namespace Validation
{
    const size_t MAX_NICKNAME_LENGHT = 9;
    const size_t MAX_USERNAME_LENGHT = 16;
    const size_t MAX_REALNAME_LENGHT = 100;
    const size_t MAX_CHANNEL_LENGHT = 200;

    const std::string SPECIAL_CHAR_NICK = "[\\]^`{|}-_";
    
    bool isValidNickname(const std::string& name);
    bool isValidUsername(const std::string& name);
    bool isValidRealname(const std::string& name);
    bool isValidChannelName(const std::string& name);
    bool isValidLimit(const char* str);

    void tryRegister(Client& client, const IResponseSender& sender, const IServerData& data);
}

#endif
