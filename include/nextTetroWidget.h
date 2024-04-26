//
// Created by Enzo Renard on 26/04/2024.
//

#ifndef NEXTTETROWIDGET_H
#define NEXTTETROWIDGET_H
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

class NextTetroWidget : public QWidget {

public:
    explicit NextTetroWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawPiece(QPainter &painter, int x, int y);
};
#endif //NEXTTETROWIDGET_H
