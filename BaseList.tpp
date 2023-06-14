#pragma once

#include <exception>
#include "BaseList.h"

template<typename T>
BaseList<T>::BaseList(int _size) : size(_size), count(0){
    tab = new Node<T>[_size];
}

// CHECKERS
template<typename T>
bool BaseList<T>::isEmpty(){
    return count == 0;
}

template<typename T>
bool BaseList<T>::isFull(){
    return count == size;
}

template<typename T>
int BaseList<T>::length(){
    return count;
}

// ADDING
template<typename T>
void BaseList<T>::add(T value) {
    if (count >= size) { throw std::exception(); } // todo: custom exception - list full

    if (indexOf(value) != -1) { throw std::exception(); } // todo: custom exception - value already exists

    tab[count++] = Node<T>(value);
}

// DELETION
template<typename T>
void BaseList<T>::remove(T value) {
    for (int i = 0; i < count; i++) {
        if (tab[i].getValue() == value) {
            for (int j = i; j < count - 1; j++) {
                tab[j] = tab[j + 1];
            }
            count--;
            tab[count] = Node<T>();
            return;
        }
    }
}

template<typename T>
void BaseList<T>::removeAt(int idx) {
    if (idx >= 0 && idx < count) {
        for (int i = idx; i < count - 1; i++) {
            tab[i] = tab[i + 1];
        }
        count--;
        tab[--count] = Node<T>();
    }
}

// GETTERS
template<typename T>
int BaseList<T>::indexOf(T value) {
    for (int i = 0; i < count; i++) {
        if (tab[i].getValue() == value) { return i; }
    }
    return -1;
}

template<typename T>
T BaseList<T>::valueAt(int idx){
    if (idx >= count) { throw std::exception(); } // todo: custom exception


}

// OPERATOR OVERLOADING

template<typename T>
Node<T> &BaseList<T>::operator[](const int &idx) {
    return tab[idx];
}