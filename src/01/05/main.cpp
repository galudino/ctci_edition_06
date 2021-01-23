/*!
    \file       main.hpp
    \brief      CTCI (6th Edition), question 1.5: One Away

    \details
    There are three types of edits that can be performed on strings: 
    insert a character, remove a character, or replace a character.

    Given two strings, 
    write a function to check if they are one edit (or zero edits) away.

    EXAMPLE

    pale,  ple  -> true
    pales, pale -> true
    pale,  bale -> true
    pale,  bake -> false

    \author     TODO
    \date       dd mmm yyyy
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
    std::cout << "Question 1.5: One Away" << std::endl;
    return EXIT_SUCCESS;
}
