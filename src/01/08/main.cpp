/*!
    \file       main.cpp
    \brief      CTCI (6th Edition), question 1.8: Zero Matrix

    \details
    Write an algorithm such that if an element in an (M x N) matrix is 0, 
    its entire row and column are set to 0.

    \author     TODO
    \date       dd mmm yyyy
*/

#include "header.hpp"

#include <iostream>

namespace ctci6 {

template <typename T, size_t M, size_t N>
std::array<std::array<T, N>, M>
zero_matrix(const std::array<std::array<T, N>, M> &mtx) {
    for (auto i = 0; i < M; ++i) {
        auto found = false;

        for (auto j = 0; j < N; ++j) {
            if (mtx[i][j] == 0) {
                // zero out all elements in row i
                for (auto k = 0; k < N; ++k) {
                    const_cast<T &>(mtx[i][k]) = 0;
                }

                // zero out all elements in column j
                for (auto k = 0; k < M; ++k) {
                    const_cast<T &>(mtx[k][j]) = 0;
                }

                found = true;
                break;
            }
        }

        if (found) { break; }
    }

    return mtx;
}

}

/*!
    \brief      Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, otherwise failure (see error code)
*/
int main(int argc, const char *argv[]) {
    constexpr auto ROW_COUNT = 3;
    constexpr auto COL_COUNT = 4;
    using matrix = ctci6::matrix<int, ROW_COUNT, COL_COUNT>;

    auto mtx = ctci6::zero_matrix(matrix::row_array {
        matrix::row { 1, 2, 3, 4 },
        matrix::row { 5, 6, 0, 8 },
        matrix::row { 9, 10, 11, 12 }
    });

    for (const auto &row : mtx) {
        for (auto element : row) {
            std::cout << element << " ";
        }

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
