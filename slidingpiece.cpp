/**
 * @file slidingpiece.cpp
 * @brief Реализация класса SlidingPiece.
 */

#include "slidingpiece.h"

SlidingPiece::SlidingPiece(int x, int y, Color color, const char* name)
    : ChessPiece(x, y, color, name) {
}

bool SlidingPiece::canMoveTo(int x, int y) const {
    int dx = x - m_x;
    int dy = y - m_y;
    if (dx == 0 && dy == 0) return false;

    int dirCount = 0;
    const Direction* dirs = getDirections(dirCount);

    for (int i = 0; i < dirCount; ++i) {
        int ddx = dirs[i].dx;
        int ddy = dirs[i].dy;
        if (ddx == 0) {
            if (dx != 0 || dy / ddy <= 0) continue;
            if (dy % ddy == 0) return true;
        }
        else if (ddy == 0) {
            if (dy != 0 || dx / ddx <= 0) continue;
            if (dx % ddx == 0) return true;
        }
        else {
            if (dx * ddy == dy * ddx && dx / ddx > 0) return true;
        }
    }
    return false;
}

std::string SlidingPiece::getType() const {
    return "SlidingPiece";
}