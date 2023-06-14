#include <iostream>
#include <iomanip>
#include "SkipList.h"
#include "Timer.h"


int main() {
    Timer t;
    SkipList<int> skipList(10);

    // Insert elements into the skip list
    skipList.insert(5);
    skipList.insert(10);
    skipList.insert(3);
    skipList.insert(8);

    std::cout << skipList << "\n";

    // Search for elements in the skip list
    int value = 4;
    t.start();
    bool found = skipList.search(value);
    t.stop();
    if (found) {
        std::cout << "Element " << value << " jest w skip liscie." << std::endl;
    } else {
        std::cout << "Element " << value << " nie znaleziony." << std::endl;
    }
    std::cout << "trwalo " << std::fixed << std::setprecision(10) << t.elapsedMilliseconds() << " ms";

    return 0;
}
