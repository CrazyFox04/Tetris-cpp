#include "nextTetroWidget.h"
#include <QLabel>
#include <QKeyEvent>
#include <QPainter>
#include <algorithm>


NextTetroWidget::NextTetroWidget(std::shared_ptr<GameController> game, QWidget* parent) : game(), QWidget(parent) {
    this->game = game;
    setFixedSize(80, 50);
    setStyleSheet("background-color: #9bbc0f; border: 2px solid #0f380f; border-radius: 5px; padding: 5px; margin: 0px;");
    setFocusPolicy(Qt::StrongFocus);
}

void NextTetroWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    drawPiece(painter);
}

void NextTetroWidget::drawPiece(QPainter &painter) {
    const auto tetromino = game->getBag().peekNext();

    auto grid = createAndFillGrid(tetromino, 'X');
    int gridSize = grid.size();
    int blockSize = 10;

    int xOffset = (width() - (blockSize * gridSize)) / 2;
    int yOffset = (height() - (blockSize * gridSize)) / 2;

    QColor baseColor = getColor(tetromino.get_id());
    QColor darkerColor = baseColor.darker(150);

    QPen pen(baseColor);
    painter.setPen(pen);

    QRect blockRect;
    QLinearGradient gradient;

    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            if (grid[y][x] != ' ') {
                blockRect.setRect(xOffset + x * blockSize, yOffset + y * blockSize, blockSize, blockSize);
                gradient.setStart(blockRect.topLeft());
                gradient.setFinalStop(blockRect.bottomRight());
                gradient.setColorAt(0, baseColor);
                gradient.setColorAt(1, darkerColor);
                painter.fillRect(blockRect, gradient);
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

QColor NextTetroWidget::getColor(int id) {
    static const std::vector<QColor> colors = {
            QColor("#FF0D72"), // Rouge
            QColor("#0DC2FF"), // Bleu
            QColor("#0DFF72"), // Vert
            QColor("#F538FF"), // Violet
            QColor("#FF8E0D"), // Orange
            QColor("#FFE138"), // Jaune
            QColor("#3877FF"), // Bleu clair
    };
    return colors[id % colors.size()];
}

void NextTetroWidget::update() {
    repaint();
}