//
// Created by Enzo Renard on 12/04/2024.
//

#ifndef GAMESTATUS_HPP
#define GAMESTATUS_HPP

struct GameStatus {
    int currentScore;
    int currentLevel;
    int currentLine;
    int currentTime;
    int difficulty;
    bool hasStarted;
    bool isOver;
    int numberOfTetrominosPut;

    GameStatus() : currentScore(0), currentLevel(1), currentLine(0), currentTime(0), difficulty(1), hasStarted(false),
                   isOver(false), numberOfTetrominosPut(0) {
    }
};
#endif //GAMESTATUS_HPP
