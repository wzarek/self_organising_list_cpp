//
// Created by katan on 14/05/2023.
//
#pragma once
#ifndef SELF_ORGANISING_LIST_CPP_NODE_H
#define SELF_ORGANISING_LIST_CPP_NODE_H

template<typename T>
class Node{
    T value;
    int accessCounter;

public:
    Node(T val) : value(val){}
    Node(const Node<T> &other);
    Node();

    T getValue();
//    friend bool operator < (const Node<T>& f, const Node<T>& other);
//    friend bool operator <= (const Node<T>& f, const Node<T>& other);
//    friend bool operator > (const Node<T>& f, const Node<T>& other);
//    friend bool operator >= (const Node<T>& f, const Node<T>& other);
//    friend bool operator == (const Node<T>& f, const Node<T>& other);
//    friend bool operator != (const Node<T>& f, const Node<T>& other);
//    friend std::ostream &operator << (std::ostream &os, const Node<T> &node);
};

#include "Node.tpp"
#endif //SELF_ORGANISING_LIST_CPP_NODE_H
