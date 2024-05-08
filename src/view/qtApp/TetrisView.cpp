//
// Created by Julien Delcombel on 23/04/2024.
//
#include "InfoBox.h"
#include "BoardBox.h"
#include "TetrisView.h"
#include <QWidget>
#include <iostream>
// Là je pensais que c'était bon pour afficher juste un texte centré au milieu de la fenetre pendant une seconde
// mais ça ne l'affiche pas. raise() devrait le mettre au dessus de tout, et hide() devrait le cacher
// J'ai une erreur dans la console au moment où le niveau augmente : QObject::killTimer: Timers cannot be stopped from another thread
TetrisView::TetrisView(std::shared_ptr<GameController> game) : window(), mainLayout(), myInfoBox(game, this), myBoardBox(game, this), game(game), levelUpLabel("Level Up +1", this), levelUpTimer(this), currentLevel(game->getLevel()) {
    this->game = game;
    mainLayout.addWidget(&myBoardBox);
    mainLayout.addWidget(&myInfoBox);
    window.setLayout(&mainLayout);
    levelUpLabel.setAlignment(Qt::AlignCenter);
    levelUpLabel.setStyleSheet("QLabel { color : white; font-size : 20px; }");
    levelUpLabel.raise();
    levelUpLabel.hide();
    connect(&levelUpTimer, &QTimer::timeout, [&] {
        levelUpLabel.hide();
    });
}

int TetrisView::start(QApplication *myQtApp) {
    window.show();
    return myQtApp->exec();
}

void TetrisView::update() {
    emit updateQt();
    //myInfoBox.updateQt();
    if (game->getLevel() > currentLevel) {
        currentLevel = game->getLevel();
        levelUpLabel.show();
        levelUpTimer.start(1000);
    }
    if (game->isGameOver()) {
        window.close();
    }
}

#include "moc_TetrisView.cpp"