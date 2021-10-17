//
// EPITECH PROJECT, 2018
// 207demography
// File description:
// main
//

#include <iostream>
#include <string.h>
#include "demograph.hpp"

int main(int const _ac, arr_const_restrict _av)
{
    if (_ac == 1) uraise("Invalid number of argument");
    for (int i = 0; _ac > i; ++i)
        for (int n = 0; _ac > n; n++)
            if (strcmp(_av[i], _av[n]) == 0 && i != n) uraise("2 times the same country");
    Demograph demo(_ac, _av);
    try {
        demo.run();
    } catch (std::overflow_error& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}