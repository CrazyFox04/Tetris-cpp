//
// Created by Enzo Renard on 26/04/2024.
//
#include "TetrisQtGUI.h"
#include "myQtApp.h"

int TetrisQtGUI::launch(int argc, char** argv) {
    myQtApp app = myQtApp(argc, argv);
    return app.start();
}