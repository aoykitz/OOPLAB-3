/**
 * @file rook.h
 * @brief Конкретная фигура "Ладья".
 */

#ifndef ROOK_H
#define ROOK_H

#include "slidingpiece.h"

#ifdef LAB3_EXPORTS
#define LAB3_API __declspec(dllexport)
#elif defined(LAB3_STATIC)
#define LAB3_API
#else
#define LAB3_API __declspec(dllimport)
#endif

 /**
  * @class Rook
  * @brief Ладья – скользящая фигура, движется по вертикали и горизонтали.
  */
class LAB3_API Rook : public SlidingPiece {
public:
    /**
     * @brief Конструктор ладьи.
     * @param x Координата X.
     * @param y Координата Y.
     * @param color Цвет.
     */
    Rook(int x, int y, Color color);

    /**
     * @brief Возвращает символ 'R'.
     */
    char getSymbol() const override { return 'R'; }

    /**
     * @brief Возвращает тип "Ладья".
     */
    std::string getType() const override;

protected:
    /**
     * @brief Возвращает четыре ортогональных направления.
     * @param count Выходной параметр – количество направлений.
     * @return Указатель на массив Direction.
     */
    const Direction* getDirections(int& count) const override;

private:
    static const Direction s_directions[4];  ///< Направления ладьи
};

#endif 