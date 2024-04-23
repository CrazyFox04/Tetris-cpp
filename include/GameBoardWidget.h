#ifndef TETRIS_GAMEBOARDWIDGET_H
#define TETRIS_GAMEBOARDWIDGET_H

#include <QWidget>
#include <memory>
#include "GameController.h"
#include <QPainter>

class GameBoardWidget : public QWidget {
    Q_OBJECT
    std::shared_ptr<GameController> controller;

public:
    ~GameBoardWidget() = default;
    GameBoardWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif //TETRIS_GAMEBOARDWIDGET_H
