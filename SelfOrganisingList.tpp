#pragma once

#include <exception>
#include <stdexcept>
#include "SelfOrganisingList.h"

template<typename T>
SelfOrganisingList<T>::SelfOrganisingList(int _size) : BaseList<T>(_size){

}

template<typename T>
void SelfOrganisingList<T>::reorganiseUp(const int &idx) {
    if (idx < 0 || idx >= BaseList<T>::count) { throw std::out_of_range("Index out of range"); }

    for (int i = idx; i > 0 && BaseList<T>::tab[i - 1].getCounter() < BaseList<T>::tab[i].getCounter(); i--) {
        std::swap(BaseList<T>::tab[i], BaseList<T>::tab[i - 1]);
    }
}

template<typename T>
int SelfOrganisingList<T>::indexOf(T value) {
    for (int i = 0; i < BaseList<T>::count; i++) {
        if (BaseList<T>::tab[i].getValue() == value) {
            BaseList<T>::tab[i].incrementCounter();
            reorganiseUp(i);
            return i;
        }
    }
    return -1;
}

template<typename T>
T SelfOrganisingList<T>::valueAt(int idx) {
    if (idx >= BaseList<T>::count || idx < 0) { throw std::out_of_range("Index out of range"); }

    BaseList<T>::tab[idx].incrementCounter();
    reorganiseUp(idx);

    return BaseList<T>::tab[idx];
}

template<typename T>
Node<T>& SelfOrganisingList<T>::operator[](const int& idx) {
    if (idx < 0 || idx >= BaseList<T>::count) { throw std::out_of_range("Index out of range"); }

    BaseList<T>::tab[idx].incrementCounter();
    reorganiseUp(idx);

    return BaseList<T>::tab[idx];
}

template<typename T>
bool SelfOrganisingList<T>::search(T value) {
    return indexOf(value) != -1;
}