//
// Created by Julien Delcombel on 14/03/2024.
//

#include "Invoker.h"

Invoker::Invoker() {}

void Invoker::addNewCommand(std::string input, Command *command) {
    commands[input] = command;
}

void Invoker::execute(std::string command) {
    if (commands.find(command) != commands.end()) {
        commands[command]->execute();
    }
}