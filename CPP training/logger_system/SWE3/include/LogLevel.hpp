#ifndef LOGLEVEL_HPP
#define LOGLEVEL_HPP

#include <string>
#include <stdexcept>

enum class LogLevel {
    
    TRC, DBG, INF, WRN, ERR, CRT, OFF
};

LogLevel parseLogLevel(const std::string& levelStr);
std::string logLevelToString(LogLevel level);

#endif