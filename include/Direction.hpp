//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef DIRECTION_H
#define DIRECTION_H
using Direction2D = std::pair<int,int>;
struct Direction {
    static const Direction2D RIGHT;
    static const Direction2D DOWN;
    static const Direction2D LEFT;
};
const Direction2D Direction::RIGHT = std::make_pair(1,0);
const Direction2D Direction::DOWN = std::make_pair(0,-1);
const Direction2D Direction::LEFT = std::make_pair(-1,0);
#endif //DIRECTION_H
