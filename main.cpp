#include <iostream>

template<typename T>
class Node{
    T value;
    int accessCounter;

public:
    Node(T val) : value(val){}
    Node(){}

    T getValue(){
        return value;
    }
};

template<typename T>
class SelfOrganisingList{
    Node<T> *tab;
    int size;
    int count;

public:
    SelfOrganisingList(int _size) : size(_size), count(0){
        tab = new Node<T>[_size];
    }

    void addToList(T value){
        if (count < size-1){
            Node<T> *tmp = new Node<T>(value);
            tab[count++] = *tmp;
        }
    }

    void removeFromListByValue(T value){
        count--;
    }

    void removeFromListByIndex(int index){
        count--;
    }

    Node<T>& operator[](const int &idx){
        return tab[idx];
    }
};

int main() {
    SelfOrganisingList<int> s(5);
    s.addToList(1);
    s.addToList(2);
    std::cout << s[0].getValue() << s[1].getValue();
    return 0;
}
