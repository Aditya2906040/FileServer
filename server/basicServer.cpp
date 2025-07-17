#include "menu.hpp"
#include "shared/utils.hpp"
#include "file_ops.hpp"
#include <iostream>

using namespace std;

bool esc = false;
char ch;

int main()
{
    Menu::welcome();
    Menu::displayChoiceMenu();

    while (!Menu::isExit(ch))
    {
        ch = Util::my_getch();
        if (Menu::typeCheck(ch))
        {
            continue;
        }

        // main logic here:

        if (ch == '1')
        {
            FileOps::listContent();
        }

        // main logic here:

        if (Menu::isExit(ch))
            break;
        cout << "\nDo you want to continue?(Y/N)\n";
        ch = Util::my_getch();
        if (toupper(ch) == 'N')
            break;
    }

    return 0;
}