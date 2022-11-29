#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "DialogMenu.h"
#include "TestSwapEnd.h"
#include "TestMyQueue.h"
#include "Exit.h"

void TestSwapEnd();
void TestMyQueue();
void Exit();

static MenuEntry MainMenu[] =
{
    {1, "1. SwapEnd(int arr[])", TestSwapEnd<int>},
    {2, "2. SwapEnd(long arr[])", TestSwapEnd<long>},
    {3, "3. MyQueue<int>", TestMyQueue<int>},
    {4, "4. MyQueue<long>", TestMyQueue<long>},
    {5, "5. Выход", Exit},
};

static const size_t MainMenu_quantity =
    sizeof(MainMenu) / sizeof(MainMenu[0]);

#endif // __MAIN_MENU_H__
