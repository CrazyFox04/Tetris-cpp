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
    Q_OBJECT
    std::shared_ptr<GameController> game;

public:
    explicit BoardBox(std::shared_ptr<GameController> game, QWidget* parent = nullptr);

public slots:
    void updateQt();

protected:
    void paintEvent(QPaintEvent* event) override;

    void keyPressEvent(QKeyEvent* event) override;

private:
    void drawPiece(QPainter&painter);

    void drawBorders(QPainter&painter);

    QColor getColor(int id);

    void blinkActiveTetromino(QPainter &painter);

    void drawTetrominoWithColor(QPainter &painter, const Tetromino &tetromino, const QColor &color);

    void blinkCompletedLine(QPainter &painter, int lineIndex);
};

#endif //TETRIS_BOARDBOX_H
