//
// Created by Julien Delcombel on 23/04/2024.
//

#ifndef TETRIS_BOARDBOX_H
#define TETRIS_BOARDBOX_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

#include "GameController.h"

class BoardBox : public QWidget {
    std::shared_ptr<GameController> game;

public:
    explicit BoardBox(std::shared_ptr<GameController> game,QWidget *parent = nullptr);
    void update();

protected:
    void paintEvent(QPaintEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

private:
    void drawPiece(QPainter &painter);
    void drawBorders(QPainter &painter);
};

#endif //TETRIS_BOARDBOX_H
