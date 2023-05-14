#include <iostream>
#include "Node.h"
#include "SelfOrganisingList.h"

int main() {
    SelfOrganisingList<int> s(5);
    s.add(1);
    s.add(2);
    std::cout << s[0].getValue() << s[1].getValue();
    return 0;
}
