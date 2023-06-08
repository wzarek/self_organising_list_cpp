#include <iostream>
#include "SkipList.h"


int main() {
    SkipList<int> s(1);

    s.add(1);
    s.add(3);
    s.add(2);
    std::cout << s[0].getValue() << "\t" << s[1].getValue() << "\t" << s[2].getValue() << "\n";
    s.remove(2);
    std::cout << s[0].getValue() << "\t" << s[1].getValue() << "\n";
    s.remove(1);
    std::cout << s[0].getValue();
    return 0;
}
