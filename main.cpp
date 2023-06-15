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
    std::string fileName = "./tests/500_nonunique_1to1000_read.in";

    for (int i=1; i<=1000; i++){
        soList.add(i);
    }

    for (int i=0; i<10; i++){
        t.start();
        searchFromFile(soList, fileName);
        t.stop();

        std::cout << "trwalo " << std::fixed << std::setprecision(10) << t.elapsedMicroseconds() << " microseconds\n";
    }
    return 0;
}
