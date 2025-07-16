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
    }

    return 0;
}