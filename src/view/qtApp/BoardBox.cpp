//
// Created by Julien Delcombel on 23/04/2024.
//
#include <QLabel>
#include <iostream>
#include <QKeyEvent>
#include <QPainter>
#include "BoardBox.h"

BoardBox::BoardBox(std::shared_ptr<GameController> game, QWidget *parent) : game(), QWidget(parent) {
    this->game = game;
    setFixedSize(300, 600);
    setStyleSheet("background-color: white;");
    setFocusPolicy(Qt::StrongFocus);
}

void BoardBox::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    painter.drawRect(10, 10, 100, 100); // Exemple de dessin d'un rectangle
}

void BoardBox::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Q:
            std::cout << "Left" << std::endl;
            break;
        case Qt::Key_D:
            std::cout << "Right" << std::endl;
            break;
        case Qt::Key_S:
            std::cout << "Down" << std::endl;
            break;
        case Qt::Key_Z:
            game->dropActiveTetromino();
            std::cout << "Drop" << std::endl;
            break;
        default:
            QWidget::keyPressEvent(event);
    }
    update(); // Mettre à jour le widget pour redessiner
}

void BoardBox::drawPiece(QPainter &painter, int x, int y) {
    // Dessiner une pièce de Tetris ou autre
    painter.fillRect(x, y, 30, 30, Qt::red);
}

void BoardBox::update() {
   repaint();
}