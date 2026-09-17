/**
 * @file bishop.cpp
 * @brief Реализация класса Bishop.
 */

#include "bishop.h"

const Direction Bishop::s_directions[4] = {
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

Bishop::Bishop(int x, int y, Color color)
    : SlidingPiece(x, y, color, "Слон") {
}

const Direction* Bishop::getDirections(int& count) const {
    count = 4;
    return s_directions;
}

std::string Bishop::getType() const {
    return "Слон";
}