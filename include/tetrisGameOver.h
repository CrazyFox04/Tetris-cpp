//
// Created by Enzo Renard on 26/04/2024.
//

#ifndef TETRISGAMEOVER_H
#define TETRISGAMEOVER_H
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "GameController.h"

class TetrisGameOver : public QWidget {
    std::shared_ptr<GameController> game;
    QVBoxLayout* layout;
    QLabel* gameOverLabel;
    QLabel* detailsLabel;
    QHBoxLayout* buttonLayout;
    QPushButton* restartButton;
    QPushButton* quitButton;

    void configureWindow();
    void createItems();

public:
    TetrisGameOver(std::shared_ptr<GameController> game, QWidget *parent = nullptr);
    ~TetrisGameOver();
    int start(QApplication *myQtApp);
    void restartGame();
    void quitGame();
};
#endif //TETRISGAMEOVER_H
