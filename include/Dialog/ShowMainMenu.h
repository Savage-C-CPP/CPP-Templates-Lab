#ifndef __SHOW_MAIN_MENU_H__
#define __SHOW_MAIN_MENU_H__

#include "MainMenu.h"
#include <iostream>

void ShowMainMenu()
{
    while (true)
    {
        system("clear");
        std::cout << "\t-----Главное меню-----\n";
        for (size_t i = 0; i < MainMenu_quantity; ++i)
            std::cout << MainMenu[i].title << "\n";

        int choice;
        choice = get_i32(1, MainMenu_quantity);
        for (size_t i = 0; i < MainMenu_quantity; ++i)
        {
            if (choice == MainMenu[i].choice)
            {
                Delegate procedure = MainMenu[i].procedure;
                (procedure)();
                break;
            }
        }
        pause();
    }
}

#endif // __SHOW_MAIN_MENU_H__
