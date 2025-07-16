#pragma once

#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

namespace Menu
{
    char my_getch()
    {
        struct termios oldt, newt;
        char ch;

        // Get current terminal settings
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;

        // Disable canonical mode and echo
        newt.c_lflag &= ~(ICANON | ECHO);

        // Apply new settings immediately
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        // Read one character
        ch = getchar();

        // Restore old settings
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        return ch;
    }

    void welcome()
    {
        cout << "------------------------------------------\n";
        cout << "Welcome to The SockIt FileServer\n";
        cout << "------------------------------------------\n";
    }

    void displayChoiceMenu()
    {
        cout << "1. List files\n2. Download files\n3. Upload files\n4. Exit" << endl;
    }

    bool typeCheck(char ch)
    {
        if (ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != 27)
        {
            cout << "Choose correct input." << endl;
            return true;
        }
        return false;
    }

    bool isesc(char ch)
    {
        if (ch == 27 || toupper(ch) == 'N')
        {
            cout << "Exiting bye...";
            return true;
        }
        return false;
    }
}
