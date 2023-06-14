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

    double elapsedMicroseconds() {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        if(running) {
            endTime = std::chrono::system_clock::now();
        }
        else {
            endTime = this->endTime;
        }

        return std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    }

    double elapsedMilliseconds() {
        return elapsedMicroseconds() / 1000.0;
    }

    double elapsedSeconds() {
        return elapsedMilliseconds() / 1000.0;
    }
};