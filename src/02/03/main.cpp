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

/*!
    \brief      Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, otherwise failure (see error code)
*/
int main(int argc, const char *argv[]) {
    std::cout << "Question 2.3: Delete Middle Node" << std::endl;
    return EXIT_SUCCESS;
}
