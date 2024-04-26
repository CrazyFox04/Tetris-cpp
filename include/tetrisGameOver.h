//
// Created by Enzo Renard on 26/04/2024.
//

#ifndef TETRISGAMEOVER_H
#define TETRISGAMEOVER_H
#include <QWidget>
class TetrisGameOver : public QWidget {
    QWidget window;

public:
    TetrisGameOver();
    int start(QApplication *myQtApp);
};
#endif //TETRISGAMEOVER_H
