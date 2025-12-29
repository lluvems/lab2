#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>

class InvalidMoveException {
public:
    InvalidMoveException(std::string message) : message(message) {}
    std::string getMessage() { return message; }
private:
    std::string message;
};

#endif