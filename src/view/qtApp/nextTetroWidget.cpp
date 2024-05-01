//
// Created by Enzo Renard on 26/04/2024.
//
#include "nextTetroWidget.h"
#include <QLabel>
#include <iostream>
#include <QKeyEvent>
#include <QPainter>
#include <algorithm>
#include "BoardBox.h"

NextTetroWidget::NextTetroWidget(std::shared_ptr<GameController> game, QWidget* parent) : game(), QWidget(parent) {
    this->game = game;
    setFixedSize(80, 50);
    setStyleSheet("background-color: #9bbc0f; border: 2px solid #0f380f; border-radius: 5px; padding: 5px; margin: 0px;");
    setFocusPolicy(Qt::StrongFocus);
}

void NextTetroWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    drawPiece(painter); // Exemple de dessin d'un rectangle
}

void NextTetroWidget::drawPiece(QPainter &painter) {
    const auto &tetromino = game->getBag().peekNext();
    auto grid = createAndFillGrid(tetromino, 'X');
    int gridSize = grid.size();
    int blockSize = std::min(width() / gridSize,
                             height() / gridSize);

    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            if (grid[y][x] != ' ') {
                QRect blockRect(x * blockSize, y * blockSize, blockSize, blockSize);
                QLinearGradient gradient(x, y, x + 30, y + 30);
                gradient.setColorAt(0, QColor("#0f380f"));
                gradient.setColorAt(1, QColor("#306230"));
                painter.fillRect(blockRect, gradient);
                QPen pen(QColor("#9bbc0f"));
                painter.setPen(pen);
                painter.drawRect(blockRect);
            }
        }
    }
}

std::vector<std::vector<char>> NextTetroWidget::createAndFillGrid(const Tetromino &tetromino, char tSymbol) const {
    int gridSize = std::max(tetromino.get_length(), tetromino.get_height());
    if (gridSize % 2 == 0) gridSize++;
    std::vector<std::vector<char>> grid(gridSize, std::vector<char>(gridSize, ' '));
    int centerX = gridSize / 2;
    int centerY = gridSize / 2;

    for (const auto &cell: tetromino.get_relative_cells()) {
        int x = centerX + cell.get_x();
        int y = centerY + cell.get_y();
        if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
            grid[y][x] = tSymbol;
        }
    }
    return grid;
}

void NextTetroWidget::update() {
    repaint();
}