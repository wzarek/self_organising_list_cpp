#pragma once

#include <exception>
#include <stdexcept>
#include "SelfOrganisingList.h"

template<typename T>
SelfOrganisingList<T>::SelfOrganisingList(int _size) : BaseList<T>(_size){

}

template<typename T>
Node<T>& SelfOrganisingList<T>::operator[](const int& idx) {
    if (idx >= 0 && idx < BaseList<T>::count) {
        BaseList<T>::tab[idx].increaseCounter(); // INCREMENT COUNTER

        for (int i = idx; i > 0; i--) {
            if (BaseList<T>::tab[i - 1].getCounter() >= BaseList<T>::tab[i].getCounter())
                break; // CHECK IF THE ELEMENT COUNTER IS LESS THAN CURRENT COUNTER

            std::swap(BaseList<T>::tab[i], BaseList<T>::tab[i - 1]); // SWAP ELEMENTS
        }

        return BaseList<T>::tab[idx];
    }
    throw std::out_of_range("Index out of range"); // THROW EXCEPTION IF INDEX IS OUT OF RANGE
}
