#include <iostream>
#include "Node.h"
#include "SelfOrganisingList.h"


int main() {
<<<<<<< Updated upstream
    SelfOrganisingList<int> s(5);

    s.add(1);
    s.add(1);
    s.add(2);
    s.remove(2);
    s.addAt(2,0);
    std::cout << s[0].getValue() << s[1].getValue() << s[2].getValue() <<s[3].getValue() <<s[4].getValue()<< "\n";
    s.remove(1);
    std::cout << s[0].getValue() << s[1].getValue() << s[2].getValue()<<s[3].getValue() <<s[4].getValue();
=======
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

>>>>>>> Stashed changes
    return 0;
}
