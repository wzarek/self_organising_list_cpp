#pragma once

#include <exception>
#include <stdexcept>
#include "SelfOrganisingList.h"

template<typename T>
SelfOrganisingList<T>::SelfOrganisingList(int _size) : BaseList<T>(_size){

}

template<typename T>
int SelfOrganisingList<T>::reorganiseUp(const int &idx) {
    if (idx < 0 || idx >= BaseList<T>::count) { throw std::out_of_range("Index out of range"); }

    int currentIdx = idx;
    for (int i = idx; i > 0 && BaseList<T>::tab[i - 1].getCounter() < BaseList<T>::tab[i].getCounter(); i--) {
        std::swap(BaseList<T>::tab[i], BaseList<T>::tab[i - 1]);
        currentIdx = i-1;
    }

    return currentIdx;
}

template<typename T>
int SelfOrganisingList<T>::indexOf(T value) {
    for (int i = 0; i < BaseList<T>::count; i++) {
        if (BaseList<T>::tab[i].getValue() == value) {
            BaseList<T>::tab[i].incrementCounter();
            int currentIdx = reorganiseUp(i);
            return currentIdx;
        }
    }
    return -1;
}

template<typename T>
T SelfOrganisingList<T>::valueAt(int idx) {
    if (idx >= BaseList<T>::count || idx < 0) { throw std::out_of_range("Index out of range"); }

    BaseList<T>::tab[idx].incrementCounter();
    int currentIdx = reorganiseUp(idx);

    return BaseList<T>::tab[currentIdx].getValue();
}

template<typename T>
Node<T>& SelfOrganisingList<T>::operator[](const int& idx) {
    if (idx < 0 || idx >= BaseList<T>::count) { throw std::out_of_range("Index out of range"); }

    BaseList<T>::tab[idx].incrementCounter();
    int currentIdx = reorganiseUp(idx);

    return BaseList<T>::tab[currentIdx];
}

template<typename T>
bool SelfOrganisingList<T>::search(T value) {
    return indexOf(value) != -1;
}