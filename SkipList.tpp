//
// Created by katan on 08/06/2023.
//
#pragma once
#include "SkipList.h"
#include <random>

template<typename T>
SkipList<T>::SkipList(int _size) : BaseList<T>(_size) {}

template<typename T>
void SkipList<T>::add(T value) {
    if (this->indexOf(value) != -1) {
        throw std::exception();
    }
  
    if (this->count >= this->size) {
        BaseList<T>::resize();
    }

    // Create a new node
    Node<T> newNode(value);

    // Determine the level for the new node
    int level = 1;
    while (rand() % 2 == 0 && level < this->size) {
        level++;
    }

    // Create/update the levels in the skip list
    for (int i = 0; i < level; i++) {
        this->tab[i] = newNode;
    }
}

template<typename T>
bool SkipList<T>::search(T value) {
    int currentLevel = this->count - 1; // Start from the highest level

    while (currentLevel >= 0) {
        if (this->tab[currentLevel].getValue() == value) {
            return true; // Found the value at the current level
        }

        if (currentLevel == 0 || this->tab[currentLevel].getValue() > value) {
            // Move down to the next level
            currentLevel--;
        } else {
            // Skip to the next relevant node at the current level
            int nextIndex = this->tab[currentLevel].getNextIndex();
            if (nextIndex != -1 && this->tab[nextIndex].getValue() <= value) {
                // Make the skip
                currentLevel = nextIndex;
            } else {
                // Move down to the next level
                currentLevel--;
            }
        }
    }

    return false; // Value not found in the skip list
}