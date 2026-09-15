/**
 * @file slidingpiece.h
 * @brief Промежуточный класс для скользящих фигур.
 */

#ifndef SLIDINGPIECE_H
#define SLIDINGPIECE_H

#include "chesspiece.h"
#include "direction.h"

#ifdef LAB3_EXPORTS
#define LAB3_API __declspec(dllexport)
#elif defined(LAB3_STATIC)
#define LAB3_API
#else
#define LAB3_API __declspec(dllimport)
#endif

 /**
  * @class SlidingPiece
  * @brief Фигура, движущаяся по прямым или диагоналям на любое количество клеток.
  */
class LAB3_API SlidingPiece : public ChessPiece {
public:
    /**
     * @brief Конструктор.
     * @param x Координата X.
     * @param y Координата Y.
     * @param color Цвет.
     * @param name Имя фигуры.
     */
    SlidingPiece(int x, int y, Color color, const char* name);

    /**
     * @brief Проверка хода для скользящих фигур.
     *
     * Ход допустим, если целевая клетка лежит на одном из направлений
     * и путь не заблокирован (упрощённо – любое расстояние).
     * @param x Целевая координата X.
     * @param y Целевая координата Y.
     * @return true, если ход возможен.
     */
    bool canMoveTo(int x, int y) const override;

    /**
     * @brief Возвращает строку "SlidingPiece".
     */
    std::string getType() const override;

protected:
    /**
     * @brief Возвращает направления движения конкретной фигуры.
     * @param count Выходной параметр – количество направлений.
     * @return Указатель на массив Direction.
     */
    virtual const Direction* getDirections(int& count) const = 0;
};

#endif 