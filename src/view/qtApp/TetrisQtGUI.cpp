#include "TetrisQtGUI.h"

#include "TetrisConfiguration.h"
#include "tetrisGameOver.h"
#include "TetrisView.h"
#include <iostream>
#include "Game.h"

TetrisQtGUI::TetrisQtGUI() : wantToExit(false), settings(), gameController(std::make_shared<Game>(settings)) {
}

void TetrisQtGUI::run(int argc, char** argv) {
    QApplication* myApp = new QApplication(argc, argv);
    tetris_configuration = new TetrisConfiguration(&settings);
    //gameController->start();
    tetris_view = new TetrisView(gameController);
    tetris_game_over = new TetrisGameOver(gameController);
    myApp->setQuitOnLastWindowClosed(false);
    configureEndOfConfiguration();
    myApp->exec();
    delete myApp;
}

void TetrisQtGUI::configureEndOfConfiguration() {
    QObject::connect(tetris_configuration, &QObject::destroyed, [=]() mutable {
        if (wantToExit) {
            QApplication::quit();
        }
        else {
            gameController = std::make_shared<Game>(settings);
            gameController->start();
            tetris_view = new TetrisView(gameController);
            gameController->addObserver(tetris_view);
            tetris_view->show();
            configureEndOfGame();
        }
    });
    QObject::connect(tetris_configuration, &TetrisConfiguration::exitGame, [=]() mutable {
        wantToExit = true;
    });
    tetris_configuration->show();
}

void TetrisQtGUI::configureEndOfGame() {
    QObject::connect(tetris_view, &QObject::destroyed, [=]()mutable {
        tetris_game_over = new TetrisGameOver(gameController);
        tetris_game_over->show();
        configureEndOfGameOver();
    });
}

void TetrisQtGUI::configureEndOfGameOver() {
    QObject::connect(tetris_game_over, &QObject::destroyed, [=]() mutable {
        if (wantToExit) {
            QApplication::quit();
        }
        else {
            tetris_configuration = new TetrisConfiguration(&settings);
            tetris_configuration->show();
            configureEndOfConfiguration();
        }
    });
    QObject::connect(tetris_game_over, &TetrisGameOver::exitGame, [=]() mutable {
        wantToExit = true;
    });
}
