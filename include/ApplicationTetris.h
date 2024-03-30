#ifndef TETRIS_APPLICATIONTETRIS_H
#define TETRIS_APPLICATIONTETRIS_H

#include "Game.h"
#include "GameController.h"
#include "Invoker.h"
#include "GameView.h"

class ApplicationTetris {
    Game game;
    std::unique_ptr<GameController> gameController;
    Invoker invoker;
    GameView gameView;

    void initializeCommands();
    void handleInput();
public:
    ApplicationTetris();
    void run();
};

#endif //TETRIS_APPLICATIONTETRIS_H
