/*!
    \file       main.cpp
    \brief      CTCI (6th Edition), question 2.2: Return Kth to Last

    \details
    Implement an algorithm to find the kth to last element of a singly linked list.

    \author     Gemuele Aludino
    \date       11 Feb 2021
*/

#include "header.hpp"

#include <iostream>
#include <forward_list>

namespace ctci6 {
template <typename T> T &kth_to_last(std::forward_list<T> &l, int64_t k);
}

/*!
    \brief      Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, otherwise failure (see error code)
*/
int main(int argc, const char *argv[]) {
    auto list = std::forward_list<std::string> {  
        "alpha", "beta", "charlie", "delta", 
        "echo", "foxtrot", "kilo" 
    };
    
    std::cout << "{ ";
    for (auto &str : list) {
        std::cout << str << " ";
    }
    std::cout << "}" << std::endl;

    constexpr auto K = 3;
    
    std::cout << "Expected:            " << "echo\n"
              << "Kth to last (k = " << K << "): " << ctci6::kth_to_last(list, K) << std::endl;

    return EXIT_SUCCESS;
}

template <typename T>
T &ctci6::kth_to_last(std::forward_list<T> &l, int64_t k) {
    auto it = l.begin();
    auto last = it;

    for (auto i = 0; i < k; ++i) {
        ++last;
    }

    while (last != l.end()) {
        ++it;
        ++last;
    }
    
    return *it;
}
