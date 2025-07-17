#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

using namespace std;

namespace Server
{
    int createSocket()
    {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            perror("Socket creation failed");
        return sockfd;
    }

    bool bindSocket(int sockfd, uint16_t port)
    {
        sockaddr_in address{};
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(port);

        if (bind(sockfd, (sockaddr *)&address, sizeof(address)) < 0)
        {
            perror("Bind failed");
            return false;
        }
        return true;
    }

    bool listenForConnection(int sockfd)
    {
        if (listen(sockfd, 1) < 0)
        {
            perror("Listen failed");
            return false;
        }
        return true;
    }

    int acceptClient(int sockfd)
    {
        sockaddr_in client_addr{};
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sockfd, (sockaddr *)&client_addr, &client_len);
        if (client_sock < 0)
            perror("Accept failed");
        return client_sock;
    }

    void handleClient(int client_sock)
    {
        char buffer[1024] = {0};
        ssize_t bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
        if (bytes_received > 0)
        {
            cout << "Client says: " << string(buffer, bytes_received) << endl;
        }
        else
        {
            cerr << "Failed to receive data or connection closed.\n";
        }

        const char *response = "Hello from server!";
        send(client_sock, response, strlen(response), 0);
    }

    bool start(uint16_t port)
    {
        int server_sock = createSocket();
        if (server_sock < 0)
            return false;

        if (!bindSocket(server_sock, port))
        {
            close(server_sock);
            return false;
        }

        if (!listenForConnection(server_sock))
        {
            close(server_sock);
            return false;
        }

        cout << "Server listening on port " << port << "...\n";

        int client_sock = acceptClient(server_sock);
        if (client_sock < 0)
        {
            close(server_sock);
            return false;
        }

        handleClient(client_sock);

        close(client_sock);
        close(server_sock);
        return true;
    }
}
