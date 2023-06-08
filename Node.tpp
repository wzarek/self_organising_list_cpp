#pragma once
#include "Node.h"

template<typename T>
Node<T>::Node() = default;

template<typename T>
Node<T>::Node(const Node<T> &other){
    this->value = other.value;
    this->accessCounter = other.accessCounter;
}

template<typename T>
T Node<T>::getValue() {
    return value;
}