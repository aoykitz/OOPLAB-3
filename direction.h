/**
 * @file direction.h
 * @brief Структура смещения по координатам.
 */

#ifndef DIRECTION_H
#define DIRECTION_H

 /**
  * @struct Direction
  * @brief Шахматное направление, задаваемое смещениями dx и dy.
  */
struct Direction {
    int dx;  ///< Изменение по горизонтали
    int dy;  ///< Изменение по вертикали
};

#endif 