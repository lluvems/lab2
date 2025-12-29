#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <atomic>
#include <chrono>
#include <ctime>

using namespace std;

class Timer {
private:
    atomic<bool> timerON; // работает ли таймер
    time_t startTime; // время начала отсчета
    tm* gameTime; // для вывода времени 

    thread workerThread; // поток
    void timerWorker(); // функция потока

public:
    Timer();
    ~Timer();

    Timer(const Timer&) = delete;
    Timer& operator=(const Timer&) = delete;

    void startTimer(); // запустить
    void stopTimer(); // остановить
    void printTime() const; // вывести время 

    time_t getElapsedSeconds() const; // получить прошедшее время
    bool ON_OFF() const; // проверка, работает ли
};

#endif