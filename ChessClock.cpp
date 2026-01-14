#include "ChessClock.h"

using namespace std;

ChessClock::ChessClock(time_t timeLimit)
    : whiteTimer(timeLimit)
    , blackTimer(timeLimit)
{
}

void ChessClock::startWhite() {
    blackTimer.stop(); // останавливаем черных 
    whiteTimer.start(); // запускаем белых
}

void ChessClock::startBlack() {
    whiteTimer.stop(); // останавливаем белых
    blackTimer.start(); // запускаем черных
}

// Переключить игрока
void ChessClock::switchPlayer() {
    if (whiteTimer.ON_OFF()) {
        startBlack();
    }
    else if (blackTimer.ON_OFF()) {
        startWhite();
    }
    else {
        // Если никто не ходит, начинаем с белых
        startWhite();
    }
}

time_t ChessClock::getWhiteTime() const {
    return whiteTimer.getRemainingTimeSec();
}

time_t ChessClock::getBlackTime() const {
    return blackTimer.getRemainingTimeSec();
}

bool ChessClock::isTimeUp() const {
    return whiteTimer.isTimeUp() || blackTimer.isTimeUp();
}

void ChessClock::reset() {
    whiteTimer.reset();
    blackTimer.reset();
}

void ChessClock::printTime() const {
    time_t whiteSeconds = whiteTimer.getRemainingTimeSec();
    time_t blackSeconds = blackTimer.getRemainingTimeSec();

    int whiteMinutes = whiteSeconds / 60;
    int whiteSecs = whiteSeconds % 60;

    int blackMinutes = blackSeconds / 60;
    int blackSecs = blackSeconds % 60;

    cout << "=== Время игроков ===" << endl;
    cout << "Белые: "
        << (whiteMinutes < 10 ? "0" : "") << whiteMinutes << ":"
        << (whiteSecs < 10 ? "0" : "") << whiteSecs;
    if (whiteTimer.ON_OFF()) cout << " [ХОДИТ]";
    cout << endl;

    cout << "Черные: "
        << (blackMinutes < 10 ? "0" : "") << blackMinutes << ":"
        << (blackSecs < 10 ? "0" : "") << blackSecs;
    if (blackTimer.ON_OFF()) cout << " [ХОДИТ]";
    cout << endl;
}

int ChessClock::totalGamesPlayed = 0;

int ChessClock::getTotalGames() {
    return totalGamesPlayed;
}

void ChessClock::incrementGames() {
    ++totalGamesPlayed;
}