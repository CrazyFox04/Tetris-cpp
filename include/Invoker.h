//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef INVOKER_H
#define INVOKER_H

#include "Command.h"
#include <string>
#include <map>


class Invoker {
    std::map<std::string, Command*> commands;
public:
    Invoker();
    void addNewCommand(std::string input, Command* command);
    void execute(std::string command);
};
#endif //INVOKER_H
