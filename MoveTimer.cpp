#define _CRT_SECURE_NO_WARNINGS
#include "MoveTimer.h"

MoveTimer::MoveTimer(time_t limit):BaseTimer() {
    limitTime = limit;
    totalTimeUsed = 0;
    currentRemaining = limit;
}

MoveTimer::~MoveTimer() {
    timerON = false;
    if (workerThread.joinable()) {
        workerThread.join();
    }

}

//функция потока
void MoveTimer::timerWorker() {
    while (timerON) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        if (timerON) {
            time_t timeUsedThisMove = difftime(time(NULL), startTime);
            time_t timeUsedThisGame = totalTimeUsed + timeUsedThisMove;
            currentRemaining = limitTime - timeUsedThisGame;

            if (currentRemaining <= 0) {
                currentRemaining = 0;
                break;
            }
        }
    }

    if (timerON) {
        timerON = false;
        time_t thisMoveTime = difftime(time(NULL), startTime);
        totalTimeUsed += thisMoveTime;
    }
}

//старт
void MoveTimer::start() {
    if (!timerON && currentRemaining > 0) {
        startTime = time(NULL);
        timerON = true;
        startThread();  
    }
}

// стоп
void MoveTimer::stop() {
    if (timerON) {
        timerON = false;
        stopThread();  

        time_t thisMoveTime = difftime(time(NULL), startTime);
        totalTimeUsed += thisMoveTime;
        currentRemaining = limitTime - totalTimeUsed;
        if (currentRemaining < 0) currentRemaining = 0;
    }
}

// ресет
void MoveTimer::reset() {
    stop();  
    totalTimeUsed = 0;
    startTime = 0;
    currentRemaining = limitTime;
}

// получение оставшегося времени
time_t MoveTimer::getRemainingTimeSec() const {
    if (timerON) {
        time_t timeUsedThisMove = difftime(time(NULL), startTime);
        time_t remaining = limitTime - (totalTimeUsed + timeUsedThisMove);
        return (remaining > 0) ? remaining : 0;
    }
    else {
        return currentRemaining;
    }
}

// получение использованного времени
time_t MoveTimer::getUsedTimeSec() const {
    if (timerON) {
        return totalTimeUsed + difftime(time(NULL), startTime);
    }
    else {
        return totalTimeUsed;
    }
}

// проверка. осталось ли время
bool MoveTimer::isTimeUp() const {
    return getRemainingTimeSec() <= 0;
}