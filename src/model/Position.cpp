//
// Created by Enzo Renard on 05/03/2024.
//
#include "Position.h"
#include "Direction.h"
#include <utility>

Position::Position(int x, int y) : x(x), y(y) {}
Position operator+(const Position &position, const Direction2D& direction) {
    return {position.get_x() + direction.first, position.get_y() + direction.second};
}
Position operator+(const Direction2D& direction, const Position &position) {
    return position + direction;
}
Position operator-(const Position &position, const Direction2D& direction) {
    return {position.get_x() - direction.first, position.get_y() - direction.second};
}
Position operator-(const Direction2D& direction, const Position &position) {
    return position - direction;
}
void Position::operator+=(const Direction2D& direction) {
    this->x += direction.first;
    this->y += direction.second;
}
void Position::operator-=(const Direction2D& direction) {
    this->x -= direction.first;
    this->y -= direction.second;
}