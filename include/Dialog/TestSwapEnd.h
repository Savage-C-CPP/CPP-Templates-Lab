#ifndef __TEST_SWAP_END_H__
#define __TEST_SWAP_END_H__

#include "SwapEnd.h"
#include <iostream>
#include <limits>

template <typename T> // Зачем писать 2 одинаковых функции для разных типов, когда можно подставить всё в рантайме
void TestSwapEnd()
{
    std::cout << "Введите длину массива (0 - 15)";
    size_t len = get_i32(0, 15); // 15 enough 1 guess

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

    T *arr = new T[len];
    std::cout << "Заполните массив\n";
    for (size_t i = 0; i < len; ++i)
    {
        std::cout << "arr[" << i << "] ";
        arr[i] = get_i32(min, max);
    }
    std::cout << "Вы ввели массив:\n";
    std::cout << "arr = [ ";
    for (size_t i = 0; i < len; ++i)
    {
        std::cout << arr[i];
        if (i != len - 1)
            std::cout << ", ";
    }
    std::cout << " ]\n";

    // Свапаем, смотрим
    T *new_arr = SwapEnd(arr, len); // вызываем шаблонную функцию с типом T*
    std::cout << "SwapEnd(arr):\n";
    std::cout << "new_arr = [ ";
    for (size_t i = 0; i < len; ++i)
    {
        std::cout << new_arr[i];
        if (i != len - 1)
            std::cout << ", ";
    }
    std::cout << " ]\n";
    return;
}

#endif // __TEST_SWAP_END_H__
