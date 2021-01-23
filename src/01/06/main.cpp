/*!
    \file       main.hpp
    \brief      CTCI (6th Edition), question 1.6: String Compression

    \details
    Implement a method to perform basic string compression using the counts of repeated characters. 
    For example, the string aabcccccaaa would become a2b1c5a3.
    If the "compressed" string would not become smaller than the original string, 
    your method should return the original string. 
    You can assume the string has only uppercase and lowercase letters (a - z).

    \author     Gemuele Aludino
    \date       22 Jan 2021
*/

#include "header.hpp"

#include <iostream>

std::string compress_string(const std::string &s);

/*!
    \brief      Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, otherwise failure (see error code)
*/
int main(int argc, const char *argv[]) {
    auto str = std::string("aabcccccccccccaaa");

    std::cout << "Return new compressed string: " << std::endl;
    std::cout << "Original:\t" << str << 
    "\nCompressed:\t" << compress_string(str)
    << "\nExpected:\t" << "a2b1c11a3" << std::endl;
    
    return EXIT_SUCCESS;
}

std::string compress_string(const std::string &s) {
    // End result buffer for the compressed version of s.
    auto result = std::string(); 

    auto i = 0;
    while (i < s.size()) {
        // The current character will begin with a count of 1.
        const auto current_char = s[i];
        auto count = 1;

        for (auto j = i + 1; j < s.size(); ++j) {
            const auto comparison_char = s[j];

            // We compare current_char with every other char
            // after it until we reach a different character.
            // Every time current_char == comparison_char,
            // the count increments by 1.
            if (current_char == comparison_char) {
                ++count;
            } else {
                break;
            }
        }

        // Append the current character and its count (as a string)
        // to our result buffer.
        result += (current_char + std::to_string(count));

        // The current position, i, will advance by count characters. 
        i += count;
    }

    return result;
}
