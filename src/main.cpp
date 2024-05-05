#include <iostream>

#include "ApplicationTetris.h"
#include "TetrisQtGUI.h"

int main(int argc, char** argv) {
    if (argc > 2) {
        std::cerr << "Too many arguments !" << std::endl;
        return 1;
    }
#ifdef qtAppIsBuilt
    if (argc == 2 && std::string(argv[1]) == "-c") {
        ApplicationTetris app = ApplicationTetris();
        app.run();
    }
    TetrisQtGUI app = TetrisQtGUI();
    app.run(argc, argv);
#else
    ApplicationTetris app = ApplicationTetris();
    app.run();
#endif
    return 0;
}
