#include "Position.h"
#include "Direction.h"
#include <utility>

Position::Position(const int x, const int y) : x(x), y(y) {}
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
void Position::operator+=(const Position& position) {
    this->x += position.get_x();
    this->y += position.get_y();
}
bool operator==(const Position &position, const Position &position2) {
    return position.get_x() == position2.get_x() && position.get_y() == position2.get_y();
}