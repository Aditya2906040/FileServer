#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

namespace Util
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
}