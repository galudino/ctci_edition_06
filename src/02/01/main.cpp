/*!
    \file       main.cpp
    \brief      CTCI (6th Edition), question 2.1: Remove Dups

    \details
    Write code to remove duplicates from an unsorted linked list.

    FOLLOW UP
    How would you solve this problem if a temporary buffer is not allowed?

    \author     Gemuele Aludino
    \date       15 Aug 2020
*/

#include "header.hpp"

#include <iostream>

/*!
    function 
    remove_duplicates(n: node) {
        var current: node = n

        while current not null {
            if current.next == null {
                break;
            }
            
            var compare: node = current.next
            var trail: node = compare

            while compare not null {
                if current.data == compare.data {
                    var victim: node = trail.next
                    trail.next = victim.next
                    delete victim

                    compare = trail.next
                } else {
                    trail = compare
                    compare = compare.next
                }
            }

            current = current.next
         } 
    }
*/
template <typename T>
void ctci6::forward_list<T>::remove_duplicates(ctci6::forward_list<T> &l) {
    // Retrieve an iterator to the beginning of the list (the first node)
    // Equivalent to retrieving the head (or any entry point) of the list.
    auto current = l.begin();

    // For all nodes in the list...
    // (while curr != null)
    while (current != l.end()) {
        // This will terminate the loop
        // if the iterator is on the last element, or node.
        // (if curr->m_next == null) break;
        if (!current.m_next().m_curr) {
            break; 
        }
    
        auto compare = current; // comparison node
        auto trail = compare;   // trails behind comparison node.
                                // will facilitate deletion.
        
        ++compare;              // Now compare is ahead of trail.
        
        // For all nodes after current...
        // (while comp != null)
        while (compare != l.end()) {
            // If curr->data == compare->data
            if (*current == *compare) {
                // trail is behind compare;
                // we use trail to erase compare.
                // compare is assigned to its link, thereby advancing it.
                compare = l.erase_after(trail);
            } else {
                // If curr->m_data != compare->m_data,
                // assign the current value of compare to trail,
                // then increment compare. (trail remains behind compare)
                trail = compare++;
            }
        }
        
        ++current;
    }
}

#include <iostream>

/*!
    \brief      Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, otherwise failure (see error code)
*/
int main(int argc, const char *argv[]) {
    auto list = ctci6::forward_list<int>{ 3, 3, 3, 1, 2, 5, 3, 4, 5 };
    std::cout << "Before: " << list << std::endl;
    
    ctci6::forward_list<int>::remove_duplicates(list);
    std::cout << "After:  " << list << std::endl;

    return EXIT_SUCCESS;
}

