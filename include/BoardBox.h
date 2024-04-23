//
// Created by Julien Delcombel on 23/04/2024.
//

#ifndef TETRIS_BOARDBOX_H
#define TETRIS_BOARDBOX_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

class BoardBox : public QWidget {

public:
    explicit BoardBox(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

private:
    void drawPiece(QPainter &painter, int x, int y);
};

#endif //TETRIS_BOARDBOX_H
