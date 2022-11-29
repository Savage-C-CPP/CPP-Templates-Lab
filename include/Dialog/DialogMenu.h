#ifndef __DIALOG_MENU_H__
#define __DIALOG_MENU_H__

#include <iostream>
#include <limits>

typedef void (*Delegate)();

struct MenuEntry
{
    int choice;
    char const *title;
    Delegate procedure;
};

long get_i32(long min, long max)
{
    bool done = false;
    long choice;
    while (!done)
    {
        std::cout << "> ";
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некоректный ввод. Попробуйте снова!\n";
            continue;
        }
        else if (choice < min || choice > max)
            std::cout << "Некоректный ввод. Попробуйте снова!\n";
        else
            done = true;
    }
    return choice;
}

void pause() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Нажмите Enter чтобы продолжить...";
    std::cin.get();
}

#endif //__DIALOG_MENU_H__
