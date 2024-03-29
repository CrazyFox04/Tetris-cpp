#include "Invoker.h"

Invoker::Invoker() : currentState(GameState::MAIN_MENU) {}

void Invoker::registerCommand(const std::string &commandName, std::unique_ptr<Command> command, GameState state) {
    commandMap[commandName] = std::make_pair(std::move(command), state);
}

void Invoker::setState(GameState newState) {
    currentState = newState;
}

void Invoker::execute(const std::string &commandName) {
    auto it = commandMap.find(commandName);
    if (it != commandMap.end()) {
        if (it->second.second == currentState) {
            it->second.first->execute();
        } else {
            throw std::runtime_error("Command not available in current state");
        }
    }
}