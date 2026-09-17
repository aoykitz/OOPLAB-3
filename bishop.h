/**
 * @file bishop.h
 * @brief Конкретная фигура "Слон".
 */

#ifndef BISHOP_H
#define BISHOP_H

#include "slidingpiece.h"

#ifdef LAB3_EXPORTS
#define LAB3_API __declspec(dllexport)
#elif defined(LAB3_STATIC)
#define LAB3_API
#else
#define LAB3_API __declspec(dllimport)
#endif

 /**
  * @class Bishop
  * @brief Шахматный слон – скользящая фигура, движется по диагоналям.
  */
class LAB3_API Bishop : public SlidingPiece {
public:
    /**
     * @brief Конструктор слона.
     * @param x Начальная координата X (0–7).
     * @param y Начальная координата Y (0–7).
     * @param color Цвет фигуры.
     */
    Bishop(int x, int y, Color color);

    /**
     * @brief Возвращает символ фигуры.
     * @return 'B' – международное обозначение слона.
     */
    char getSymbol() const override { return 'B'; }

    /**
     * @brief Возвращает тип фигуры.
     * @return Строка "Слон".
     */
    std::string getType() const override;

protected:
    /**
     * @brief Возвращает направления движения слона.
     * @param count Выходной параметр – количество направлений (4).
     * @return Указатель на массив из четырёх диагональных направлений.
     */
    const Direction* getDirections(int& count) const override;

private:
    static const Direction s_directions[4];  ///< Статический массив направлений слона
};

#endif 