#pragma once
#include "SelfOrganisingList.h"

template<typename T>
SelfOrganisingList<T>::SelfOrganisingList(int _size) : size(_size), count(0){
    tab = new Node<T>[_size];
}

template<typename T>
void SelfOrganisingList<T>::add(T value) {
    if (count >= size) {

        return; //PELNA LISTA
    }

    if (indexOf(value) != -1) {

        return; //ELEMENT JUZ ISTNIEJE
    }

    tab[count++] = Node<T>(value);
}

template<typename T>
void SelfOrganisingList<T>::addAt(T value, int idx) {
    if (count >= size) {

        return; //PELNA LISTA
    }

    if (idx < 0 || idx > count) {

        return; //NIEWLASCIWY INDEX
    }

    if (indexOf(value) != -1) {

        return; //ELEMENT JUZ ISTNIEJE
    }

    for (int i = count; i > idx; i--) {
        tab[i] = tab[i - 1];
    }

    tab[idx] = Node<T>(value);
    count++;
}

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
        tab[count] = Node<T>();
    }
}

template<typename T>
int SelfOrganisingList<T>::indexOf(T value) {
    for (int i = 0; i < count; i++) {
        if (tab[i].getValue() == value) {
            return i;
        }
    }
    return -1;
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