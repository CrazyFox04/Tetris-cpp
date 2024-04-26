//
// Created by Enzo Renard on 26/04/2024.
//

#ifndef TETRISCONFIGURATION_H
#define TETRISCONFIGURATION_H
#include <QWidget>
class TetrisConfiguration : public QWidget {
    QWidget window;

public:
    TetrisConfiguration(int argc, char *argv[]);
    int start(QApplication *myQtApp);
};
#endif //TETRISCONFIGURATION_H
