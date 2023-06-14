#include <iostream>
#include "SkipList.h"


int main() {
    SelfOrganisingList<int> s(5);

    s.add(1);
    s.add(3);
    s.add(2);
    s.remove(2);
    std::cout << s[0].getValue() << "\t" << s[1].getValue() << "\n";
    s.remove(1);
    SkipList<int> skipList(10); // Specify the maximum size of the skip list

    // Insert elements into the skip list
    skipList.insert(5);
    skipList.insert(10);
    skipList.insert(3);
    skipList.insert(8);

    // Search for elements in the skip list
    int value = 3;
    bool found = skipList.search(value);
    if (found) {
        std::cout << "Element " << value << " jest w skip liscie." << std::endl;
    } else {
        std::cout << "Element " << value << " nie znaleziony." << std::endl;
    }

    return 0;
}
