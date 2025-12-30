#include "materialSituationController.h"

MaterialSituationController::MaterialSituationController(std::unique_ptr<TakenPieceController> tpc)
    : tpController(std::move(tpc)), whiteTakenPieces(0), blackTakenPieces(0), totalTakenPieces(0) {
}
// уставновить кол-во взятых белых
void MaterialSituationController::setWhiteTakenPieces(int n) {
    whiteTakenPieces = n;
}

// уставновить кол-во взятых черных
void MaterialSituationController::setBlackTakenPieces(int n) {
    blackTakenPieces = n;
}

// посчитать общее кол-во
void MaterialSituationController::countTotalTakenPieces() {
    totalTakenPieces = getWhiteTakenPieces() + getBlackTakenPieces();
}

// обновить данные
void MaterialSituationController::updateSituation() {
    setWhiteTakenPieces(tpController->getCutBishop(color::white) + tpController->getCutKnight(color::white) + tpController->getCutPawn(color::white)\
        + tpController->getCutQueen(color::white) + tpController->getCutRook(color::white));

    setBlackTakenPieces(tpController->getCutBishop(color::black) + tpController->getCutKnight(color::black) + tpController->getCutPawn(color::black)\
        + tpController->getCutQueen(color::black) + tpController->getCutRook(color::black));

    countTotalTakenPieces();
}

// получить кол-во взятых белых
int MaterialSituationController::getWhiteTakenPieces() {
    return whiteTakenPieces;
}

// получить кол-во взятых черных
int MaterialSituationController::getBlackTakenPieces() {
    return blackTakenPieces;
}

// получить общее кол-во
int MaterialSituationController::getTotalTakenPieces() {
    return totalTakenPieces;
}

// ывывод
void MaterialSituationController::printMaterialSituation() const {
    MaterialSituationController* nonConstThis = const_cast<MaterialSituationController*>(this);
    nonConstThis->updateSituation();

    std::cout << "=== МАТЕРИАЛЬНОЕ ПОЛОЖЕНИЕ ===" << std::endl;
    std::cout << "Всего взято фигур: " << totalTakenPieces << std::endl;
    std::cout << "Белых фигур взято: " << whiteTakenPieces << std::endl;
    std::cout << "Черных фигур взято: " << blackTakenPieces << std::endl;

    int advantage = blackTakenPieces - whiteTakenPieces;

    std::string status;
    if (advantage > 0)
        status = "Материальное преимущество у БЕЛЫХ: +" + std::to_string(advantage);
    else if (advantage < 0)
        status = "Материальное преимущество у ЧЕРНЫХ: +" + std::to_string(-advantage);
    else
        status = "Материальное равенство";

    std::cout << status << std::endl;
}