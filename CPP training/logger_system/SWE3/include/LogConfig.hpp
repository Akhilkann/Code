#ifndef LOGCONFIG_HPP
#define LOGCONFIG_HPP

#include "LogLevel.hpp"

struct LogConfig {
    LogLevel consoleLevel;
    LogLevel fileLevel;
    LogLevel networkLevel;
    
    int fileSize;
    int networkPort;

    std::string filePath;
    std::string networkIP;
    std::string mode;
    static LogConfig loadFromFile(const std::string& path);
};

#endif