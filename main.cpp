#include <iostream>
#include "SkipList.h"


int main() {
    SkipList<int> skipList(10);

    // Insert elements into the skip list
    skipList.insert(5);
    skipList.insert(10);
    skipList.insert(3);
    skipList.insert(8);

    std::cout << skipList << "\n";

    // Search for elements in the skip list
    int value = 4;
    bool found = skipList.search(value);
    if (found) {
        std::cout << "Element " << value << " jest w skip liscie." << std::endl;
    } else {
        std::cout << "Element " << value << " nie znaleziony." << std::endl;
    }

    return 0;
}
