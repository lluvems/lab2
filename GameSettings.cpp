#include "GameSettings.h"
#include <sstream>

// Настройки по умолчанию
GameSettings::GameSettings() {
    randomTurnOrder = false;
    timeLimitEnabled = false;
    highlightMoves = true;
    timeLimitSeconds = 0;

}

bool GameSettings::getRandomTurnOrder() const {
    return randomTurnOrder;
}

bool GameSettings::getTimeLimitEnabled() const {
    return timeLimitEnabled;
}

time_t GameSettings::getTimeLimitSeconds() const {
    return timeLimitSeconds;
}

bool GameSettings::getHighlightMoves() const {
    return highlightMoves;
}

void GameSettings::setRandomTurnOrder(bool random) {
    this->randomTurnOrder = random;
}

void GameSettings::setTimeLimitEnabled(bool enabled) {
    this->timeLimitEnabled = enabled;
}

void GameSettings::setTimeLimitSeconds(time_t seconds) {
    this->timeLimitSeconds = seconds;
}

void GameSettings::setHighlightMoves(bool highlight) {
    this->highlightMoves = highlight;
}


