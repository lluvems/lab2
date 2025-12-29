#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>

#include "exceptions.h"

using namespace std;

#define BOARD_MAX_X 7
#define BOARD_MAX_Y 7

//координаты
struct Coordinates {
private:
    int x;
    int y;

public:
    Coordinates() : x(0), y(0) {} //конструктор без параметров
    Coordinates(int x, int y) : x(x), y(y) {} //конструктор с координатами
    Coordinates(const Coordinates& c) : x(c.x), y(c.y) {}

    int getX() { return x; }; //получение координаты X
    int getY() { return y; }; //получение координаты Y

    static Coordinates toCoord(string str) {
        if (str.length() == 2) {
            int x = toupper(str[0]) - 'A';
            int y = str[1] - '0' - 1;
            if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
                return Coordinates(x, y);
            throw InvalidMoveException("Координаты " + str + " вне доски");
        }
        throw InvalidMoveException("Неверный ввод. Координаты должны быть вида a1");
    }
    //перегрузка оператора +
    Coordinates operator+(const Coordinates& coord) const {
        int x, y;
        x = this->x + coord.x;
        y = this->y + coord.y;
        return Coordinates(x, y);
    }

    //перегрузка оператора -
    Coordinates operator-(const Coordinates& coord) const {
        int x, y;
        x = this->x - coord.x;
        y = this->y - coord.y;
        return Coordinates(x, y);
    }

    //перегрузка оператора *
    Coordinates operator* (const int& n) const {
        int x, y;
        x = this->x * n;
        y = this->y * n;
        return Coordinates(x, y);
    }

    //перегрузка оператора ==
    bool operator==(const Coordinates& coord) const {
        if (x == coord.x && y == coord.y)
            return true;
        return false;
    }

    //перегрузка оператора +=
    Coordinates& operator+=(const Coordinates coord) {
        x += coord.x;
        y += coord.y;
        return *this;
    }

    //перегрузка оператора <<
    friend ostream& operator<<(std::ostream& os, const Coordinates& c) {
        return os << static_cast<char>('A' + c.x) << c.y + 1;
    }

    //перегрузка оператора <<
    friend istream& operator>>(std::istream& in, Coordinates& c) {
        string str;
        in >> str;
        c = toCoord(str);
        return in;
    }

    //проверка принадлежности координат доске
    bool checkBound() {
        if (x < 0 || x > BOARD_MAX_X || y < 0 || y > BOARD_MAX_Y)
            return false;
        return true;
    }
};

//типы фигур
enum class pieceType {
    king, //король
    queen, //ферзь
    rook, //ладья
    bishop, //слон
    knight, //конь
    pawn //пешка
};

//цвет фигур
enum class color {
    black, //черный
    white //белый
};

#endif