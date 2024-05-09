#include <iostream>
#include "BoardBox.h"
#include "TetrisView.h"

BoardBox::BoardBox(std::shared_ptr<GameController> game, QWidget* parent) : game(), QWidget(parent) {
    this->game = game;
    connect(dynamic_cast<const QtPrivate::FunctionPointer<void(TetrisView::*)()>::Object*>(parent), SIGNAL(updateQt()), this, SLOT(update()));
    setFixedSize((game->getBoard().getWidth() + 2) * 30, game->getBoard().getHeight() * 30);
    setStyleSheet("background-color: #9bbc0f;");
    setFocusPolicy(Qt::StrongFocus);
}

void BoardBox::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    drawBorders(painter);
    drawPiece(painter);
}

void BoardBox::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_Q:
            game->moveActiveTetromino(Direction::LEFT);
            std::cout << "Left" << std::endl;
            break;
        case Qt::Key_D:
            game->moveActiveTetromino(Direction::RIGHT);
            std::cout << "Right" << std::endl;
            break;
        case Qt::Key_S:
            game->moveActiveTetromino(Direction::DOWN);
            std::cout << "Down" << std::endl;
            break;
        case Qt::Key_Z:
            game->dropActiveTetromino();
            std::cout << "Drop" << std::endl;
            break;
        case Qt::Key_A:
            game->rotateActiveTetromino(Rotation::COUNTERCLOCKWISE);
            std::cout << "Rotate ccw" << std::endl;
            break;
        case Qt::Key_E:
            game->rotateActiveTetromino(Rotation::CLOCKWISE);
            std::cout << "Rotate cw" << std::endl;
            break;
        default:
            QWidget::keyPressEvent(event);
    }
}

void BoardBox::drawPiece(QPainter&painter) {
    QRect blockRect;
    QLinearGradient gradient;
    QPen pen(QColor("#9bbc0f"));
    painter.setPen(pen);

    for (const auto tetromino: game->getBoard().getTetrominos()) {
        QColor baseColor = getColor(tetromino.get_id());
        QColor darkerColor = baseColor.darker(150);

        for (const auto&block: tetromino.get_relative_cells()) {
            int x = 30 + (game->getBoard().getRefPosition().get_x() + block.get_x()) * 30;
            int y = (game->getBoard().getRefPosition().get_y() + block.get_y()) * 30;
            blockRect.setRect(x, y, 30, 30);

            gradient.setStart(x, y);
            gradient.setFinalStop(x + 30, y + 30);
            gradient.setColorAt(0, baseColor); // plus clair en haut à gauche
            gradient.setColorAt(1, darkerColor); // plus foncé en bas à droite
            painter.fillRect(blockRect, gradient);
            painter.drawRect(blockRect);
        }
    }

    auto droppedTetro = game->getDroppedTetro();
    if (droppedTetro != game->getBoard().getTetrominos().back()) {
        QColor semiTransparent = getColor(droppedTetro.get_id());
        semiTransparent.setAlpha(80);

        for (const auto&cell: droppedTetro.get_relative_cells()) {
            int x = 30 + (game->getBoard().getRefPosition().get_x() + cell.get_x()) * 30;
            int y = (game->getBoard().getRefPosition().get_y() + cell.get_y()) * 30;
            blockRect.setRect(x, y, 30, 30);
            painter.fillRect(blockRect, semiTransparent);
        }
    }
}

QColor BoardBox::getColor(int id) {
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

void BoardBox::drawBorders(QPainter&painter) {
    int brickWidth = 30;
    int brickHeight = 15;
    QColor darkColor("#0f380f");
    QColor lightColor("#306230");

    for (int y = 0; y < height(); y += brickHeight * 2) {
        painter.fillRect(0, y, brickWidth, brickHeight, darkColor);
        painter.fillRect(0, y + brickHeight, brickWidth, brickHeight, lightColor);
    }

    for (int y = 0; y < height(); y += brickHeight * 2) {
        painter.fillRect(width() - brickWidth, y, brickWidth, brickHeight, darkColor);
        painter.fillRect(width() - brickWidth, y + brickHeight, brickWidth, brickHeight, lightColor);
    }
}

// Faire clignoter le tetromino actif quand il se pose. La difficulté c'est que la méthode
// setOccupiedForActiveTetromino est dans Board
/**
void BoardBox::blinkActiveTetromino(QPainter &painter) {
    Tetromino activeTetromino = game->getBoard().getActiveTetromino();
    for (int i = 0; i < 5; i++) {
        QColor color = (i % 2 == 0) ? QColor(Qt::transparent) : getColor(
                activeTetromino.get_id());
        drawTetrominoWithColor(painter, activeTetromino, color);
        updateQt();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
*/

// Pour faire clignoter clignoter un seul tetro, je penses qu'on a besoin d'une nouvelle methode sinon
// DrawPiece va faire clignoter tout les tetro
/**
void BoardBox::drawTetrominoWithColor(QPainter &painter, const Tetromino &tetromino, const QColor &color) {
    QRect blockRect;
    for (const auto &block: tetromino.get_relative_cells()) {
        int x = 30 + (game->getBoard().getRefPosition().get_x() + block.get_x()) * 30;
        int y = (game->getBoard().getRefPosition().get_y() + block.get_y()) * 30;
        blockRect.setRect(x, y, 30, 30);

        QLinearGradient gradient(x, y, x + 30, y + 30);
        gradient.setColorAt(0, color.lighter()); // plus clair en haut à gauche
        gradient.setColorAt(1, color.darker(150)); // plus foncé en bas à droite
        painter.fillRect(blockRect, gradient);
        painter.drawRect(blockRect);
    }
}
*/

// Faire clignoter une ligne avant de la faire disparaitre
/**
void BoardBox::blinkCompletedLine(QPainter &painter, int lineIndex) {
    for (int i = 0; i < 5; i++) {
        QColor color = (i % 2 == 0) ? QColor(Qt::transparent) : QColor("#9bbc0f");
        for (int x = 0; x < game->getBoard().getWidth(); x++) {
            QRect blockRect(x * 30, lineIndex * 30, 30, 30);
            painter.fillRect(blockRect, color);
            painter.drawRect(blockRect);
        }
        updateQt();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
*/
void BoardBox::updateQt() {
    repaint();
}

#include "moc_BoardBox.cpp"