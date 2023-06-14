//
// Created by katan on 14/05/2023.
//
#pragma once
#ifndef SELF_ORGANISING_LIST_CPP_SELFORGANISINGLIST_H
#define SELF_ORGANISING_LIST_CPP_SELFORGANISINGLIST_H
#include "BaseList.h"

template<typename T>
class SelfOrganisingList : public BaseList<T>{
public:
    explicit SelfOrganisingList(int _size);

    void reorganiseUp(const int& idx);

    // overriding
    bool search(T value);
    int indexOf(T value);
    T valueAt(int idx);
    Node<T>& operator[](const int& idx);
};

#include "SelfOrganisingList.tpp"

#endif //SELF_ORGANISING_LIST_CPP_SELFORGANISINGLIST_H
