#include "GameBoardWidget.h"
#include "Board.h"
#include "Game.h"
#include <memory>

GameBoardWidget::GameBoardWidget(QWidget *parent)
        : QWidget(parent) {
    controller = std::make_shared<Game>();
}

void GameBoardWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const Board &board = controller->getBoard();
    const int blockSize = 30;
    const int boardWidth = board.getWidth();
    const int boardHeight = board.getHeight();

    painter.fillRect(rect(), Qt::black);

    for (int row = 0; row < boardHeight; ++row) {
        for (int col = 0; col < boardWidth; ++col) {
            if (board.isOccupied(row, col)) {
                painter.fillRect(col * blockSize, row * blockSize, blockSize, blockSize, Qt::red);
            }
        }
    }

    painter.setPen(Qt::white);
    for (int i = 0; i <= boardHeight; i++) {
        painter.drawLine(0, i * blockSize, boardWidth * blockSize, i * blockSize);
    }
    for (int j = 0; j <= boardWidth; j++) {
        painter.drawLine(j * blockSize, 0, j * blockSize, boardHeight * blockSize);
    }

}