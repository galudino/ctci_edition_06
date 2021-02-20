/*!
    \file       main.cpp
    \brief      CTCI (6th Edition), question 2.5: Sum Lists

    \details
    You have two numbers represented by a linked list, where each node contains a single digit. i
    The digits are stored in reverse order, such that the 1's digit is at the head of the list.
    Write a function that adds the two numbers and returns the sum as a linked list.

    EXAMPLE
    Input:  (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
    Output: (2 -> 1 -> 9). That is, 912.

    FOLLOW UP:
    Suppose the digits are stored in forward order. Repeat the above problem.
    
    EXAMPLE
    Input:  (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
    Output: (9 -> 1 -> 2). That is, 912.

    \author     Gemuele Aludino
    \date       19 Feb 2021
*/

#include "header.hpp"

#include <iostream>
#include <forward_list>
#include <cmath>

template <typename T, typename Alloc = std::allocator<T>>
std::ostream &operator<<(std::ostream &os, 
                         const typename std::forward_list<T, Alloc> &l);

namespace ctci6 {

template <typename T, typename Alloc = std::allocator<T>>
typename std::forward_list<T, Alloc> sum_lists(const typename std::forward_list<T, Alloc> &x, 
                                               const typename std::forward_list<T, Alloc> &y);

template <typename T, typename Alloc = std::allocator<T>>
typename std::forward_list<T, Alloc> sum_lists_forward(const typename std::forward_list<T, Alloc> &x, 
                                                       const typename std::forward_list<T, Alloc> &y,
                                                       size_t place_value_count = 0);
}

/*!
    \brief      Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, otherwise failure (see error code)
*/
int main(int argc, const char *argv[]) {
    auto list_a = std::forward_list<int> { 7, 1, 6 };
    auto list_b = std::forward_list<int> { 5, 9, 2 };
    
    std::cout << list_a << " + " << list_b << " = " << ctci6::sum_lists(list_a, list_b)
    << " (617 + 295 = 912)" << std::endl;

    auto list_c = std::forward_list<int> { 6, 1, 7 };
    auto list_d = std::forward_list<int> { 2, 9, 5 };

    // Two ways to solve this if the lists are not reversed:
    // 0) If the place value count is not known,
    //    invoke sum_lists_forward(list_c, list_d).
    //    This will reverse list_c and list_c, and call sum_lists().
    // 1) If the place value count is known,
    //    invoke sum_lists_forward(list_c, list_d, place_value_count)
    //
    //  If, for instance, the place value count of your forward-listed input is unknown,
    //  you must decide if it is more performant to
    //      - have the lists reversed so sum_lists can be invoked
    //      - iterate over the lists to determine what the place value count is (the size(s) of the lists)

    std::cout << list_c << " + " << list_b << " = " << ctci6::sum_lists_forward(list_c, list_d)
    << " (617 + 295 = 912)" << std::endl;

    std::cout << list_c << " + " << list_b << " = " << ctci6::sum_lists_forward(list_c, list_d, 3)
    << " (617 + 295 = 912)" << std::endl;

    return EXIT_SUCCESS;
}

template <typename T, typename Alloc>
std::ostream &operator<<(std::ostream &os, 
                         const typename std::forward_list<T, Alloc> &l) {
    os << "{ ";

    for (auto n : l) {
        os << n << " ";
    }

    os << "}";

    return os;
}

template <typename T, typename Alloc>
typename std::forward_list<T, Alloc> ctci6::sum_lists(const typename std::forward_list<T, Alloc> &x, 
                                                      const typename std::forward_list<T, Alloc> &y) {
    
    // list is given in reverse order. 
    // e.g. list parameter is given as 3, 2, 1, correct parameter to be 1, 2, 3

    // Results are undefined if x and y have different sizes
    // (it is still possible to add numbers of differing place value, just provide the padding zeroes)

    auto it_x = x.begin();
    auto it_y = y.begin();

    auto collect_list = typename std::forward_list<T, Alloc>();

    auto c = 1;

    // Example: 
    // if list x is { 5, 4, 1 }, which represents 145,
    // and list y is { 6, 3, 2 }, which represents 236,
    // We iterate over x and y, and create a new list:
    //  { 1 * (5 + 6), 10 * (4 + 3), 100 * (1 + 2) }
    //  { 11, 70, 300 }
    while (it_x != x.end() && it_y != y.end()) {
        auto xval = it_x == x.end() ? 0 : *it_x;
        auto yval = it_y == y.end() ? 0 : *it_y;

        collect_list.push_front(c * (xval + yval));

        ++it_x;
        ++it_y;

        c *= 10;
    }

    auto sum = 0; 

    for (auto n : collect_list) {
        // Add all elements in collect_list, store in sum.
        sum += n;
    }

    // Convert sum to a string we can iterate over.
    // sum_as_str is composed of char, [0, 9].
    auto sum_as_str = std::to_string(sum);

    auto sum_as_list = typename std::forward_list<T, Alloc>();

    for (auto ch : sum_as_str) {
        // [0, 9] have ascii values of [48, 57].
        // By computing (int)(ch) - 48,
        // we have the desired decimal int we want to push.
        sum_as_list.push_front(static_cast<T>(ch) - 48);
    }

    return sum_as_list;
}

template <typename T, typename Alloc>
typename std::forward_list<T, Alloc> ctci6::sum_lists_forward(const typename std::forward_list<T, Alloc> &x, 
                                                              const typename std::forward_list<T, Alloc> &y,
                                                              size_t place_value_count) {
    auto sum_as_list = std::forward_list<T, Alloc>();

    if (place_value_count == 0) {
        auto X = std::forward_list<T, Alloc>(x);
        auto Y = std::forward_list<T, Alloc>(y);
    
        X.reverse();
        Y.reverse();

        sum_as_list = sum_lists(X, Y);
    } else {
        auto it_x = x.begin();
        auto it_y = y.begin();

        auto collect_list = std::forward_list<T, Alloc>();
        auto it = collect_list.before_begin();

        auto c = std::pow(10, place_value_count - 1);

        while (it_x != x.end() && it_y != y.end()) {
            auto xval = it_x == x.end() ? 0 : *it_x;
            auto yval = it_y == y.end() ? 0 : *it_y;

            it = collect_list.insert_after(it, c * (xval + yval));

            ++it_x;
            ++it_y;
        
            c /= 10;
        }

        auto sum = 0;

        for (auto n : collect_list) {
            sum += n;
        }

        auto sum_as_str = std::to_string(sum);
        it = sum_as_list.before_begin();

        for (auto ch : sum_as_str) {
            sum_as_list.insert_after(it, static_cast<int>(ch) - 48);
        }
    }

    return sum_as_list;
}
