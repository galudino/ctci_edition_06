/*!
    \file       main.cpp
    \brief      CTCI (6th Edition), question 12.2: Reverse String

    \details
    Implement a function `void reverse(char *str)` in C or C++
    which reverses a null-terminated string.

    \author     Gemuele Aludino
    \date       18 Jun 2021
*/
#include "header.hpp"

#include <iostream>

namespace ctci6 {

void reverse(char *str);

template <typename BidirectionalIterator>
void reverse(BidirectionalIterator start, BidirectionalIterator finish);

}

template <typename BidirectionalIterator>
void ctci6::reverse(BidirectionalIterator start, BidirectionalIterator finish) {
    // Get the element count by calculating the delta of finish and start
    const auto size = finish - start;

    // Get the mid element address by using start + (size / 2)
    const auto mid = start + (size >> 1);
    
    while (start != mid) {
        // swap(start, --finish);
        auto temp = *start;
        *(start++) = *(--finish);
        *(finish) = temp;
    }
}

/*!
    \brief      Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, otherwise failure (see error code)
*/
int main(int argc, const char *argv[]) {
    char str[] = "abcdef";

    std::cout << "before reverse: " << str << std::endl;
    ctci6::reverse(str);
    std::cout << "after reverse: " << str << std::endl;

    auto cppstr = std::string("abcdef");

    std::cout << "before reverse<std::string>: " << cppstr << std::endl;
    ctci6::reverse(cppstr.begin(), cppstr.end());
    std::cout << "after reverse<std::string>: " << cppstr << std::endl;

    return EXIT_SUCCESS;
}

/*
    0 1 2 3 4 5 6
    a b c d e f \0

    swap elements at curr and last until curr == mid
    mid is (str + (size >> 1)), or (str + (size / 2))

    save tmp at null-terminator position 
    instead of using a dedicated variable.

    a         f         characters to swap.
    a b c d e f a       *(str + size) = *(curr); // save temporary
    f         f         *(curr++) = *(--last); 
    f         a a       *(last) = *(str + size) // use temporary
    f b c d e a a

        b     e          characters to swap.
    f b c d e a b       save temporary
    f e c d e a b       assign e to b's address
    f e c d b a b       assign b to e's former address

        c d             characters to swap.
    f e c d b a c
    f e d d b a c
    f e d c b a c
          c             index 3 reached. stop

                \0      Re-terminate the string: *(str + size) = '\0'
    f e d c b a \0
*/
void ctci6::reverse(char *str) {
    // Save the string size
    const auto size = std::strlen(str);
    
    // Save the address of the mid element
    const auto mid = str + (size >> 1);
     
    // last starts at one-past the last element of str (the null-terminator)
    auto last = (str + size);
    
    // Copy str's address and use to traverse
    auto curr = str;

    while (curr != mid) {
        // *(str + size) is temporary storage for *curr.
        *(str + size) = *(curr);
        
        /*
            Expands to:
            *(curr) = *(last - 1);
            *(last - 1) = *(str + size);
            --last;
         */
        *(curr++) = *(--last);
        *(last) = *(str + size);
    }
    
    // Re-terminate the last character
    *(str + size) = '\0';
}
