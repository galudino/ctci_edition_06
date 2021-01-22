/*!
    \file       main.cpp
    \brief      CTCI (6th Edition), question 1.1: Is Unique

    \details
    Implement an algorithm to determine if a string has all unique characters.
    What if you cannot use additional data structures?

    \author     Gemuele Aludino
    \date       21 Jan 2021
*/

#include "header.hpp"

#include <iostream>
#include <vector>
#include <bitset>

bool has_unique_chars(const std::string &str, std::vector<bool> &v);
bool has_unique_chars(const std::string &str, std::bitset<256> &bs);
bool has_unique_chars(const std::string &str);

/*!
    \brief      Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, otherwise failure (see error code)
*/
int main(int argc, const char *argv[]) {
    auto strings = {
        "pop",
        "onetwothreefour",
        "asdfjkl;",
        "niNety",
        "abBcX"
    };

    // Decimal ascii values range from [0, 128)
    auto v = std::vector<bool>(128);
    
    std::cout << "Using std::vector<bool>(128): " << std::endl;
    for (auto &s : strings) {
        std::cout << s << " -> " << std::boolalpha << has_unique_chars(s, v) << std::endl;
    }

    std::cout << std::endl;

    // A char is an 1 byte (8-bit) integer 
    auto bs = std::bitset<256>();

    // Save space by using std::bitset<256>() as opposed to std::vector<bool>(128).
    std::cout << "Using std::bitset<256>: " << std::endl;
    for (auto &s : strings) {
        std::cout << s << " -> " << std::boolalpha << has_unique_chars(s, bs) << std::endl;
    }

    std::cout << std::endl;

    std::cout << "No data structure: " << std::endl;
    for (auto &s : strings) {
        std::cout << s << " -> " << std::boolalpha << has_unique_chars(s) << std::endl;
    }

    return EXIT_SUCCESS;
}

/*!
    \brief      Determines if str is a string of all unique characters
    \details    Uses std::vector<bool>(128)   
    
    \param[in]  str     The string to assess
    \param[in]  v       Determines if a character has occurred more than once in str

    \return             true, if str has all unique characters, false otherwise
 */
bool has_unique_chars(const std::string &str, std::vector<bool> &v) {
    // We must reset the vector each time we run this function,
    // since v will be reused. All elements assigned to be false, or 0.
    v.assign(v.size(), false);

    // Save the character count.
    auto size = str.size();

    for (auto i = 0; i < size; ++i) {
        if (v[str[i]]) {
            // if v at index str[i] == true
            return false;
        } else {
            v[str[i]] = true;
        }
    }

    return true;
}

/*!
    \brief      Determines if str is a string of all unique characters
    \details    Optimized method using std::bitset<256>          
    
    \param[in]  str     The string to assess
    \param[in]  bs      Determines if a character has occurred more than once in str

    \return             true, if str has all unique characters, false otherwise
 */
bool has_unique_chars(const std::string &str, std::bitset<256> &bs) {
    // We must reset the bitset each time we run this function,
    // since bs will be reused. All bits set to 0.
    bs.reset();

    // Save the character count.
    auto size = str.size();

    for (auto i = 0; i < size; ++i) {
        if (bs[str[i]]) {
            // if bs at index str[i] == true
            return false;
        } else {
            // bs.set(str[i], true) also works here.
            bs[str[i]] = true;
        }
    }
    
    return true;
}

/*!
    \brief              Determines if str is a string of all unique characters
    \details            Brute force method using nested loops.
    \param[in]  str     The string to assess
    \return             true, if str has all unique characters, false otherwise 
 */
bool has_unique_chars(const std::string &str) {
    // Save the character count.
    const auto size = str.size();

    // The outer loop begins at i = 0;
    // our current character is str[i].
    for (auto i = 0; i < size - 1; ++i) {
        // The inner loop begins at j = 1;
        // our comparison character is str[j].
        for (auto j = i + 1; j < size; ++j) {
            // str[i] is compared with every other char after it.
            if (str[i] == str[j]) {
                // If the current character and comparison character
                // are matched, we stop immediately and return false.
                return false;
            }
        }
    }

    // Once we get this far, we know that str
    // is composed of all unique chars.
    return true;
}
