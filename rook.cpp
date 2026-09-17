/**
 * @file rook.cpp
 * @brief Реализация класса Rook.
 */

#include "rook.h"

const Direction Rook::s_directions[4] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

Rook::Rook(int x, int y, Color color)
    : SlidingPiece(x, y, color, "Ладья") {
}

const Direction* Rook::getDirections(int& count) const {
    count = 4;
    return s_directions;
}

std::string Rook::getType() const {
    return "Ладья";
}