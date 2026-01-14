#ifndef CHESSCLOCK_H
#define CHESSCLOCK_H

#include "MoveTimer.h"

class ChessClock {
private:
    MoveTimer whiteTimer; // таймер белых
    MoveTimer blackTimer; // таймер черных
    static int totalGamesPlayed;

public:
    // Конструктор с лимитом времени (по умолчанию 5 минут)
    ChessClock(time_t timeLimit = 300);

    ChessClock(const ChessClock&) = delete;
    ChessClock& operator=(const ChessClock&) = delete;

    void startWhite(); // начать ход белых
    void startBlack(); // начать ход черных
    void switchPlayer(); // переключить игрока (остановить текущего, запустить следующего)

    time_t getWhiteTime() const; // время белых в секундах
    time_t getBlackTime() const; // время черных в секундах
    bool isTimeUp() const; // проверить, не закончилось ли время у кого-то

    void reset();
    void printTime() const;

    static int getTotalGames();
    static void incrementGames();
};

#endif
