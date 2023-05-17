#include <iostream>
#include "Node.h"
#include "SelfOrganisingList.h"


int main() {
    SelfOrganisingList<int> s(5);

    s.add(1);
    s.add(1);
    s.add(2);
    s.remove(2);
    s.addAt(2,0);
    std::cout << s[0].getValue() << s[1].getValue() << s[2].getValue() <<s[3].getValue() <<s[4].getValue()<< "\n";
    s.remove(1);
    std::cout << s[0].getValue() << s[1].getValue() << s[2].getValue()<<s[3].getValue() <<s[4].getValue();
    return 0;
}
