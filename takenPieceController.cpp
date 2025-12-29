#include "takenPieceController.h"

TakenPieceController::TakenPieceController() {
    initWhite();
    initBlack();
}

void TakenPieceController::initWhite() {
    cutWhiteQueens = 0;
    cutWhiteRooks = 0;
    cutWhiteBishops = 0;
    cutWhiteKnights = 0;
    cutWhitePawns = 0;
}

void TakenPieceController::initBlack() {
    cutBlackQueens = 0;
    cutBlackRooks = 0;
    cutBlackBishops = 0;
    cutBlackKnights = 0;
    cutBlackPawns = 0;
}

void TakenPieceController::cutPiece(shared_ptr<Piece> piece) {
    pieceType type = piece->getType();
    color col = piece->getColor();
    switch (type)
    {
    case pieceType::queen:
        cutQueen(col);
        break;

    case pieceType::rook:
        cutRook(col);
        break;

    case pieceType::bishop:
        cutBishop(col);
        break;

    case pieceType::knight:
        cutKnight(col);
        break;

    case pieceType::pawn:
        cutPawn(col);
        break;

    default:
        break;
    }
}

void TakenPieceController::cutQueen(color pieceColor) {
    if (pieceColor == color::white) cutWhiteQueens++;
    else cutBlackQueens++;
}

void TakenPieceController::cutRook(color pieceColor) {
    if (pieceColor == color::white) cutWhiteRooks++;
    else cutBlackRooks++;
}

void TakenPieceController::cutBishop(color pieceColor) {
    if (pieceColor == color::white) cutWhiteBishops++;
    else cutBlackBishops++;
}

void TakenPieceController::cutKnight(color pieceColor) {
    if (pieceColor == color::white) cutWhiteKnights++;
    else cutBlackKnights++;
}

void TakenPieceController::cutPawn(color pieceColor) {
    if (pieceColor == color::white) cutWhitePawns++;
    else cutBlackPawns++;
}

int TakenPieceController::getCutQueen(color pieceColor) {
    if (pieceColor == color::white) return cutWhiteQueens;
    else return cutBlackQueens;
}

int TakenPieceController::getCutRook(color pieceColor) {
    if (pieceColor == color::white) return cutWhiteRooks;
    else return cutBlackRooks;
}

int TakenPieceController::getCutBishop(color pieceColor) {
    if (pieceColor == color::white) return cutWhiteBishops;
    else return cutBlackBishops;
}

int TakenPieceController::getCutKnight(color pieceColor) {
    if (pieceColor == color::white) return cutWhiteKnights;
    else return cutBlackKnights;
}

int TakenPieceController::getCutPawn(color pieceColor) {
    if (pieceColor == color::white) return cutWhitePawns;
    else return cutBlackPawns;
}

void TakenPieceController::printTakenPieces() const {
    cout << "Взятые фигуры:" << endl;
    cout << "Белые (взятые черными): ";
    cout << "Ферзи:" << cutWhiteQueens << " ";
    cout << "Ладьи:" << cutWhiteRooks << " ";
    cout << "Слоны:" << cutWhiteBishops << " ";
    cout << "Кони:" << cutWhiteKnights << " ";
    cout << "Пешки:" << cutWhitePawns << endl;

    cout << "Черные (взятые белыми): ";
    cout << "Ферзи:" << cutBlackQueens << " ";
    cout << "Ладьи:" << cutBlackRooks << " ";
    cout << "Слоны:" << cutBlackBishops << " ";
    cout << "Кони:" << cutBlackKnights << " ";
    cout << "Пешки:" << cutBlackPawns << endl;
}