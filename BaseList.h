//
// Created by katan on 08/06/2023.
//
#pragma once
#ifndef SELF_ORGANISING_LIST_CPP_BASELIST_H
#define SELF_ORGANISING_LIST_CPP_BASELIST_H
#include "Node.h"

template<typename T>
class BaseList {
protected:
    Node<T> *tab;
    int size;
    int count;

public:
    explicit BaseList(int _size);

    // CHECK
    bool isEmpty();
    bool isFull();
    int length();

    // ADD
    void add(T value);

    // REMOVE
    void remove(T value);
    void removeAt(int idx);
    void clear();

    // GET
    T valueAt(int idx);
    int indexOf(T value);
    Node<T>& operator[](const int &idx);
};

#include "BaseList.tpp"
#endif //SELF_ORGANISING_LIST_CPP_BASELIST_H
