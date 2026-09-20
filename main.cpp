/**
 * @file main.cpp
 * @brief лабораторная работа 3.
 *
 * Демонстрирует все требования: полиморфизм, статические члены,
 * глубокое копирование, множественное наследование.
 */

#include <iostream>
#include <clocale>
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "horse.h"
#include "king.h"

 /**
  * @brief Точка входа.
  */
int main() {
    std::setlocale(LC_ALL, "Russian");

    std::cout << "\nЛАБОРАТОРНАЯ РАБОТА №3. Шахматные фигуры";

    // 1. Фигуры
    std::cout << "1. Исходные фигуры:\n";
    Rook  wr(0, 0, Color::WHITE);
    Bishop bb(2, 0, Color::BLACK);
    Queen wq(3, 0, Color::WHITE);
    Horse bh(1, 0, Color::BLACK);
    King  wk(4, 0, Color::WHITE);
    ChessPiece* board[] = { &wr, &bb, &wq, &bh, &wk };
    for (int i = 0; i < 5; ++i) {
        std::cout << "   " << board[i]->getSymbol() << "  "
            << board[i]->getType() << "  "
            << char('a' + board[i]->getX()) << board[i]->getY() + 1 << "\n";
    }

    // 2. Статические счётчики
    std::cout << "\n2. Статические счётчики:\n";
    std::cout << "   Белых: " << ChessPiece::getWhiteCount()
        << ", чёрных: " << ChessPiece::getBlackCount() << "\n";

    // 3. Полиморфная проверка ходов
    std::cout << "\n3. Полиморфная проверка ходов:\n";
    int targets[3][2] = { {0,2}, {5,2}, {5,0} };
    for (int t = 0; t < 3; ++t) {
        int tx = targets[t][0], ty = targets[t][1];
        std::cout << "   " << char('a' + tx) << ty + 1 << ": ";
        for (int i = 0; i < 5; ++i)
            std::cout << board[i]->getSymbol() << (board[i]->canMoveTo(tx, ty) ? "+ " : "- ");
        std::cout << "\n";
    }

    // 4. Виртуальная getType()
    std::cout << "\n4. Виртуальная функция getType():\n";
    std::cout << "   ";
    for (int i = 0; i < 5; ++i)
        std::cout << board[i]->getSymbol() << ":" << board[i]->getType() << "  ";
    std::cout << "\n";

    // 5. Множественное наследование
    std::cout << "\n5. Множественное наследование (Queen):\n";
    CombinedPiece* cp = &wq;
    std::cout << "   Queen объединяет SlidingPiece и CombinedPiece.\n";
    std::cout << "   isCombined() = " << (cp->isCombined() ? "true" : "false") << "\n";

    // 6. Статическая проверка доски
    std::cout << "\n6. Статическая проверка состояния доски:\n";
    ChessPiece* valid[] = { &wk, &bb };
    std::cout << "   Один король: "
        << (ChessPiece::validateBoardState(valid, 2) ? "корректно" : "ошибка") << "\n";
    King wk2(7, 7, Color::WHITE);
    ChessPiece* invalid[] = { &wk, &wk2 };
    std::cout << "   Два белых короля: "
        << (ChessPiece::validateBoardState(invalid, 2) ? "корректно" : "ошибка") << "\n";

    // 7. Глубокое копирование и присваивание
    std::cout << "\n7. Глубокое копирование и присваивание:\n";
    Rook wrCopy(wr);
    std::cout << "   Ладья (копия): " << wrCopy.getName()
        << " (оригинал: " << wr.getName() << ") – копии независимы.\n";
    Queen q1(0, 0, Color::BLACK);
    Queen q2(7, 7, Color::BLACK);
    q2 = q1;
    std::cout << "   Ферзь (присваивание): " << q2.getName()
        << " (оригинал: " << q1.getName() << ") – копии независимы.\n";

    std::cout << "\nВсе требования выполнены.";

    return 0;
}