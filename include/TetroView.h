//
// Created by Enzo Renard on 10/05/2024.
//

#ifndef TETROVIEW_H
#define TETROVIEW_H
#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QKeyEvent>

#include "GameController.h"
#include "Tetromino.h"

class TetroView : public QWidget {
    Q_OBJECT
    Q_PROPERTY(QColor color READ getCurrentColor WRITE setColor)
    Tetromino tetromino;
    std::shared_ptr<GameController> game;
    QColor color;
    bool isGhost;
    bool hasBlinked;

    QLinearGradient getGradient(int x, int y) const;
public:
    TetroView(std::shared_ptr<GameController> game, Tetromino tetromino, bool isGhost, QWidget* parent = nullptr);

    void paintEvent(QPaintEvent* event) override;

    void updateQt(Tetromino tetromino);

    void setColor(QColor color);

    void getColorFromTetro();

    void makeItBlink(int blinkTime);

    QColor getCurrentColor() const;
};
QColor getColor(Tetromino& tetromino);
#endif //TETROVIEW_H
