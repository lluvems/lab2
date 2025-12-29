#include "piece.h"

Piece::Piece(pieceType type) : _pos(Coordinates(0, 0)), _color(color::white), _type(type) {};
Piece::Piece(Coordinates pos, color col, pieceType type) : _pos(pos), _color(col), _type(type) {};

void Piece::setPos(Coordinates pos) {
    _pos = pos;
}

void Piece::incMoves() {
    _moves++;
}

int Piece::getMoves() {
    return _moves;
}

bool Piece::isMoved() {
    if (_moves > 0) return true;
    return false;
}

Coordinates Piece::getPos() {
    if (_isAlive)
        return _pos;
    else return Coordinates(-1, -1);
}


color Piece::getColor() {
    return _color;
}

pieceType Piece::getType() {
    return _type;
}

void Piece::setDead() {
    _isAlive = false;
}

bool Piece::isAlive() {
    return _isAlive;
}

void Piece::printInfo() {
    string type, color;
    switch (getType()) {
    case pieceType::bishop:
        type = "Слон";
        break;

    case pieceType::king:
        type = "Король";
        break;

    case pieceType::knight:
        type = "Конь";
        break;

    case pieceType::pawn:
        type = "Пешка";
        break;

    case pieceType::queen:
        type = "Ферзь";
        break;

    case pieceType::rook:
        type = "Ладья";
        break;
    }

    switch (getColor()) {
    case color::white:
        color = "Белый";
        break;

    case color::black:
        color = "Черный";
        break;
    }

    cout << "Тип фигуры: " << type << endl;
    cout << "Цвет фигуры: " << color << endl;
    cout << "Текущая позиция: " << getPos() << endl;
    cout << "Живой - " << isAlive() << endl;
}