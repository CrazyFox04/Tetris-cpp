//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef INVOKER_H
#define INVOKER_H

#include "Command.h"
#include <map>
#include <string>
#include <memory>

class Invoker {
    std::map<std::string, std::unique_ptr<Command>> commands;
public:
    void setCommand(std::string& name, std::unique_ptr<Command> command);
    void executeCommand(const std::string& name);
};

#endif //INVOKER_H
