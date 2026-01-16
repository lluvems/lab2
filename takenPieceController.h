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

    virtual void printTakenPieces() const;

    friend string getSummary(const TakenPieceController& tpc);

    bool operator==(const TakenPieceController& other) const;
    TakenPieceController& operator+=(const TakenPieceController& other);
    friend std::ostream& operator<<(std::ostream& os, const TakenPieceController& tpc);
};

class AdvancedTakenPieceController : public TakenPieceController {
private:
    std::string ownerName;
public:
    AdvancedTakenPieceController(const std::string& name);
    AdvancedTakenPieceController(const AdvancedTakenPieceController& other); // глубокое копирование
    AdvancedTakenPieceController& operator=(const AdvancedTakenPieceController& other);

    // Запретим копирование через базовый класс напрямую
    AdvancedTakenPieceController& operator=(const TakenPieceController& base) = delete;

    // Перегрузка метода с вызовом базового
    void printTakenPieces() const override;

    // Новый метод — перегрузка без вызова базового
    void printSummaryOnly() const;

    // Клонирование
    AdvancedTakenPieceController* shallowClone() const;
    AdvancedTakenPieceController* deepClone() const;
};

#endif