#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include "SkipList.h"
#include "Timer.h"
#include "SelfOrganisingList.h"

template<typename T>
void searchFromFile(BaseList<T> &list, const std::string &filepath){
    std::ifstream file;
    file.open(filepath);

    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    T singleLine;
    while (file >> singleLine) {
        list.search(singleLine);
    }

    file.close();
}

int main() {
    Timer t;
    SelfOrganisingList<int> soList(1000);

    for (int i=1; i<=100; i++){
        soList.add(i);
    }

    t.start();
    searchFromFile(soList, "./tests/500_unique_1to1000_read.in");
    t.stop();

    std::cout << "trwalo " << std::fixed << std::setprecision(10) << t.elapsedMicroseconds() << " microseconds";
    return 0;
}
