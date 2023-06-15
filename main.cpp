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

void generateRandomIntToFile(int rangeFrom, int rangeTo, int count, const std::string &filepath){
    std::ofstream file;
    file.open(filepath);

    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    for (int i=0; i<count; i++){
        file << rangeFrom + (std::rand() % (rangeTo - rangeFrom + 1)) << std::endl;
    }

    file.close();
}

void generateRandomUniqueIntToFile(int rangeFrom, int rangeTo, int count, const std::string &filepath){
    std::ofstream file;
    file.open(filepath);

    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    std::vector<int> numbers;
    for(int i=rangeFrom; i<=rangeTo; i++){
        numbers.push_back(i);
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    for (int i=0; i<count; i++){
        file << numbers[i] << std::endl;
    }

    file.close();
}

int main() {
    srand(time(NULL));

//    generateRandomUniqueIntToFile(1, 1000, 5000, "../tests/5000_unique_1to1000_read.in");
    Timer t;
    SelfOrganisingList<int> soList(1000);
    std::string fileName = "../tests/50000_unique_1to1000_read.in";

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
