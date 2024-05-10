#include "nextTetroWidget.h"
#include <QLabel>
#include <QKeyEvent>
#include <QPainter>
#include <algorithm>

NextTetroWidget::NextTetroWidget(std::shared_ptr<GameController> game, QWidget *parent) : game(), QWidget(parent) {
    this->game = game;
    setFixedSize(100, 70);
    setStyleSheet(
            "background-color: #9bbc0f; border: 2px solid #0f380f; border-radius: 5px; padding: 5px; margin: 0px;");
    setFocusPolicy(Qt::StrongFocus);
}

void NextTetroWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect blockRect;
    int tetroWidth = game->getBag().peekNext().get_length();
    int tetroHeight = game->getBag().peekNext().get_height();
    int centerX = width() / 2 - tetroWidth / 2 - 5;
    int centerY = height() / 2 - tetroHeight / 2 - 5;
    for (const auto &cell: game->getBag().peekNext().get_relative_cells()) {
        int x = centerX + cell.get_x() * 10;
        int y = centerY + cell.get_y() * 10;
        blockRect.setRect(x, y, 10, 10);
        painter.fillRect(blockRect, getColor(game->getBag().peekNext()));
        painter.drawRect(blockRect);
    }
}

QColor NextTetroWidget::getColor(const Tetromino &tetromino) {
    switch (tetromino.get_id()) {
        case 1:
            return QColor("#FF0D72"); // Rouge
        case 2:
            return QColor("#0DC2FF"); // Bleu
        case 3:
            return QColor("#0DFF72"); // Vert
        case 4:
            return QColor("#F538FF"); // Violet
        case 5:
            return QColor("#FF8E0D"); // Orange
        case 6:
            return QColor("#FFE138"); // Jaune
        case 7:
            return QColor("#3877FF"); // Bleu clair
        default:
            return QColor("#000000"); // Noir
    }
}

void NextTetroWidget::update() {
    repaint();
}