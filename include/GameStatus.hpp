#ifndef GAMESTATUS_HPP
#define GAMESTATUS_HPP

struct GameStatus {
    int currentScore; //!< The current score.
    int currentLevel; //!< The current level.
    int currentLine; //!< The current number of lines cleared.
    int currentTime; //!< The current time.
    int difficulty; //!< The difficulty of the game.
    bool hasStarted; //!< The start flag.
    bool isOver; //!< The game over flag.

    /**
     * Construct a GameStatus object.
     */
    GameStatus() : currentScore(0), currentLevel(1), currentLine(0), currentTime(0), difficulty(1), hasStarted(false),
                   isOver(false) {
    }
};
#endif //GAMESTATUS_HPP
