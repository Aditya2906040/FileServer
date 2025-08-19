#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include "menu.hpp"

using namespace std;

namespace Handler
{
    void handleClient(int client_sock, int server_sock)
    {
        char buffer[1024] = {0};
        int i = 5;
        // while (i-- > 0)
        // {
        //     ssize_t bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
        //     if (bytes_received > 0)
        //     {
        //         cout << "Client says: " << string(buffer, bytes_received) << endl;
        //     }
        //     else
        //     {
        //         cerr << "Failed to receive data or connection closed. This msg is from client handler\n";
        //     }
        //     memset(buffer, '\0', sizeof(buffer));

        //     string resp;
        //     cout << "Enter your message: ";
        //     // cin >> resp;
        //     getline(cin, resp);
        //     // const char *response = "Hello from server!";
        //     send(client_sock, resp.c_str(), resp.length(), 0);
        // }

        // send the welcome and menu messages:
        string welcome = Menu::welcome();
        send(client_sock, welcome.c_str(), welcome.length(), 0);
        cout << "\nSent first packet.\n";

        string menu = Menu::displayChoiceMenu();
        send(client_sock, menu.c_str(), menu.length(), 0);
        cout << "\nSent second packet.\n";

        ssize_t bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);

        if (bytes_received > 0)
        {
            cout << buffer;
            // string cmd;
            // strcpy(cmd.c_str(), buffer);
            //  Util::parseCommand(buffer);

            memset(buffer, '\0', sizeof(buffer));
        }
        else
        {
            cerr << "------------------\nFailed to receive data or connection closed. This msg is from client handler\n------------------\n";
        }

        cout << "Exiting bye...";
        close(client_sock);
        close(server_sock);
    }
}