#include "TetrisQtGUI.h"

#include "TetrisConfiguration.h"
#include "tetrisGameOver.h"
#include "TetrisView.h"
#include <iostream>
#include "Game.h"

TetrisQtGUI::TetrisQtGUI() : settings(), gameController(){

}

void TetrisQtGUI::run(int argc, char** argv) {
    QApplication myApp = QApplication(argc, argv);
    while (true) {
        TetrisConfiguration tetris_configuration = TetrisConfiguration(&settings);
        tetris_configuration.start(&myApp);
        gameController = std::make_shared<Game>(settings);
        gameController->start();
        TetrisView tetris_view = TetrisView(gameController);
        TetrisGameOver tetris_game_over = TetrisGameOver(gameController);
        gameController->addObserver(tetris_view);
        tetris_view.start(&myApp);
        tetris_game_over.start(&myApp);
    }
}