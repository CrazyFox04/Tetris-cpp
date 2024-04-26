//
// Created by Enzo Renard on 26/04/2024.
//
#include "nextTetroWidget.h"
#include <QLabel>
#include <iostream>
#include <QKeyEvent>
#include <QPainter>
#include "BoardBox.h"

NextTetroWidget::NextTetroWidget(QWidget *parent) : QWidget(parent) {
    setFixedSize(80, 50);
    setStyleSheet("background-color: white;");
}

void NextTetroWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    painter.drawRect(5, 5, 10, 10); // Exemple de dessin d'un rectangle
}

void NextTetroWidget::drawPiece(QPainter &painter, int x, int y) {
    // Dessiner une pièce de Tetris ou autre
    painter.fillRect(x, y, 10, 10, Qt::red);
}