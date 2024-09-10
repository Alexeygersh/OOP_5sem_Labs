#pragma once
#include <iostream>
#include <limits>


template <typename T>
T InputNum(T start, T end)
{
    T param;
    while (!(std::cin >> param) || (std::cin.peek() != '\n') || (param < start) || (param > end))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (param < start) {
            std::cout << "number is less than expected, try again\n";
        }
        else if (param > end) {
            std::cout << "number is higher than expected, try again\n";
        }
        else {

            std::cout << "incorrect number, try again\n";
        }
        
    }
    //std::cerr << param << "\n";
    return param;
}