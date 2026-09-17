/**
 * @file horse.h
 * @brief Конкретная фигура "Конь".
 */

#ifndef HORSE_H
#define HORSE_H

#include "jumpingpiece.h"

#ifdef LAB3_EXPORTS
#define LAB3_API __declspec(dllexport)
#elif defined(LAB3_STATIC)
#define LAB3_API
#else
#define LAB3_API __declspec(dllimport)
#endif

 /**
  * @class Horse
  * @brief Шахматный конь – прыгающая фигура, ходит буквой "Г".
  */
class LAB3_API Horse : public JumpingPiece {
public:
    /**
     * @brief Конструктор коня.
     * @param x Начальная координата X (0–7).
     * @param y Начальная координата Y (0–7).
     * @param color Цвет фигуры.
     */
    Horse(int x, int y, Color color);

    /**
     * @brief Возвращает символ фигуры.
     * @return 'N' – международное обозначение коня.
     */
    char getSymbol() const override { return 'N'; }

    /**
     * @brief Возвращает тип фигуры.
     * @return Строка "Конь".
     */
    std::string getType() const override;

protected:
    /**
     * @brief Возвращает возможные прыжки коня.
     * @param count Выходной параметр – количество прыжков (8).
     * @return Указатель на массив из восьми смещений.
     */
    const Direction* getJumps(int& count) const override;

private:
    static const Direction s_jumps[8];  ///< Статический массив прыжков коня
};

#endif 