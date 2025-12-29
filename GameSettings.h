#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include <string>

class GameSettings {
private:
    bool randomTurnOrder;    // случайная очередь хода 
    bool timeLimitEnabled;   // вкл ли ограничение времени
    time_t timeLimitSeconds; // лимит времени (в сек)
    bool highlightMoves;

public:
    GameSettings();

    bool getRandomTurnOrder() const;
    bool getTimeLimitEnabled() const;
    time_t getTimeLimitSeconds() const;
    bool getHighlightMoves() const;

    void setRandomTurnOrder(bool random);
    void setTimeLimitEnabled(bool enabled);
    void setTimeLimitSeconds(time_t seconds);
    void setHighlightMoves(bool highlight);

};

#endif