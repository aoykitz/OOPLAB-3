/**
 * @file queen.cpp
 * @brief Реализация класса Queen.
 */

#include "queen.h"

const Direction Queen::s_directions[8] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

Queen::Queen(int x, int y, Color color)
    : SlidingPiece(x, y, color, "Ферзь") {
}

const Direction* Queen::getDirections(int& count) const {
    count = 8;
    return s_directions;
}

std::string Queen::getType() const {
    return "Ферзь";
}