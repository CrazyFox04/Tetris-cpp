//
// Created by Enzo Renard on 26/04/2024.
//

#ifndef TETRISGAMEOVER_H
#define TETRISGAMEOVER_H
#include <QWidget>
#include "GameController.h"

class TetrisGameOver : public QWidget {
    std::shared_ptr<GameController> game;

    void configureWindow();
    void createItems();

public:
    TetrisGameOver(std::shared_ptr<GameController> game, QWidget *parent = nullptr);
    int start(QApplication *myQtApp);
    void restartGame();
    void quitGame();
};
#endif //TETRISGAMEOVER_H
