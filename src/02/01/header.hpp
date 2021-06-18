/*!
    \file       header.hpp
    \brief      Header file for CTCI (6th Edition), question 2.1: Remove Dups

    \details
    Write code to remove duplicates from an unsorted linked list.

    FOLLOW UP
    How would you solve this problem if a temporary buffer is not allowed?

    \author     Gemuele Aludino
    \date       15 Aug 2020
*/

#ifndef HEADER_HPP
#define HEADER_HPP

#include <ostream>
#include <initializer_list>

namespace ctci6 {

template <typename T> struct fwd_list_node;
template <typename T> struct fwd_list_iterator;
template <typename T> struct fwd_list_const_iterator;
template <typename T> class forward_list;

template <typename T>
std::ostream &operator<<(std::ostream &os, const forward_list<T> &l);

template <typename T>
struct fwd_list_node {
    fwd_list_node() = default;
    fwd_list_node(const T &data) : m_data(data) { }

    static void hook_after(fwd_list_node *x, fwd_list_node *y);
    static void unhook_after(fwd_list_node *y);

    fwd_list_node *m_next = nullptr;
    T m_data;
};

template <typename T>
struct fwd_list_iterator {
    using Self = fwd_list_iterator<T>;
    using Node = fwd_list_node<T>;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
   
    fwd_list_iterator(Node *curr = nullptr) : m_curr(curr) { }
    fwd_list_iterator(const Self &it) : m_curr(it.m_curr) { }
    
    reference operator*() {
        return m_curr->m_data;
    }

    pointer operator->() {
        return &(m_curr->m_data);
    }

    Self &operator++() {
        m_curr = m_curr->m_next; 
        return *this;
    }

    Self operator++(int) {
        auto temp(*this);
        m_curr = m_curr->m_next;
        return temp;
    }

    Self &operator=(const Self &it) {
        m_curr = it.m_curr;
        return *this;
    }

    friend bool operator==(const Self &x, const Self &y) {
        return x.m_curr == y.m_curr;
    }

    friend bool operator!=(const Self &x, const Self &y) {
        return x.m_curr != y.m_curr;
    }

    Self m_next() {
        return m_curr ? Self(m_curr->m_next) : Self(nullptr);
    }

    Node *m_curr = nullptr;
};

template <typename T>
struct fwd_list_const_iterator {
    using Self = fwd_list_const_iterator<T>;
    using Node = const fwd_list_node<T>;
    using iterator = const fwd_list_iterator<T>;

    using value_type = T;
    using pointer = const T *;
    using reference = const T &;

    fwd_list_const_iterator(Node *curr = nullptr) : m_curr(curr) { }
    fwd_list_const_iterator(iterator &it) : m_curr(it.m_curr) { }
    fwd_list_const_iterator(const Self &it) : m_curr(it.m_curr) { }

    reference operator*() const {
        return m_curr->m_data;
    }

    pointer operator->() const {
        return &(m_curr->m_data);
    }

    Self &operator++() {
        m_curr = m_curr->m_next;
        return *this;
    }

    Self operator++(int) {
        auto temp(*this);
        m_curr = m_curr->m_next;
        return temp;
    }

    Self &operator=(const Self &it) {
        m_curr = it.m_curr;
        return *this;
    }

    friend bool operator==(const Self &x, const Self &y) {
        return x.m_curr == y.m_curr;
    }

    friend bool operator!=(const Self &x, const Self &y) {
        return x.m_curr != y.m_curr;
    }

    Self m_next() {
        return m_curr ? Self(m_curr->m_next) : Self(nullptr);
    }

    Node *m_curr = nullptr;
};

template <typename T>
class forward_list {
private:
    using Node = fwd_list_node<T>;
   
    Node *m_insert_after(Node *pos, const T &data);
    Node *m_erase_after(Node *pos);
    Node *m_erase_after(Node *pos, Node *last);

    Node m_node;
public:
    using iterator = fwd_list_iterator<T>;
    using const_iterator = fwd_list_const_iterator<T>;

    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using const_reference = const T &;

    forward_list() = default;

    forward_list(std::initializer_list<T> l) {
        auto it = before_begin();
        for (const auto &val : l) {
            it = insert_after(it, val);
        }
    }

    ~forward_list() { clear(); }
    
    iterator before_begin() {
        return iterator(&m_node);
    }

    iterator begin() {
        return iterator(m_node.m_next);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator before_begin() const {
        return const_iterator(&m_node);
    }

    const_iterator begin() const {
        return const_iterator(m_node.m_next);
    }

    const_iterator end() const {
        return const_iterator(nullptr);
    }

    void push_front(const T &data) {
        insert_after(before_begin(), data);
    }

    void pop_front() {
        erase_after(before_begin());
    }
    
    iterator insert_after(const_iterator it, const T &data) {
        return iterator(m_insert_after(const_cast<Node *>(it.m_curr), data));
    }
    
    iterator erase_after(const_iterator it) {
        return iterator(m_erase_after(const_cast<Node *>(it.m_curr)));
    }

    iterator erase_after(const_iterator it, const_iterator last) {
        return iterator(m_erase_after(const_cast<Node *>(it.m_curr), const_cast<Node *>(last.m_curr)));
    }

    void clear() {
        erase_after(before_begin(), end());
    }

    static void remove_duplicates(forward_list &l);

    friend std::ostream &operator<< <>(std::ostream &os, const forward_list &l);
};

template <typename T>
void fwd_list_node<T>::hook_after(fwd_list_node *x, fwd_list_node *y) {
    y->m_next = x->m_next;
    x->m_next = y;
}

template <typename T>
void fwd_list_node<T>::unhook_after(fwd_list_node *y) {
    y->m_next = y->m_next->m_next;
}

template <typename T>
typename forward_list<T>::Node *
forward_list<T>::m_insert_after(typename forward_list<T>::Node *pos, const T &data) {
    auto new_node = new typename forward_list<T>::Node(data);
    forward_list<T>::Node::hook_after(pos, new_node);
    return pos->m_next;
}

template <typename T>
typename forward_list<T>::Node *
forward_list<T>::m_erase_after(typename forward_list<T>::Node *pos) {
    auto victim = pos->m_next;
    forward_list<T>::Node::unhook_after(pos);
    delete victim;
    return pos->m_next;
}

template <typename T>
typename forward_list<T>::Node *
forward_list<T>::m_erase_after(typename forward_list<T>::Node *pos,
                               typename forward_list<T>::Node *last) {
    while (pos->m_next != nullptr) { m_erase_after(pos); }
    return last;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const typename ctci6::forward_list<T> &l) {
    os << "{";
    for (const auto &val : l) {
        os << " " << val << " ";
    }
    os << "}";
    return os;
}

}

#endif /* HEADER_HPP */

