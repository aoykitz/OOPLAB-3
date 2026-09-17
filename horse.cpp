/**
 * @file horse.cpp
 * @brief Реализация класса Horse (конь).
 */

#include "horse.h"

const Direction Horse::s_jumps[8] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

Horse::Horse(int x, int y, Color color)
    : JumpingPiece(x, y, color, "Конь") {
}

const Direction* Horse::getJumps(int& count) const {
    count = 8;
    return s_jumps;
}

std::string Horse::getType() const {
    return "Конь";
}