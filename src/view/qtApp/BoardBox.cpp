//
// Created by Julien Delcombel on 23/04/2024.
//
#include <QLabel>
#include <iostream>
#include <QKeyEvent>
#include <QPainter>
#include "BoardBox.h"

BoardBox::BoardBox(std::shared_ptr<GameController> game, QWidget* parent) : game(), QWidget(parent) {
    this->game = game;
    setFixedSize(300, 600);
    setStyleSheet("background-color: white;");
    setFocusPolicy(Qt::StrongFocus);
}

void BoardBox::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    drawPiece(painter);
}

void BoardBox::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_Q:
            game->moveActiveTetromino(Direction::LEFT);
            std::cout << "Left" << std::endl;
            break;
        case Qt::Key_D:
            game->moveActiveTetromino(Direction::RIGHT);
            std::cout << "Right" << std::endl;
            break;
        case Qt::Key_S:
            game->moveActiveTetromino(Direction::DOWN);
            std::cout << "Down" << std::endl;
            break;
        case Qt::Key_Z:
            game->dropActiveTetromino();
            std::cout << "Drop" << std::endl;
            break;
        case Qt::Key_A:
            game->rotateActiveTetromino(Rotation::COUNTERCLOCKWISE);
            std::cout << "Rotate ccw" << std::endl;
            break;
        case Qt::Key_E:
            game->rotateActiveTetromino(Rotation::CLOCKWISE);
            std::cout << "Rotate cw" << std::endl;
            break;
        default:
            QWidget::keyPressEvent(event);
    }
    update(); // Mettre à jour le widget pour redessiner
}

void BoardBox::drawPiece(QPainter&painter) {
    for (const auto&tetromino: game->getBoard().getTetrominos()) {
        for (const auto&block: tetromino.get_relative_cells()) {
            painter.fillRect((game->getBoard().getRefPosition().get_x() + block.get_x()) * 30,
                             (game->getBoard().getRefPosition().get_y() + block.get_y()) * 30, 30, 30, Qt::red);
        }
    }
}

void BoardBox::update() {
    repaint();
}
