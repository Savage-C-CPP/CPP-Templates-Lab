#ifndef __TEST_MY_QUEUE_H__
#define __TEST_MY_QUEUE_H__

#include "MyQueue.h"
#include <limits>

template <typename T>
void TestMyQueue()
{
    MyQueue<T> q;
    std::cout << "1. Push()\n";
    std::cout << "2. Pop()\n";
    std::cout << "3. Print()\n";
    std::cout << "4. Назад\n";

    char choice = get_i32(1, 4);
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            long min, max;
            if (typeid(T) == typeid(int))
            {
                min = INT32_MIN;
                max = INT32_MAX;
            }
            else if (typeid(T) == typeid(long))
            {
                min = INT64_MIN;
                max = INT64_MAX;
            }

            std::cout << "Push()";
            q.Push(get_i32(min, max));
            break;

        case 2:
            if (!q.Empty())
                q.Pop();
            else
                std::cout << "Нельзя вызвать Pop() так как очередь пуста!\n";
            break;

        case 3:
            q.Print();
            break;
        }
        pause();
        system("clear");
        std::cout << "1. Push()\n";
        std::cout << "2. Pop()\n";
        std::cout << "3. Print()\n";
        std::cout << "4. Назад\n";
        choice = get_i32(1, 4);
    }
    return;
}

#endif // __TEST_MY_QUEUE_H__
