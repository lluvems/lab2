#define _CRT_SECURE_NO_WARNINGS
#include "MoveTimer.h"

MoveTimer::MoveTimer(time_t limit) {
    timerON = false;
    startTime = 0;
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

void MoveTimer::start() {
    if (!timerON && currentRemaining > 0) {
        startTime = time(NULL);
        timerON = true;
        workerThread = std::thread(&MoveTimer::timerWorker, this);
    }
    else if (currentRemaining <= 0) {
    }
}

void MoveTimer::stop() {
    if (timerON) {
        timerON = false;
        if (workerThread.joinable()) {
            workerThread.join();
        }

        time_t thisMoveTime = difftime(time(NULL), startTime);
        totalTimeUsed += thisMoveTime;
        currentRemaining = limitTime - totalTimeUsed;
        if (currentRemaining < 0) currentRemaining = 0;
    }
}

void MoveTimer::reset() {
    if (timerON) {
        stop();
    }

    if (workerThread.joinable()) {
        workerThread.join();
    }

    totalTimeUsed = 0;
    startTime = 0;
    currentRemaining = limitTime;
}

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

time_t MoveTimer::getUsedTimeSec() const {
    if (timerON) {
        return totalTimeUsed + difftime(time(NULL), startTime);
    }
    else {
        return totalTimeUsed;
    }
}

bool MoveTimer::ON_OFF() const {
    return timerON;
}

bool MoveTimer::isTimeUp() const {
    return getRemainingTimeSec() <= 0;
}