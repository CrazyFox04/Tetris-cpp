#ifndef GameSettings_HPP
#define GameSettings_HPP
#include "Board.h"

struct GameSettings {
    int boardWidth; //!< The width of the board.
    int boardHeight; //!< The height of the board.
    int startLevel; //!< The starting level
    int targetLine; //!< The target number of lines to win.
    int targetTime; //!< The target time to win.
    int targetScore; //!< The target score to win.
    int difficulty; //!< The difficulty of the game.

    /**
     * Construct a GameSettings object.
     */
    GameSettings() : boardWidth(Board::DEFAULT_WIDTH), boardHeight(Board::DEFAULT_HEIGHT), startLevel(1),
                                   targetLine(0), targetTime(0), targetScore(0), difficulty(1) {
    }
};
#endif //GameSettings_HPP
