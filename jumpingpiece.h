/**
 * @file jumpingpiece.h
 * @brief Промежуточный класс для прыгающих фигур.
 */

#ifndef JUMPINGPIECE_H
#define JUMPINGPIECE_H

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
  * @class JumpingPiece
  * @brief Фигура, перемещающаяся фиксированным прыжком (например, конь).
  */
class LAB3_API JumpingPiece : public ChessPiece {
public:
    /**
     * @brief Конструктор.
     * @param x Координата X.
     * @param y Координата Y.
     * @param color Цвет.
     * @param name Имя фигуры.
     */
    JumpingPiece(int x, int y, Color color, const char* name);

    /**
     * @brief Проверка хода для прыгающих фигур.
     * @param x Целевая координата X.
     * @param y Целевая координата Y.
     * @return true, если ход соответствует одному из прыжков.
     */
    bool canMoveTo(int x, int y) const override;

    /**
     * @brief Возвращает строку "JumpingPiece".
     * @return Тип фигуры.
     */
    std::string getType() const override;

protected:
    /**
     * @brief Чисто виртуальная функция, возвращающая массив прыжков.
     * @param count Выходной параметр – количество прыжков.
     * @return Указатель на статический массив Direction.
     */
    virtual const Direction* getJumps(int& count) const = 0;
};

#endif 