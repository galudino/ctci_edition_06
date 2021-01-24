/*!
    \file       header.hpp
    \brief      Header file for CTCI (6th Edition), question 2.3: Delete Middle
   Node

    \details
    Implement an algorithm to delete a node in the middle
    (i.e. any node but the first and the last node,
    not necessarily the exact middle) of a singly linked list,
    given only access to that node.

    EXAMPLE
    Input: the node c from the linked list
        a->b->c->d->e->f

    Result: nothing is returned,
    but the new linked list looks like
        a->b->d->e->f

    \author     Gemuele Aludino
    \date       23 Jan 2021
*/

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <initializer_list>
#include <memory>
#include <cstddef>

/*
    A simplified implementation of std::forward_list<T>
    (a singly-linked list)
 */

namespace ctci6 {
template <typename T> struct fwd_list_node;
template <typename T> struct fwd_list_iterator;
template <typename T> struct fwd_list_const_iterator;
template <typename T> class forward_list;

template <typename T>
struct fwd_list_node {
    fwd_list_node() = default;
    fwd_list_node(const T &data) : m_data(data) { }

    fwd_list_node *m_next = nullptr;
    T m_data;
};

template <typename T>
struct fwd_list_iterator {
private:
    using Self = fwd_list_iterator<T>;
    using Node = fwd_list_node<T>;

public:
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    fwd_list_iterator(Node *curr = nullptr) : m_curr(curr) { }
    fwd_list_iterator(const Self &it) : m_curr(it.m_curr) { }

    reference operator*() { return m_curr->m_data; }
    pointer operator->() { return &(m_curr->m_data); }

    Self &operator++() {
        m_curr = m_curr->m_next;
        return *this;
    }

    Self operator++(int) {
        auto temp(*this);
        m_curr = m_curr->m_next;
        return temp;
    }

    Self &operator+=(int n) {
        for (auto i = 0; i < n; ++i) {
            m_curr = m_curr->m_next;
        }
        return *this;
    }

    friend Self operator+(const Self &x, int n) {
        return const_cast<Self &>(x) += n;
    }

    friend bool operator==(const Self &x, const Self &y) {
        return x.m_curr == y.m_curr;
    }

    friend bool operator!=(const Self &x, const Self &y) {
        return x.m_curr != y.m_curr;
    }

    Self m_next() const {
        return m_curr ? Self(m_curr->m_next) : Self(nullptr);
    }

    Node *m_curr = nullptr;
};

template <typename T>
struct fwd_list_const_iterator {
private:
    using Node = const fwd_list_node<T>;
    using Self = fwd_list_const_iterator<T>;
    using iterator = const fwd_list_iterator<T>;

public:
    using value_type = T;
    using pointer = const T *;
    using reference = const T &;

    fwd_list_const_iterator(Node *curr = nullptr) : m_curr(curr) { }
    fwd_list_const_iterator(iterator &it) : m_curr(it.m_curr) { }
    fwd_list_const_iterator(const Self &it) : m_curr(it.m_curr) { }

    reference operator*() { return m_curr->m_data; }
    pointer operator->() { return &(m_curr->m_data); }

    Self &operator++() {
        m_curr = m_curr->m_next;
        return *this;
    }

    Self operator++(int) {
        auto temp(*this);
        m_curr = m_curr->m_next;
        return temp;
    }

    Self &operator+=(int n) {
        for (auto i = 0; i < n; ++i) {
            m_curr = m_curr->m_next;
        }
        return *this;
    }

    friend Self operator+(const Self &x, int n) {
        return const_cast<Self &>(x) += n;
    }

    friend bool operator==(const Self &x, const Self &y) {
        return x.m_curr == y.m_curr;
    }

    friend bool operator!=(const Self &x, const Self &y) {
        return x.m_curr != y.m_curr;
    }

    Self m_next() const {
        return m_curr ? Self(m_curr->m_next) : Self(nullptr);
    }

    const Node *m_curr = nullptr;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, 
                         const typename ctci6::forward_list<T> &l);

template <typename T>
class forward_list {
private:
    using Node = fwd_list_node<T>;

    Node *m_insert_after(Node *curr, const T &data);
    Node *m_erase_after(Node *curr);
    Node *m_erase_after(Node *curr, Node *last);

    Node m_node;
public:
    using iterator = fwd_list_iterator<T>;
    using const_iterator = fwd_list_const_iterator<T>;

    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_type = std::size_t; 

    forward_list() = default;

    forward_list(std::initializer_list<T> l) {
        auto curr = &m_node;

        for (auto &val : l) {
            curr = m_insert_after(curr, val);
        }
    }

    ~forward_list() { m_erase_after(&m_node, nullptr); }

    iterator before_begin() { return iterator(&m_node); }
    const_iterator before_begin() const { return const_iterator(&m_node); }

    iterator begin() { return iterator(m_node.m_next); }
    const_iterator begin() const { return const_iterator(m_node.m_next); }

    iterator end() { return iterator(nullptr); }
    const_iterator end() const { return const_iterator(nullptr); }

    bool empty() const { return m_node.m_next == nullptr; }

    size_type size() const;

    reference front() { return *(m_node.m_next->m_data); }
    const_reference front() const { return *(m_node.m_next->m_data); }
    
    reference operator[](int n);

    void push_front(const T &data) { m_insert_after(before_begin(), data); }

    void pop_front() { m_erase_after(before_begin()); }

    iterator insert_after(const_iterator pos, const T &val) {
        return iterator(m_insert_after(pos, val));
    }

    iterator erase_after(const_iterator pos) {
        return iterator(m_erase_after(const_cast<Node *>(pos.m_curr)));
    }

    iterator erase_after(const_iterator pos, const_iterator last) {
        return iterator(m_erase_after(const_cast<Node *>(pos.m_curr),
                                      const_cast<Node *>(last.m_curr)));
    }

    void clear() { m_erase_after(&m_node, nullptr); }

    friend std::ostream &operator<< <>(std::ostream &os, const forward_list &l);
};

template <typename T>
typename forward_list<T>::size_type forward_list<T>::size() const {
    auto curr = m_node.m_next;
    auto count = 0;

    while (curr != nullptr) {
        curr = curr->m_next;
        ++count;
    }

    return count;
}

template <typename T>
typename forward_list<T>::reference forward_list<T>::operator[](int n) {
    auto curr = m_node.m_next;

    for (auto i = 0; i < n; ++i) {
        curr = curr->m_next;
    }

    return curr->m_data;
}

template <typename T>
typename forward_list<T>::Node *
forward_list<T>::m_insert_after(typename forward_list<T>::Node *curr,
                                const T &data) {
    auto new_node = new typename forward_list<T>::Node(data);

    new_node->m_next = curr->m_next;
    curr->m_next = new_node;

    return curr->m_next;
}

template <typename T>
typename forward_list<T>::Node *
forward_list<T>::m_erase_after(typename forward_list<T>::Node *curr) {
    auto pos = curr->m_next;

    curr->m_next = pos->m_next;
    delete pos;

    return curr->m_next;
}

template <typename T>
typename forward_list<T>::Node *
forward_list<T>::m_erase_after(typename forward_list<T>::Node *curr,
                               typename forward_list<T>::Node *last) {
    auto pos = curr->m_next;

    while (pos != last) {
        auto temp = pos;
        pos = pos->m_next;
        delete temp;
    }

    return last;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, 
                         const typename ctci6::forward_list<T> &l) {
    auto curr = l.m_node.m_next;
    
    os << "{ ";
    while (curr != nullptr) {
        os << curr->m_data << " ";
        curr = curr->m_next;
    }
    os << "}";

    return os;
}

} // namespace ctci6

#endif /* HEADER_HPP */
