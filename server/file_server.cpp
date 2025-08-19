#include "server.hpp"
#include "client_handler.hpp"
#include "utils.hpp"
#include <iostream>

#define port 8080
using namespace std;

int main()
{
    if (!Server::start(port))
    {
        cout << "Connection failed";
        return 1;
    }

    cout << "Connection successful";
    int client_sock = Server::getCSock();
    int server_sock = Server::getSSock();
    Handler::handleClient(client_sock, server_sock);

    // now parsing the commands
    string ans = Util::parseCommand(cmd);

    return 0;
}