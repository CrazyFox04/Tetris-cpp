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
    auto* tetris_configuration = new TetrisConfiguration(&settings);
    while (true) {
        tetris_configuration->start(&myApp);
        gameController = std::make_shared<Game>(settings);
        gameController->start();
        auto* tetris_view = new TetrisView(gameController);
        gameController->addObserver(tetris_view);
        tetris_view->start(&myApp);
        gameController->removeObserver(tetris_view);
        delete tetris_view;
        auto* tetris_game_over = new TetrisGameOver(gameController);
        tetris_game_over->start(&myApp);
        delete tetris_game_over;
    }
}