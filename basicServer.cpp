#include "menu.hpp"
#include <iostream>

using namespace std;

bool esc = false;
char ch;

int main()
{
    Menu::welcome();
    Menu::displayChoiceMenu();

    while (!Menu::isesc(ch))
    {
        ch = Menu::my_getch();
        Menu::typeCheck(ch);

        // main logic here:

        // main logic here:

        cout << "Do you want to continue?(Y/N)\n";
        cin >> ch;
        // if (toupper(ch) == 'N')
        //     break;
    }

    return 0;
}