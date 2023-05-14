#pragma once
#include "Node.h"

template<typename T>
Node<T>::Node() = default;

template<typename T>
T Node<T>::getValue() {
    return value;
}