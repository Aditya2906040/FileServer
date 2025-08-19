#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

#define PORT 8080

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Socket creation error");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("Invalid address/ Address not supported");
        return 1;
    }

    // Connect
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Connection Failed");
        return 1;
    }
    // int i = 5;
    // while (i-- > 0)
    // {
    //     // const char *hello = "Hello from client!";
    //     string msg;
    //     // cin.getline(msg);
    //     getline(cin, msg);
    //     send(sock, msg.c_str(), msg.length(), 0);
    //     read(sock, buffer, 1024);
    //     cout << "Server replied: " << buffer << endl;
    //     memset(buffer, '\0', strlen(buffer));
    // }

    // get the welcome message and the menu

    read(sock, buffer, 1024);
    cout << buffer << endl;
    memset(buffer, '\0', sizeof(buffer));

    read(sock, buffer, 1024);
    cout << buffer << endl;
    memset(buffer, '\0', sizeof(buffer));

    string cmd;
    cout << "Enter command: ";
    // getline(cin, cmd);
    cin >> cmd;
    // cout << "Sending: " << cmd << endl;
    send(sock, cmd.c_str(), cmd.length(), 0);

    cout << "Exiting bye...";
    close(sock);
    return 0;
}
