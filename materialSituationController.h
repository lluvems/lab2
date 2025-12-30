#ifndef MATERIALSITUATIONCONTROLLER_H
#define MATERIALSITUATIONCONTROLLER_H

#include "takenPieceController.h"

class MaterialSituationController {
private:
    std::unique_ptr<TakenPieceController> tpController;
    int whiteTakenPieces; //белых фигур взято
    int blackTakenPieces; //черных фигур взято
    int totalTakenPieces; //всего взято

public:
    MaterialSituationController(std::unique_ptr<TakenPieceController> tpc);

    void updateSituation(); //обновить данные

    void setWhiteTakenPieces(int n); //уставновить кол-во взятых белых

    void setBlackTakenPieces(int n); //установить кол-во взятых черных

    void countTotalTakenPieces(); //посчитать общее кол-во

    int getWhiteTakenPieces(); //получить кол-во взятых белых

    int getBlackTakenPieces(); //получить кол-во взятых черных

    int getTotalTakenPieces(); //получить общее кол-во

    void printMaterialSituation() const; //вывод

};

#endif