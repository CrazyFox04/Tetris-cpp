#include "Invoker.h"

void Invoker::setCommand(std::string& name, std::unique_ptr<Command> command) {
    commands[name] = std::move(command);
}

void Invoker::executeCommand(const std::string& name) {
    commands[name]->execute();
}
