//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef DIRECTION_H
#define DIRECTION_H
#include <utility>
using Direction2D = std::pair<int,int>;
struct Direction {
    static const Direction2D RIGHT;
    static const Direction2D DOWN;
    static const Direction2D LEFT;
};
#endif //DIRECTION_H
