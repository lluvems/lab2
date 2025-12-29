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
    randomTurnOrder = random;
}

void GameSettings::setTimeLimitEnabled(bool enabled) {
    timeLimitEnabled = enabled;
}

void GameSettings::setTimeLimitSeconds(time_t seconds) {
    timeLimitSeconds = seconds;
}

void GameSettings::setHighlightMoves(bool highlight) {
    highlightMoves = highlight;
}


