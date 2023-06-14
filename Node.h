//
// Created by katan on 14/05/2023.
//
#pragma once
#ifndef SELF_ORGANISING_LIST_CPP_NODE_H
#define SELF_ORGANISING_LIST_CPP_NODE_H


template<typename T>
class Node{
public:
    T value;
    Node(T val) : value(val){}
    Node();
    int accessCounter;
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
