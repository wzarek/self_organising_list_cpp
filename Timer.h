#pragma once

#include <chrono>
#include <ctime>
#include <cmath>

class Timer {

private:
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> endTime;
    bool running = false;

public:
    void start() {
        startTime = std::chrono::system_clock::now();
        running = true;
    }

    void stop() {
        endTime = std::chrono::system_clock::now();
        running = false;
    }

    double elapsedMilliseconds() {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        if(running) {
            endTime = std::chrono::system_clock::now();
        }
        else {
            endTime = this->endTime;
        }

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    }

    double elapsedSeconds() {
        return elapsedMilliseconds() / 1000.0;
    }
};