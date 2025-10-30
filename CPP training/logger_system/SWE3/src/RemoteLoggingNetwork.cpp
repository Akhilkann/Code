#include "LoggingLibrary.hpp"
#include "RemoteLoggingNetwork.hpp"
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

RemoteLoggingNetwork::RemoteLoggingNetwork(const LogConfig &config)
{
    this->serverconfig = config;
}
void RemoteLoggingNetwork::writeToNetwork(const std::string &formatted)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        throw std::runtime_error("Failed to create socket");
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(serverconfig.networkPort);
    inet_pton(AF_INET, serverconfig.networkIP.c_str(), &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        throw std::runtime_error("Failed to connect to remote server");
    }

    send(sock, formatted.c_str(), formatted.size(), 0);
    close(sock);
}