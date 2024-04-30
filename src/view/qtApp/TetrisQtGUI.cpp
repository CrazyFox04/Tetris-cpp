//
// Created by Enzo Renard on 26/04/2024.
//
#include "TetrisQtGUI.h"

#include "TetrisConfiguration.h"
#include "tetrisGameOver.h"
#include "TetrisView.h"
#include <iostream>
#include "Game.h"

TetrisQtGUI::TetrisQtGUI() : settings(), gameController(){

}

int TetrisQtGUI::run(int argc, char** argv) {
    QApplication myApp = QApplication(argc, argv);
    TetrisConfiguration tetris_configuration = TetrisConfiguration(&settings);
    tetris_configuration.start(&myApp);
    gameController = std::make_shared<Game>(settings);
    gameController->start();
    TetrisView tetris_view = TetrisView(gameController);
    gameController->addObserver(tetris_view);
    tetris_view.start(&myApp);
    TetrisGameOver tetris_game_over = TetrisGameOver();
    tetris_game_over.start(&myApp);
    return myApp.exec();
}