/*!
    \file       main.cpp
    \brief      CTCI (6th Edition), question 3.2: Stack Min

    \details
    How would you design a stack which, in addition to push and pop,
    has a function min which return the minimum element? push, pop, and min
    should all operate in O(1) time.

    \author     Gemuele Aludino
    \date       28 Mar 2021
*/

#include "header.hpp"

#include <iostream>
/*!
    \brief      Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, otherwise failure (see error code)
*/
int main(int argc, const char *argv[]) {
    auto s = ctci6::stack_min<int>();

    s.push(3);
    s.push(5);
    s.push(2);
    s.push(1);
    s.push(10);

    // Elements will be popped from smallest to largest.
    while (!s.empty()) {
        auto top = s.min();
        std::cout << top << std::endl;
        s.pop();
    }
    return EXIT_SUCCESS;
}
