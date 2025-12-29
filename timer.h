#ifndef TIMER_H
#define TIMER_H

#include "BaseTimer.h"
#include <ctime>

using namespace std;

class Timer : public BaseTimer {
private:
    tm* gameTime; // для вывода времени 

    void timerWorker() override; // функция потока

public:
    Timer();
    ~Timer();

    Timer(const Timer&) = delete;
    Timer& operator=(const Timer&) = delete;

    void start() override; //запустить
    void stop() override; // остановить
    void printTime() const; // вывести время 

};

#endif