//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef BAGVIEW_H
#define BAGVIEW_H

#include "Tetromino.h"
#include <iostream>

class BagView {
public:
     BagView() {};
     void drawNextTetromino(const Tetromino& tetromino);
};
#endif //BAGVIEW_H
