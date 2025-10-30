#include "LogLevel.hpp"

LogLevel parseLogLevel(const std::string& levelStr) {

    if (levelStr == "off") return LogLevel::OFF;
    if (levelStr == "crt") return LogLevel::CRT;
    if (levelStr == "err") return LogLevel::ERR;
    if (levelStr == "wrn") return LogLevel::WRN;
    if (levelStr == "inf") return LogLevel::INF;
    if (levelStr == "dbg") return LogLevel::DBG;
    if (levelStr == "trc") return LogLevel::TRC;
    throw std::invalid_argument("Invalid log level: " + levelStr);

}

std::string logLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::OFF: return "OFF";
        case LogLevel::CRT: return "CRT";
        case LogLevel::ERR: return "ERR";
        case LogLevel::WRN: return "WRN";
        case LogLevel::INF: return "INF";
        case LogLevel::DBG: return "DBG";
        case LogLevel::TRC: return "TRC";
        default: throw std::invalid_argument("Invalid log level");
    }
}