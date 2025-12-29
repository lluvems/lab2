#define _CRT_SECURE_NO_WARNINGS
#include "BaseTimer.h"

BaseTimer::BaseTimer(){
    timerON = false;
    startTime = 0;

}

BaseTimer::~BaseTimer() {
    stop();  
}

//общий метод запуска
void BaseTimer::start() {
    if (!timerON) {
        startTime = time(NULL);
        timerON = true;
        startThread();
    }
}

//общий метод остановки
void BaseTimer::stop() {
    if (timerON) {
        timerON = false;
        stopThread();
    }
}

//запуск потока
void BaseTimer::startThread() {
    workerThread = std::thread(&BaseTimer::timerWorker, this);
}

//остановка потока
void BaseTimer::stopThread() {
    if (workerThread.joinable()) {
        workerThread.join();
    }
}

//проверка, работает ли таймер
bool BaseTimer::ON_OFF() const {
    return timerON;
}

//получение прошедшего времени
time_t BaseTimer::getElapsedSeconds() const {
    if (timerON) {
        return difftime(time(NULL), startTime);
    }
    else if (startTime != 0) {
        return difftime(time(NULL), startTime);
    }
    return 0;
}