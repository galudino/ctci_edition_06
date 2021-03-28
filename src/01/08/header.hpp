/*!
    \file       header.hpp
    \brief      Header file for CTCI (6th Edition), question 1.8: Zero Matrix

    \details
    Write an algorithm such that if an element in an (M x N) matrix is 0, 
    its entire row and column are set to 0.

    \author     TODO
    \date       dd mmm yyyy
*/

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <array>
#include <memory>

namespace ctci6 {

template <typename T, size_t M, size_t N = M>
class matrix;

template <typename T, size_t M, size_t N>
std::ostream &operator<<(std::ostream &os, const matrix<T, M, N> &m);

template <typename T, size_t M, size_t N>
class matrix {
public:
    static constexpr auto rowsz = M;
    static constexpr auto colsz = N;

    using row = std::array<T, colsz>;
    using row_reference = std::array<T, colsz> &;
    using row_const_reference = const std::array<T, colsz> &;

    using row_iterator = typename row::iterator;
    using row_const_iterator = typename row::const_iterator;

    using value_type = typename row::value_type;
    using reference = typename row::reference;
    using const_reference = typename row::const_reference;

    using row_array = std::array<row, M>;
    using row_array_reference = std::array<row, M> &;
    using row_array_const_reference = const std::array<row, M> &;

    using row_array_iterator = typename row_array::iterator;
    using row_array_const_iterator = typename row_array::const_iterator;

    matrix(row_array_const_reference row_arr) : m_impl(row_arr) { }
    
    matrix(const std::array<std::initializer_list<value_type>, rowsz> &arr_list) {
        for (auto &row : *this) {
            std::copy(arr_list.begin(), arr_list.end(), row.begin());
        }
    }
    
    row_iterator begin() { return m_impl.begin(); }
    row_iterator end() { return m_impl.end(); }
    row_const_iterator begin() const { return m_impl.begin(); }
    row_const_iterator end() const { return m_impl.end(); }

    size_t row_size() const { return m_impl.size(); }
    size_t col_size() const { return m_impl[0].size(); }

    row_reference operator[](int index) {
        return m_impl[index];
    }

    friend std::ostream &operator<< <>(std::ostream &os, const matrix &m);

private:
    row_array m_impl;   // array<array<T, N>, M>
                        // array<array<value_type, col_size>, row_size>
};

template <typename T, size_t M, size_t N>
std::ostream &operator<<(std::ostream &os, const matrix<T, M, N> &m) {
    for (const auto &row : m) {
        for (const auto &element : row) {
            os << element << " ";
        }

        os << std::endl;
    }
    return os;
}

}

#endif /* HEADER_HPP */
