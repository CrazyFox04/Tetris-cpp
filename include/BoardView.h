//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "Board.h"
#include <iostream>
#include <map>

class BoardView {
public:
    BoardView() {};
    void drawBoard(const Board& board) const;
};
#endif //BOARDVIEW_H
