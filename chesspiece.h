/**
 * @file chesspiece.h
 * @brief Базовый абстрактный класс шахматной фигуры.
 */

#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
#include <cstring>

#ifdef LAB3_EXPORTS
#define LAB3_API __declspec(dllexport)
#elif defined(LAB3_STATIC)
#define LAB3_API
#else
#define LAB3_API __declspec(dllimport)
#endif

 /**
  * @enum Color
  * @brief Цвет шахматной фигуры.
  */
enum class Color { WHITE, BLACK };

/**
 * @class ChessPiece
 * @brief Абстрактный базовый класс для всех шахматных фигур.
 *
 * Содержит общие свойства (позиция, цвет, имя) и чисто виртуальные функции.
 * Ведёт статический подсчёт созданных фигур по цветам.
 */
class LAB3_API ChessPiece {
public:
    /**
     * @brief Конструктор с параметрами.
     * @param x Начальная координата X (0–7).
     * @param y Начальная координата Y (0–7).
     * @param color Цвет фигуры.
     * @param name Название фигуры (динамическая строка).
     */
    ChessPiece(int x, int y, Color color, const char* name);

    /**
     * @brief Конструктор копирования (глубокое копирование имени).
     * @param other Копируемый объект.
     */
    ChessPiece(const ChessPiece& other);

    /**
     * @brief Оператор присваивания (глубокое копирование).
     * @param other Объект, из которого производится присваивание.
     * @return Ссылка на текущий объект.
     */
    ChessPiece& operator=(const ChessPiece& other);

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~ChessPiece();

    /**
     * @brief Проверка возможности хода на заданную клетку (геометрия).
     * @param x Координата X цели (0–7).
     * @param y Координата Y цели (0–7).
     * @return true, если ход допустим по правилам фигуры.
     */
    virtual bool canMoveTo(int x, int y) const = 0;

    /**
     * @brief Получить символ фигуры для отображения.
     * @return char Символ ('R', 'B', 'Q', 'N', 'K').
     */
    virtual char getSymbol() const = 0;

    /**
     * @brief Виртуальная функция с реализацией по умолчанию.
     * @return std::string Тип фигуры.
     */
    virtual std::string getType() const;

    /**
     * @brief Вывод информации о фигуре на стандартный вывод.
     */
    virtual void print() const;

    /** @brief Возвращает координату X. */
    int getX() const { return m_x; }
    /** @brief Возвращает координату Y. */
    int getY() const { return m_y; }
    /** @brief Возвращает цвет фигуры. */
    Color getColor() const { return m_color; }
    /** @brief Возвращает динамическую строку с именем фигуры. */
    const char* getName() const { return m_name; }

    /** @brief Возвращает количество белых фигур. */
    static int getWhiteCount() { return s_whiteCount; }
    /** @brief Возвращает количество чёрных фигур. */
    static int getBlackCount() { return s_blackCount; }

    /**
     * @brief Статическая функция проверки состояния доски.
     *
     * Проверяет, что на доске не более одного короля каждого цвета.
     * @param pieces Массив указателей на фигуры.
     * @param count Количество фигур в массиве.
     * @return true, если состояние корректно.
     */
    static bool validateBoardState(ChessPiece* const pieces[], int count);

protected:
    int m_x;          ///< Координата X (0..7)
    int m_y;          ///< Координата Y (0..7)
    Color m_color;    ///< Цвет фигуры
    char* m_name;     ///< Динамическая строка с именем

private:
    static int s_whiteCount;  ///< Счётчик созданных белых фигур
    static int s_blackCount;  ///< Счётчик созданных чёрных фигур

    /**
     * @brief Вспомогательная функция для глубокого копирования.
     * @param other Объект, данные которого копируются.
     */
    void copyFrom(const ChessPiece& other);
};

#endif 