#ifndef MOVETIMER_H
#define MOVETIMER_H 

#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>


using namespace std;

class MoveTimer {
private:
	atomic<bool> timerON; // запущен ли таймер
	time_t startTime; // время начала текущего хода
	time_t limitTime; // лимит времени
	time_t currentRemaining; // сколько осталось
	time_t totalTimeUsed; // потраченное время

	thread workerThread; // поток

	void timerWorker(); // ф-ция в отдельном потокe

public:
	MoveTimer(time_t limit = 300);
	~MoveTimer();

	MoveTimer(const MoveTimer&) = delete;
	MoveTimer& operator=(const MoveTimer&) = delete;

	void start();
	void stop();
	void reset();

	time_t getRemainingTimeSec() const; // получение оставшегося времени
	time_t getUsedTimeSec() const; // получение использованного времени

	bool ON_OFF() const; // проверка. включен ли таймер
	bool isTimeUp() const; // проверка. осталось ли время
};


#endif