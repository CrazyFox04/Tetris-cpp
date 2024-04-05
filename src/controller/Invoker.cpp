#include <utility>

#include "Invoker.h"

Invoker::Invoker() : commandMap(), currentState(GameState::MAIN_MENU) {}

void Invoker::registerCommand(const std::string &commandName, std::unique_ptr<Command> command,
                              std::vector<GameState> states) {
    commandMap.emplace(commandName, std::make_pair(std::move(command), states));
}

void Invoker::setState(GameState newState) {
    currentState = newState;
}

void Invoker::execute(const std::string &commandName) const {
    auto it = commandMap.find(commandName);
    if (it != commandMap.end()) {
        for (auto state : it->second.second) {
            if (state == currentState) {
                it->second.first->execute();
                return;
            }
        }
    }
}

GameState Invoker::getState() const {
    return currentState;
}