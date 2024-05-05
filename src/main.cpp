#include <iostream>

#include "ApplicationTetris.h"
#include "TetrisQtGUI.h"

int main(int argc, char** argv) {
    if (argc > 2) {
        std::cerr << "Too many arguments !" << std::endl;
        return 1;
    }
    if (argc == 2 && std::string(argv[1]) == "-c") {
        ApplicationTetris app = ApplicationTetris();
        app.run();
    }
    TetrisQtGUI app = TetrisQtGUI();
    app.run(argc, argv);
    return 0;
}
