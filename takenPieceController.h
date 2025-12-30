#ifndef TAKENPIECECONTROLLER_H
#define TAKENPIECECONTROLLER_H

#include <memory>

#include "data.h"
#include "piece.h"

using namespace std;

class TakenPieceController {
private:
    int cutWhiteQueens;
    int cutWhiteRooks;
    int cutWhiteBishops;
    int cutWhiteKnights;
    int cutWhitePawns;

    int cutBlackQueens;
    int cutBlackRooks;
    int cutBlackBishops;
    int cutBlackKnights;
    int cutBlackPawns;

public:
    TakenPieceController();

    void initWhite();
    void initBlack();

    void cutPiece(shared_ptr<Piece> piece);

    void cutQueen(color pieceColor);
    void cutRook(color pieceColor);
    void cutBishop(color pieceColor);
    void cutKnight(color pieceColor);
    void cutPawn(color pieceColor);

    int getCutQueen(color pieceColor);
    int getCutRook(color pieceColor);
    int getCutBishop(color pieceColor);
    int getCutKnight(color pieceColor);
    int getCutPawn(color pieceColor);

    void printTakenPieces() const;

    friend string getSummary(const TakenPieceController& tpc);
};

#endif