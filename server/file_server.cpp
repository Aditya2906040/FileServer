#include "server.hpp"
#include <iostream>

#define port 8080
using namespace std;

int main()
{
    if (Server::start(port))
        cout << "Connection successful";
    else
        cout << "Connection failed";

    return 0;
}