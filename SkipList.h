#pragma once
#ifndef SELF_ORGANISING_LIST_CPP_SKIPLIST_H
#define SELF_ORGANISING_LIST_CPP_SKIPLIST_H

#include "BaseList.h"

template<typename T>
class SkipList : public BaseList<T> {
public:
    explicit SkipList(int _size);

    // INSERT
    void insert(T value);

    // SEARCH
    bool search(T value);
};

#include "SkipList.tpp"

#endif //SELF_ORGANISING_LIST_CPP_SKIPLIST_H