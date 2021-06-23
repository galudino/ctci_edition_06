/*!
    \file       header.hpp
    \brief      Header file for CTCI (6th Edition), question 12.8: Copy Node

    \details
    Write a method that takes a pointer to a `Node` structure
    as a parameter and returns a complete copy of the
    passed-in data structure. The `Node` data structure
    contains two pointers to other `Node`s. 

    \author     Gemuele Aludino
    \date       18 Jun 2021
*/

#ifndef HEADER_HPP
#define HEADER_HPP

#include <cstddef> // std::size_t
#include <iostream>

namespace ctci6 {

template <typename T>
struct node;

}

template <typename T>
struct ctci6::node {
    using Self = node;

    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using const_reference = const T &;

    using size_type = std::size_t;

    static Self copy_by_addr(Self *n);

    value_type m_data;

    Self *m_next = nullptr;
    Self *m_prev = nullptr;
};


#endif /* HEADER_HPP */

