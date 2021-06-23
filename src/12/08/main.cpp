/*!
    \file       main.cpp
    \brief      CTCI (6th Edition), question 12.8: Copy Node

    \details
    Write a method that takes a pointer to a `Node`
    structure as a parameter and returns a complete
    copy of the passed-in data structure. The `Node`
    data structure contains two pointers to other `Node`s.

    \author     Gemuele Aludino
    \date       18 Jun 2021
*/

#include "header.hpp"
#include <iostream>

template <typename T>
ctci6::node<T> ctci6::node<T>::copy_by_addr(ctci6::node<T> *n) {
    return ctci6::node<T>(*n);
}

template <typename T>
using Node = ctci6::node<T>;

/*!
    \brief      Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, otherwise failure (see error code)
*/
int main(int argc, const char *argv[]) {
    std::cout << "Copy Node" << std::endl;
    
    auto n0 = Node<std::string>{"Node n0"};
    auto n1 = Node<std::string>::copy_by_addr(&n0);
    
    auto node_data_equal = &n0.m_data == &n1.m_data;
    assert(node_data_equal == false);

    return EXIT_SUCCESS;
}
