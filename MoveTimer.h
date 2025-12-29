#ifndef MOVETIMER_H
#define MOVETIMER_H 

#include "BaseTimer.h"

#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>



using namespace std;

class MoveTimer : public BaseTimer {
private:
	time_t limitTime; // лимит времени
	time_t currentRemaining; // сколько осталось
	time_t totalTimeUsed; // потраченное время

	void timerWorker() override; // ф-ция в отдельном потокe

public:
	MoveTimer(time_t limit = 300);
	~MoveTimer();

	MoveTimer(const MoveTimer&) = delete;
	MoveTimer& operator=(const MoveTimer&) = delete;

	void start() override; //старт
	void stop() override; //стоп
	void reset(); //ресет

	time_t getRemainingTimeSec() const; // получение оставшегося времени
	time_t getUsedTimeSec() const; // получение использованного времени
	bool isTimeUp() const; // проверка. осталось ли время
};


#endif