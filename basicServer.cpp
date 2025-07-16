#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

bool esc = false;
char ch;
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
    cout << "Welcome to File Server, you have been connected successfully" << endl;
    while (!esc)
    {
        cout << "1. List files\n2. Download files\n3. Upload files\n4. Exit" << endl;
        // cin >> ch;
        ch = getHiddenChar();
        if (ch != '1' && ch != '2' && ch != '3' && ch != '4')
        {
            cout << "Choose correct input." << endl;
            continue;
        }
        if (ch == '4')
            esc = true;
    }

    return 0;
}