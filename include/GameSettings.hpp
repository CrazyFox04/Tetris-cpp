//
// Created by Enzo Renard on 12/04/2024.
//

#ifndef GameSettings_HPP
#define GameSettings_HPP
#include "Board.h"

struct GameSettings {
    int boardWidth;
    int boardHeight;
    int startLevel;
    int targetLine;
    int targetTime;
    int targetScore;
    int difficulty;

    GameSettings() : boardWidth(Board::DEFAULT_WIDTH), boardHeight(Board::DEFAULT_HEIGHT), startLevel(1),
                                   targetLine(0), targetTime(0), targetScore(0), difficulty(1) {
    }
};
#endif //GameSettings_HPP
