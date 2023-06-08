#pragma once
#include "SelfOrganisingList.h"

template<typename T>
SelfOrganisingList<T>::SelfOrganisingList(int _size) : size(_size), count(0){
    tab = new Node<T>[_size];
}

// CHECKERS
template<typename T>
bool SelfOrganisingList<T>::isEmpty(){
    return count == 0;
}

template<typename T>
bool SelfOrganisingList<T>::isFull(){
    return count == size;
}

template<typename T>
int SelfOrganisingList<T>::length(){
    return count;
}

// ADDING
template<typename T>
void SelfOrganisingList<T>::add(T value) {
    if (count >= size) { throw std::exception(); } // todo: custom exception - list full

    if (indexOf(value) != -1) { throw std::exception(); } // todo: custom exception - value already exists

    tab[count++] = Node<T>(value);
}

// DELETION
template<typename T>
void SelfOrganisingList<T>::remove(T value) {
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
void SelfOrganisingList<T>::removeAt(int idx) {
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
int SelfOrganisingList<T>::indexOf(T value) {
    for (int i = 0; i < count; i++) {
        if (tab[i].getValue() == value) { return i; }
    }
    return -1;
}

template<typename T>
T SelfOrganisingList<T>::valueAt(int idx){
    if (idx >= count) { throw std::exception(); } // todo: custom exception


}

// OPERATOR OVERLOADING

template<typename T>
Node<T> &SelfOrganisingList<T>::operator[](const int &idx) {
    return tab[idx];
}