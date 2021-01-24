/*!
    \file       main.cpp
    \brief      CTCI (6th Edition), question 2.3: Delete Middle Node

    \details
    Implement an algorithm to delete a node in the middle 
    (i.e. any node but the first and the last node, 
    not necessarily the exact middle) of a singly linked list, 
    given only access to that node.

    EXAMPLE
    Input: the node c from the linked list 
        a->b->c->d->e->f

    Result: nothing is returned, 
    but the new linked list looks like 
        a->b->d->e->f

    \author     Gemuele Aludino
    \date       23 Jan 2021
*/

#include "header.hpp"

#include <iostream>
#include <forward_list>

/*!
    \brief      Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, otherwise failure (see error code)
*/
int main(int argc, const char *argv[]) {
    auto list = ctci6::forward_list<char>{ 'a', 'b', 'c', 'd', 'e', 'f' };

    // Retrieve an iterator to the position before the first element.
    // Advance it two elements over, so we land on index 1.
    // (node of the second element)
    auto it = list.before_begin() + 2;
    std::cout << "Element at position: " << *it << std::endl;

    std::cout << "Before erase_after: " << std::endl;
    std::cout << list << std::endl; 

    // We want to erase the node containing 'c',
    // which at index 2, the third element.
    // Therefore, we provide an iterator to the second element,
    // so it can be linked with c's link, 'd'. (index 3, the fourth element).
    it = list.erase_after(it);

    std::cout << "After erase_after: " << std::endl;
    std::cout << list << std::endl;
    
    return EXIT_SUCCESS;
}
