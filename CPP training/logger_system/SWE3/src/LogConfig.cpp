#include "LogConfig.hpp"
#include <yaml-cpp/yaml.h>

LogConfig LogConfig::loadFromFile(const std::string& path) {
    YAML::Node config = YAML::LoadFile(path);
    LogConfig logConfig;

    logConfig.mode = config["logger"]["mode"].as<std::string>();
    logConfig.consoleLevel = parseLogLevel(config["logger"]["console_level"].as<std::string>());
    logConfig.fileLevel = parseLogLevel(config["logger"]["file_level"].as<std::string>());
    logConfig.fileSize = config["logger"]["file_size"].as<int>();
    logConfig.filePath = config["logger"]["file_path"].as<std::string>();
    logConfig.networkLevel = parseLogLevel(config["logger"]["network_level"].as<std::string>());
    logConfig.networkIP = config["logger"]["network_ip"].as<std::string>();
    logConfig.networkPort = config["logger"]["network_port"].as<int>();
    
    return logConfig;
}