#ifndef PIECE_H
#define PIECE_H

#include "data.h"
#include "vector"
#include "iostream"

using namespace std;

class Piece {
private:
    vector<Coordinates> pattern;
    bool _isAlive = true; //состояние
    color _color; //цвет
    pieceType _type; //тип
    Coordinates _pos; //координаты
    int _moves = 0;

public:
    Piece(pieceType type);
    Piece(Coordinates pos, color col, pieceType type);

    //установить координаты фигуры
    void setPos(Coordinates pos);

    void incMoves();
    int getMoves();
    bool isMoved();

    virtual vector<Coordinates> getPattern() = 0;

    //получение координаты фигуры
    Coordinates getPos();

    //получить цвет фигуры
    color getColor();

    //получить тип фигуры
    pieceType getType();

    //пометка уничтожения фигуры
    void setDead();

    bool isAlive();

    void printInfo();
};

#endif