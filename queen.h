/**
 * @file queen.h
 * @brief Конкретная фигура "Ферзь" (множественное наследование).
 */

#ifndef QUEEN_H
#define QUEEN_H

#include "slidingpiece.h"
#include "combinedpiece.h"

#ifdef LAB3_EXPORTS
#define LAB3_API __declspec(dllexport)
#elif defined(LAB3_STATIC)
#define LAB3_API
#else
#define LAB3_API __declspec(dllimport)
#endif

 /**
  * @class Queen
  * @brief Ферзь – объединяет движение ладьи и слона.
  *
  * Наследует SlidingPiece (движение) и CombinedPiece (признак комбинированной фигуры).
  */
class LAB3_API Queen : public SlidingPiece, public CombinedPiece {
public:
    /**
     * @brief Конструктор ферзя.
     * @param x Начальная координата X.
     * @param y Начальная координата Y.
     * @param color Цвет.
     */
    Queen(int x, int y, Color color);

    /**
     * @brief Возвращает символ 'Q'.
     */
    char getSymbol() const override { return 'Q'; }

    /**
     * @brief Возвращает тип "Ферзь".
     */
    std::string getType() const override;

    /**
     * @brief Признак комбинированной фигуры.
     * @return true.
     */
    bool isCombined() const override { return true; }

protected:
    /**
     * @brief Возвращает 8 направлений (ортогонали + диагонали).
     * @param count Выходной параметр – количество направлений.
     * @return Указатель на массив Direction.
     */
    const Direction* getDirections(int& count) const override;

private:
    static const Direction s_directions[8];  ///< Направления ферзя
};

#endif 