#include "timer.h"
#include "ChessClock.h"
#include "takenPieceController.h"
#include "materialSituationController.h"
#include <iostream>
#include <chrono>
#include <locale>

int main() {
    setlocale(LC_ALL, "Russian");

    //Демонстрация таймера
    Timer gameTimer;
    std::cout << "Таймер запущен автоматически!" << std::endl;  
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Ждем 2 секунды
    gameTimer.printTime();  
    std::this_thread::sleep_for(std::chrono::seconds(4)); // Ждем еще 4 секунды
    gameTimer.printTime();

    //Демонстрация шахматных часоов
    ChessClock clock(60); // 1 минута на игрока
    clock.startWhite();
    std::cout << "Начало игры:" << std::endl;
    clock.printTime();    
    std::this_thread::sleep_for(std::chrono::seconds(10)); // Ждем 10 секунд
    clock.switchPlayer(); // Переключаем игрока
    std::cout << "\nПосле 10 секунд:" << std::endl;
    clock.printTime();
    if (clock.isTimeUp()) {
        std::cout << "\nВремя вышло!" << std::endl;
    }

    
    ChessClock::incrementGames();
    std::cout << "Total games: " << ChessClock::getTotalGames() << std::endl;

    //Демонстрация контроллера взятых фигур
    TakenPieceController controller;
    std::cout << "Начало игры:" << std::endl;
    controller.printTakenPieces();
    controller.cutQueen(color::white);   // черные взяли белого ферзя
    controller.cutPawn(color::white);    // черные взяли белую пешку
    controller.cutPawn(color::white);    // черные взяли еще одну белую пешку
    controller.cutRook(color::black);    // белые взяли черную ладью
    controller.cutKnight(color::black);  // белые взяли черного коня
    std::cout << "\nПосле нескольких ходов:" << std::endl;
    controller.printTakenPieces();

    //Демонстрация Контроллера метермльного преимущества
    auto takenController = std::make_unique<TakenPieceController>();
    takenController->cutQueen(color::white); // черные взяли белого ферзя
    takenController->cutPawn(color::white); // черные взяли белую пешку
    takenController->cutRook(color::black); // белые взяли черную ладью
    MaterialSituationController materialController(std::move(takenController));

}