#define _CRT_SECURE_NO_WARNINGS
#include "timer.h"
#include <iostream>

Timer::Timer() {
    timerON = false;
    startTime = 0;
    gameTime = nullptr;   

    startTimer();  
}

Timer::~Timer() {
    stopTimer();
}

//функция потока
void Timer::timerWorker() {
    while (timerON) {
        this_thread::sleep_for(chrono::seconds(1));

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
void Timer::startTimer() {
    if (!timerON) {
        startTime = time(NULL);
        timerON = true;
        workerThread = thread(&Timer::timerWorker, this);
    }
}

// остановить
void Timer::stopTimer() {
    if (timerON) {
        timerON = false;

        if (workerThread.joinable()) {
            workerThread.join();
        }

        time_t elapsed = difftime(time(NULL), startTime);

        if (gameTime == nullptr) {
            gameTime = new tm();
        }

        tm timeInfo;
        localtime_s(&timeInfo, &elapsed);
        *gameTime = timeInfo;
    }
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

// получить прошедшее время
time_t Timer::getElapsedSeconds() const {
    if (timerON) {
        return difftime(time(NULL), startTime);
    }
    else {
        if (startTime != 0) {
            return difftime(time(NULL), startTime);
        }
        return 0;
    }
}

// проверка, работает ли
bool Timer::ON_OFF() const {
    return timerON;
}