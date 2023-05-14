#pragma once
#include "SelfOrganisingList.h"

template<typename T>
SelfOrganisingList<T>::SelfOrganisingList(int _size) : size(_size), count(0){
    tab = new Node<T>[_size];
}

template<typename T>
void SelfOrganisingList<T>::add(T value) {
    if (count < size-1){
        auto *tmp = new Node<T>(value);
        tab[count++] = *tmp;
    }
}

template<typename T>
void SelfOrganisingList<T>::remove(T value) {
    count--;
}

template<typename T>
void SelfOrganisingList<T>::removeAt(int index) {
    count--;
}

template<typename T>
Node<T> &SelfOrganisingList<T>::operator[](const int &idx) {
    return tab[idx];
}