//
// Created by Enzo Renard on 26/04/2024.
//
#include <iostream>
#include "TetrisQtGUI.h"

#include "TetrisConfiguration.h"
#include "tetrisGameOver.h"
#include "TetrisView.h"

TetrisQtGUI::TetrisQtGUI() : settings(), gameController(){

}

int TetrisQtGUI::run(int argc, char** argv) {
    QApplication myApp = QApplication(argc, argv);
    TetrisConfiguration tetris_configuration = TetrisConfiguration();
    tetris_configuration.start(&myApp);
    TetrisView tetris_view = TetrisView();
    tetris_view.start(&myApp);
    TetrisGameOver tetris_game_over = TetrisGameOver();
    tetris_game_over.start(&myApp);
    return myApp.exec();
}