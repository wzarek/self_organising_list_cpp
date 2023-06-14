#pragma once

#include <exception>
#include "SelfOrganisingList.h"

template<typename T>
SelfOrganisingList<T>::SelfOrganisingList(int _size) : BaseList<T>(_size){

}

template<typename T>
Node<T>& SelfOrganisingList<T>::operator[](const int& idx) {
    if (idx >= 0 && idx < count) {
        count++; // INCREMENT COUNTER

        for (int i = idx; i > 0; i--) {
            if (!tab[i - 1].exists())
                break; // CHECK IF PREVIOUS ELEMENT EXISTS

            if (tab[i - 1].getCounter() >= count)
                break; // CHECK IF THE ELEMENT COUNTER IS LESS THAN CURRENT COUNTER

            std::swap(tab[i], tab[i - 1]); // SWAP ELEMENTS
        }

        return tab[idx];
    }
    throw std::out_of_range("Index out of range"); // THROW EXCEPTION IF INDEX IS OUT OF RANGE
}
