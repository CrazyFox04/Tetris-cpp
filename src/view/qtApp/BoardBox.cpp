#include <iostream>
#include "BoardBox.h"
#include <thread>
#include "ColorAnimation.h"

#include "TetrisView.h"
#include <memory>

BoardBox::BoardBox(std::shared_ptr<GameController> game, QWidget *parent)
        : QWidget(parent), game(game), tetroViews(),
          dropVisualizationTetro(new TetroView(game, game->getDroppedTetro(), true, this)) {
    connect(dynamic_cast<const QObject *>(parent), SIGNAL(updateQt()), this, SLOT(updateQt()));
    setFixedSize((game->getBoard().getWidth() + 2) * 30, game->getBoard().getHeight() * 30);
    setStyleSheet("background-color: #52796F;");
    setFocusPolicy(Qt::StrongFocus);
    layout = new QGridLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(dropVisualizationTetro, 0, 0);
    setLayout(layout);
    initPaintOccupied();
    updateTetros();
}

void BoardBox::initPaintOccupied() {
    std::vector<Position> occupied{};
    auto occupiedFromGame = game->getBoard().getOccupied();
    for (int i = 0; i < game->getBoard().getHeight(); ++i) {
        for (int j = 0; j < game->getBoard().getWidth(); ++j) {
            if (occupiedFromGame.at(i).at(j)) {
                occupied.emplace_back(j, i);
            }
        }
    }
    auto bigOccupied = Tetromino(0, {-game->getBoard().getRefPosition().get_x(), 0}, occupied, false);
    blockView = new TetroView(game, bigOccupied, false, this);
    blockView->setColor(QColor("#354F52"));
    layout->addWidget(blockView, 0, 0);
}

void BoardBox::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    drawBorders(painter);
    for (auto&tetro_view: tetroViews) {
        tetro_view->update();
    }
}

void BoardBox::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_Q:
            game->moveActiveTetromino(Direction::LEFT);
            break;
        case Qt::Key_D:
            game->moveActiveTetromino(Direction::RIGHT);
            break;
        case Qt::Key_S:
            game->moveActiveTetromino(Direction::DOWN);
            break;
        case Qt::Key_Space:
            game->dropActiveTetromino();
            break;
        case Qt::Key_A:
            game->rotateActiveTetromino(Rotation::COUNTERCLOCKWISE);
            break;
        case Qt::Key_E:
            game->rotateActiveTetromino(Rotation::CLOCKWISE);
            break;
        default:
            QWidget::keyPressEvent(event);
    }
}

void BoardBox::drawBorders(QPainter&painter) {
    int brickWidth = 30;
    int brickHeight = 15;
    QColor darkColor("#2F3E46");
    QColor lightColor("#354F52");

    for (int y = 0; y < height(); y += brickHeight * 2) {
        painter.fillRect(0, y, brickWidth, brickHeight, darkColor);
        painter.fillRect(0, y + brickHeight, brickWidth, brickHeight, lightColor);
    }

    for (int y = 0; y < height(); y += brickHeight * 2) {
        painter.fillRect(width() - brickWidth, y, brickWidth, brickHeight, darkColor);
        painter.fillRect(width() - brickWidth, y + brickHeight, brickWidth, brickHeight, lightColor);
    }
}

void BoardBox::updateQt() {
    if (tetroViews.size() > game->getBoard().getTetrominos().size()) {
        restart();
    }
    updateBlocks();
    updateTetros();
    animatePreviousTetro();
    updateTetroVisualization();
}

void BoardBox::updateBlocks() {
    std::vector<Position> occupied{};
    auto occupiedFromGame = game->getBoard().getOccupied();
    for (int i = 0; i < game->getBoard().getHeight(); ++i) {
        for (int j = 0; j < game->getBoard().getWidth(); ++j) {
            if (occupiedFromGame.at(i).at(j)) {
                occupied.emplace_back(j, i);
            }
        }
    }
    auto bigOccupied = Tetromino(0, {-game->getBoard().getRefPosition().get_x(), 0}, occupied, false);
    blockView->updateQt(bigOccupied);
}

void BoardBox::updateTetros() {
    for (int i = 0; i < tetroViews.size(); ++i) {
        tetroViews.at(i)->updateQt(game->getBoard().getTetrominos().at(i));
    }
    for (int i = tetroViews.size(); i < game->getBoard().getTetrominos().size(); ++i) {
        auto tetroView = new TetroView(game, game->getBoard().getTetrominos().at(i), false, this);
        tetroViews.append(tetroView);
        layout->addWidget(tetroView, 0, 0);
        tetroView->show();
    }
}

void BoardBox::animatePreviousTetro() {
    if (tetroViews.size() > 1) {
        tetroViews.at(tetroViews.size() - 2)->makeItBlink(1000);
    }
}

void BoardBox::updateTetroVisualization() {
    dropVisualizationTetro->updateQt(game->getDroppedTetro());
    dropVisualizationTetro->getColorFromTetro();
}

void BoardBox::restart() {
    for (const auto&tetro_view: tetroViews) {
        layout->removeWidget(tetro_view);
        tetro_view->hide();
        delete tetro_view;
    }
    tetroViews.clear();
}

#include "moc_BoardBox.cpp"
