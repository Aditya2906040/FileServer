#pragma once

#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

namespace Menu
{

    string welcome()
    {
        // cout << "------------------------------------------\n";
        // cout << "Welcome to The SockIt FileServer\n";
        // cout << "------------------------------------------\n";
        return "------------------------------------------\nWelcome to The SockIt FileServer\n------------------------------------------\n";
    }

    string displayChoiceMenu()
    {
        // cout << "1. List files\n2. Download files\n3. Upload files\n4. Exit" << endl;
        // cout << "The commands and their formats are: ";
        // cout << "\n   LIST\n";
        // cout << "   DOWNLOAD <filename/directory_name>\n";
        // cout << "   UPLOAD <filename/directory_name>\n";
        // cout << "   EXIT\n";

        return "The commands and their formats are: \n   LIST\n   DOWNLOAD <filename/directory_name>\n   UPLOAD <filename/directory_name>\n   EXIT\n";
    }

    bool typeCheck(char ch)
    {
        if (ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != 27)
        {
            return true;
        }
        return false;
    }

    bool isExit(char ch)
    {
        if (ch == 27 || ch == '4')
        {
            cout << "Exiting bye...\n";
            return true;
        }
        return false;
    }
}
