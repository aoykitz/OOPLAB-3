/**
 * @file king.cpp
 * @brief Реализация класса King.
 */

#include "king.h"
#include <cstdlib>  
King::King(int x, int y, Color color)
    : ChessPiece(x, y, color, "Король") {
}

bool King::canMoveTo(int x, int y) const {
    int dx = abs(x - m_x);
    int dy = abs(y - m_y);
    return (dx <= 1 && dy <= 1) && (dx != 0 || dy != 0);
}

std::string King::getType() const {
    return "Король";
}