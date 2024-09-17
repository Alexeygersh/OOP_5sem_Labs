#pragma once
#include <iostream>
#include <limits>


template <typename T>
T InputNum(T start, T end)
{
    T param;
    (std::cin >> param);
    while (std::cin.fail() || (std::cin.peek() != '\n') || (param < start) || (param > end))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "incorrect number, try again\n";
        (std::cin >> param);
    }
    
    return param;
}