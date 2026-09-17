/**
 * @file king.h
 * @brief Конкретная фигура "Король".
 */

#ifndef KING_H
#define KING_H

#include "chesspiece.h"

#ifdef LAB3_EXPORTS
#define LAB3_API __declspec(dllexport)
#elif defined(LAB3_STATIC)
#define LAB3_API
#else
#define LAB3_API __declspec(dllimport)
#endif

 /**
  * @class King
  * @brief Шахматный король – ходит на одну клетку в любом направлении.
  */
class LAB3_API King : public ChessPiece {
public:
    /**
     * @brief Конструктор короля.
     * @param x Координата X.
     * @param y Координата Y.
     * @param color Цвет.
     */
    King(int x, int y, Color color);

    /**
     * @brief Возвращает символ 'K'.
     */
    char getSymbol() const override { return 'K'; }

    /**
     * @brief Проверка хода короля (на одну клетку).
     * @param x Целевая координата X.
     * @param y Целевая координата Y.
     * @return true, если перемещение не более чем на 1 по каждой оси.
     */
    bool canMoveTo(int x, int y) const override;

    /**
     * @brief Возвращает тип "Король".
     */
    std::string getType() const override;
};

#endif 