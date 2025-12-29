#define _CRT_SECURE_NO_WARNINGS
#include "timer.h"
#include <iostream>

Timer::Timer():BaseTimer() {
    gameTime = nullptr;   
    start();  
}

Timer::~Timer() {
    if (gameTime != nullptr) {
        delete gameTime;
        gameTime = nullptr;
    }
}

//функция потока
void Timer::timerWorker() {
    while (timerON) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (timerON) {
            time_t elapsed = difftime(time(NULL), startTime);
            tm timeInfo;
            localtime_s(&timeInfo, &elapsed);

            if (gameTime == nullptr) {
                gameTime = new tm();
            }
            *gameTime = timeInfo;
        }
    }
}

// запустить
void Timer::start() {
    BaseTimer::start();  
}

// остановить
void Timer::stop() {
    BaseTimer::stop();  
    time_t elapsed = difftime(time(NULL), startTime);

    if (gameTime == nullptr) {
        gameTime = new tm();
    }

    tm timeInfo;
    localtime_s(&timeInfo, &elapsed);
    *gameTime = timeInfo;
}


// вывести время 
void Timer::printTime() const {
    if (gameTime != nullptr) {
        std::cout << "Время игры: "
            << gameTime->tm_min << ":"
            << gameTime->tm_sec << std::endl;
    }
    else {
        std::cout << "Время игры: не доступно" << std::endl;
    }
}
