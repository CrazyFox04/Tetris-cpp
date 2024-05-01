//
// Created by Enzo Renard on 26/04/2024.
//

#ifndef NEXTTETROWIDGET_H
#define NEXTTETROWIDGET_H
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

#include "GameController.h"

class NextTetroWidget : public QWidget {
    std::shared_ptr<GameController> game;

public:
    NextTetroWidget(std::shared_ptr<GameController> game, QWidget *parent = nullptr);
    void update();
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawPiece(QPainter &painter);
    std::vector<std::vector<char>> createAndFillGrid(const Tetromino &tetromino, char tSymbol) const;
};
#endif //NEXTTETROWIDGET_H
