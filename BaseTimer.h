#ifndef BASETIMER_H
#define BASETIMER_H

#include <thread>
#include <atomic>
#include <chrono>
#include <ctime>

class BaseTimer {
protected:
    std::atomic<bool> timerON; // работает ли таймер
    time_t startTime; // время начала отсчета
    std::thread workerThread; // поток

    virtual void timerWorker() = 0;

public:
    BaseTimer();
    virtual ~BaseTimer();

    BaseTimer(const BaseTimer&) = delete;
    BaseTimer& operator=(const BaseTimer&) = delete;

    virtual void start(); //старт
    virtual void stop(); //стоп

    bool ON_OFF() const; // проверка. включен ли таймер
    time_t getElapsedSeconds() const; // получить прошедшее время

protected:
    void startThread(); //запуск потока

    void stopThread(); //остановка потока
};

#endif