/*!
    \file       header.hpp
    \brief      CTCI (6th Edition), question 3.2: Stack Min

    \details
    How would you design a stack which, in addition to push and pop,
    has a function min which return the minimum element? push, pop, and min
    should all operate in O(1) time.

    \author     Gemuele Aludino
    \date       28 Mar 2021
*/

#ifndef HEADER_HPP
#define HEADER_HPP

#include <stack>

namespace ctci6 {

template <typename T>
class stack_min {
public:
    void push(const T &val);
    void pop();
    T &min() { return m_impl.top(); }
    const T &min() const { return m_impl.top(); }
    bool empty() const { return m_impl.empty(); }
private:
    std::stack<T> m_impl;
};

template <typename T>
void stack_min<T>::push(const T &val) {
    // If stack is empty, just push val.
    if (m_impl.empty()) {
        m_impl.push(val);
    // Otherwise...
    } else {
        // Save the current top.
        auto top = m_impl.top();

        // Compare val and top.
        // If val is smaller than top...
        if (val < top) {
            // ...push it to the stack.
            m_impl.push(val);
        } else {
            m_impl.pop();       // Pop the current top for now.
            m_impl.push(val);   // Push val on to the stack.
            m_impl.push(top);   // Push top back on to the stack.
            // This ensures that val remains under top.
        }
    }
}

template <typename T>
void stack_min<T>::pop() {
    if (!this->empty()) {
        m_impl.pop();

        // If the statement above didn't pop the last elem... 
        if (!this->empty()) {
            // Save the current top. Pop it off.
            auto top = m_impl.top();
            m_impl.pop();

            // If the statement above didn't pop the last elem...
            if (!this->empty()) {
                // Save the current top. Pop it off.
                auto next_top = m_impl.top();
                m_impl.pop();

                // Compare top and next_top.
                // Push top and next_top such that the
                // smallest element ends up on the top of the stack.
                if (top > next_top) {
                    m_impl.push(top);
                    m_impl.push(next_top);
                } else {
                    m_impl.push(next_top);
                    m_impl.push(top);
                }
            // Put the last element in the stack back.
            // We don't have a second element to compare.
            } else {
                m_impl.push(top);
            }
        }
    }
}

}

#endif /* HEADER_HPP */
