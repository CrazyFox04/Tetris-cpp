//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef INVOKER_H
#define INVOKER_H

#include "Command.h"
#include "GameState.h"
#include <map>
#include <string>
#include <memory>

class Invoker {
    std::map<std::string, std::pair<std::unique_ptr<Command>, GameState>> commandMap;
    GameState currentState;
public:
    Invoker();
    void registerCommand(const std::string& input, std::unique_ptr<Command> command, GameState state);
    void setState(GameState state);
    void execute(const std::string& name);
};

#endif //INVOKER_H
