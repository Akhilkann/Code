#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fstream>

int main() {
    const int PORT = 8080; // Use the same port as in config.networkPort
    const int BUFFER_SIZE = 1024;

    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind to the specified port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Log receiver started on port " << PORT << "...\n";

    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address,
                                 (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        int bytesRead = read(new_socket, buffer, BUFFER_SIZE - 1);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0'; // Null-terminate the received data
            std::cout << "Received log: " << buffer << std::endl;

            try{
            std::ofstream file("serverLog.log", std::ios::app);
            if (!file.is_open()) {
            throw std::runtime_error("Failed to open log file: serverLog.log\n");
            }
            file << buffer << std::endl;
            file.close();
            }catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            }
        }

        close(new_socket);
    }

    close(server_fd);
    return 0;
}
