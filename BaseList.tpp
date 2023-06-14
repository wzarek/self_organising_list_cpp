#pragma once

#include <exception>
#include "BaseList.h"

template<typename T>
BaseList<T>::BaseList(int _size) : size(_size), count(0){
    if (_size == 0) { throw std::exception(); } // todo: throw an error that size cannot be 0
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
    if (count >= size) { resize(); }

    if (indexOf(value) != -1) { throw std::exception(); } // todo: custom exception - value already exists

    tab[count++] = Node<T>(value);
}

// DELETION
template<typename T>
void BaseList<T>::remove(T value) {
    removeAt(indexOf(value));
}

template<typename T>
void BaseList<T>::removeAt(int idx) {
    if (idx < 0 || idx >= count) { throw std::out_of_range("Index out of range"); }

    for (int i = idx; i < count - 1; i++) {
        tab[i] = tab[i + 1];
    }

    count--;
}

template<typename T>
void BaseList<T>::clear() {
    if (count == 0) { return; }

    count = 0;
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
T BaseList<T>::valueAt(int idx) {
    if (idx >= count || idx < 0) { throw std::out_of_range("Index out of range"); }

    return tab[idx];
}

// RESIZING
template<typename T>
void BaseList<T>::resize() {
    auto *tmpTab = new Node<T>[size*2];

    for (int i = 0; i < size; i++){
        tmpTab[i] = tab[i];
    }
    delete []tab;

    tab = tmpTab;
    size *= 2;
}

// OPERATOR OVERLOADING
template<typename T>
Node<T> &BaseList<T>::operator[](const int &idx) {
    if (idx >= count || idx < 0) { throw std::out_of_range("Index out of range"); }

    return tab[idx];
}

template<typename T>
std::ostream &operator<<(std::ostream &o, BaseList<T> &list) {
    for (int i=0; i<list.count; i++){
        o << list[i].getValue() << "\t";
    }

    return o;
}