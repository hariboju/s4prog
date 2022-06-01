#pragma once
#include <iostream>

template<typename T>
T get_input()
{
    T input;
    while (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.sync();
        std::cout << "Your input is not valid, try another one please." << std::endl;
    }
    return input;
}