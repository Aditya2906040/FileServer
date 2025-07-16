#include <iostream>
#include <termios.h>
#include <unistd.h>

char getHiddenChar()
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

int main()
{
    std::cout << "Press any key (input will be hidden, no Enter needed): ";

    char c = getHiddenChar();

    std::cout << "\nYou pressed: " << c << std::endl;

    return 0;
}
