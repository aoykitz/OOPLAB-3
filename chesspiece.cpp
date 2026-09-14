/**
 * @file chesspiece.cpp
 * @brief Реализация базового класса ChessPiece.
 */

#include "chesspiece.h"

int ChessPiece::s_whiteCount = 0;
int ChessPiece::s_blackCount = 0;

ChessPiece::ChessPiece(int x, int y, Color color, const char* name)
    : m_x(x), m_y(y), m_color(color), m_name(nullptr)
{
    size_t len = std::strlen(name) + 1;
    m_name = new char[len];
    strcpy_s(m_name, len, name);   

    if (color == Color::WHITE)
        ++s_whiteCount;
    else
        ++s_blackCount;
}

ChessPiece::ChessPiece(const ChessPiece& other)
    : m_x(other.m_x), m_y(other.m_y), m_color(other.m_color), m_name(nullptr)
{
    size_t len = std::strlen(other.m_name) + 1;
    m_name = new char[len];
    strcpy_s(m_name, len, other.m_name);

    if (m_color == Color::WHITE)
        ++s_whiteCount;
    else
        ++s_blackCount;
}

ChessPiece& ChessPiece::operator=(const ChessPiece& other) {
    if (this != &other) {
        if (m_color == Color::WHITE) --s_whiteCount;
        else --s_blackCount;

        m_x = other.m_x;
        m_y = other.m_y;
        m_color = other.m_color;

        delete[] m_name;
        size_t len = std::strlen(other.m_name) + 1;
        m_name = new char[len];
        strcpy_s(m_name, len, other.m_name);

        if (m_color == Color::WHITE) ++s_whiteCount;
        else ++s_blackCount;
    }
    return *this;
}

ChessPiece::~ChessPiece() {
    if (m_color == Color::WHITE)
        --s_whiteCount;
    else
        --s_blackCount;
    delete[] m_name;
}

std::string ChessPiece::getType() const {
    return "ChessPiece";
}

void ChessPiece::print() const {
    std::cout << getSymbol() << " (" << m_name << ") на "
        << char('a' + m_x) << (m_y + 1);
}

bool ChessPiece::validateBoardState(ChessPiece* const pieces[], int count) {
    int whiteKings = 0, blackKings = 0;
    for (int i = 0; i < count; ++i) {
        if (pieces[i]->getSymbol() == 'K') {
            if (pieces[i]->getColor() == Color::WHITE)
                ++whiteKings;
            else
                ++blackKings;
        }
    }
    return (whiteKings <= 1 && blackKings <= 1);
}