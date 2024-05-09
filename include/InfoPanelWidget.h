#ifndef TETRIS_INFOPANELWIDGET_H
#define TETRIS_INFOPANELWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class InfoPanelWidget : public QWidget {
Q_OBJECT

public:
    ~InfoPanelWidget() = default;
    InfoPanelWidget(QWidget *parent = nullptr);

private:
    QLabel *scoreLabel;
    QLabel *levelLabel;
    QLabel *linesLabel;

    void setupUI();
};

// A SUPPRIMER ?

#endif //TETRIS_INFOPANELWIDGET_H
