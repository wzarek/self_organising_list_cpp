//
// Created by katan on 08/06/2023.
//
#pragma once
#include "SkipList.h"
#include <random>

template<typename T>
SkipList<T>::SkipList(int _size) : BaseList<T>(_size) {}

template<typename T>
void SkipList<T>::insert(T value) {
    if (this->count >= this->size) {
        BaseList<T>::resize();
    }

    if (this->indexOf(value) != -1) {
        throw std::exception(); // todo: custom exception - value already exists
    }

    // Create a new node
    Node<T> newNode(value);

    // Determine the level for the new node
    int level = 1;
    while (rand() % 2 == 0 && level < this->size) {
        level++;
    }

    // Create/update the levels in the skip list
    if (level > this->count) {
        for (int i = this->count; i < level; i++) {
            this->tab[i] = newNode;
        }
        this->count = level;
    } else {
        for (int i = 0; i < level; i++) {
            this->tab[i].incrementCounter();
            if (i < this->count && this->tab[i].getCounter() >= 2) {
                this->tab[i] = newNode;
            }
        }
    }
}

template<typename T>
bool SkipList<T>::search(T value) {
    for (int i = 0; i < this->count; i++) {
        if (this->tab[i].getValue() == value) {
            this->tab[i].incrementCounter();
            return true;
        }
    }
    return false;
}