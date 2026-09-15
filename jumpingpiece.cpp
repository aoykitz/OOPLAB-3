/**
 * @file jumpingpiece.cpp
 * @brief Реализация промежуточного класса JumpingPiece.
 */

#include "jumpingpiece.h"

JumpingPiece::JumpingPiece(int x, int y, Color color, const char* name)
    : ChessPiece(x, y, color, name) {
}

bool JumpingPiece::canMoveTo(int x, int y) const {
    int dx = x - m_x;
    int dy = y - m_y;
    int count = 0;
    const Direction* jumps = getJumps(count);
    for (int i = 0; i < count; ++i) {
        if (dx == jumps[i].dx && dy == jumps[i].dy)
            return true;
    }
    return false;
}

std::string JumpingPiece::getType() const {
    return "JumpingPiece";
}