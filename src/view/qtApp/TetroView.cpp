#include "TetroView.h"

#include "ColorAnimation.h"

TetroView::TetroView(std::shared_ptr<GameController> game, Tetromino tetromino, bool isGhost,
                     QWidget* parent) : QWidget(parent), tetromino(tetromino), game(), isGhost(isGhost),
                                        hasBlinked(false) {
    this->game = game;
    color = getColor(tetromino);
}

void TetroView::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QRect blockRect;
    QPen pen;
    pen.setColor("#84A98C");
    painter.setPen(pen);
    for (const auto&cell: tetromino.get_relative_cells()) {
        int x = 30 + (game->getBoard().getRefPosition().get_x() + cell.get_x()) * 30;
        int y = (game->getBoard().getRefPosition().get_y() + cell.get_y()) * 30;
        blockRect.setRect(x, y, 30, 30);
        painter.fillRect(blockRect, getGradient(x, y));
        painter.drawRect(blockRect);
    }
}

QLinearGradient TetroView::getGradient(int x, int y) const {
    QLinearGradient gradient = QLinearGradient(x, y, x + 30, y + 30);
    gradient.setColorAt(0, color); // plus clair en haut à gauche
    gradient.setColorAt(1, color.darker(250));
    return gradient;
}

void TetroView::updateQt(Tetromino tetromino) {
    this->tetromino = tetromino;
}

void TetroView::setColor(QColor color) {
    this->color = color;
}

void TetroView::getColorFromTetro() {
    if (isGhost) {
        color = getColor(tetromino);
        color.setAlpha(80);
    }
    else {
        color = getColor(tetromino);
    }
}

QColor getColor(Tetromino&tetromino) {
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

void TetroView::makeItBlink(int blinkTime) {
    if (!hasBlinked) {
        hasBlinked = true;
        auto* animation = new ColorAnimation(this, "color");
        animation->setDuration(500);
        animation->setLoopCount(blinkTime / 500);
        animation->setStartValue("#354F52");
        animation->setEndValue(getColor(tetromino));
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

QColor TetroView::getCurrentColor() const {
    return color;
}

#include "moc_TetroView.cpp"
