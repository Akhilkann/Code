
#ifndef REMOTE_LOGGING_NETWORK_HPP
#define REMOTE_LOGGING_NETWORK_HPP

#include "LogConfig.hpp"
#include <iostream>
#include <string>
using namespace std;

class RemoteLoggingNetwork
{
public:
    RemoteLoggingNetwork(const LogConfig &config);
    void writeToNetwork(const std::string &formatted);

private:
    LogConfig serverconfig;
};

#endif