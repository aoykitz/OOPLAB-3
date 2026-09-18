/**
 * @file combinedpiece.h
 * @brief Интерфейс для фигур, объединяющих несколько типов движения.
 */

#ifndef COMBINEDPIECE_H
#define COMBINEDPIECE_H

#ifdef LAB3_EXPORTS
#define LAB3_API __declspec(dllexport)
#elif defined(LAB3_STATIC)
#define LAB3_API
#else
#define LAB3_API __declspec(dllimport)
#endif

 /**
  * @class CombinedPiece
  * @brief Абстрактный интерфейс для комбинированных фигур (например, ферзь).
  *
  * Используется для множественного наследования.
  */
class LAB3_API CombinedPiece {
public:
    virtual ~CombinedPiece() = default;

    /**
     * @brief Проверяет, является ли фигура комбинированной.
     * @return true, если фигура объединяет несколько типов движения.
     */
    virtual bool isCombined() const = 0;
};

#endif 