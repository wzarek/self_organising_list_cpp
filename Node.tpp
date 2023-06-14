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

template<typename T>
int Node<T>::getCounter() {
    return accessCounter;
}

template<typename T>
void Node<T>::incrementCounter() {
    accessCounter++;
}

template<typename T>
int Node<T>::getNextIndex() const {
    return nextIndex;
}