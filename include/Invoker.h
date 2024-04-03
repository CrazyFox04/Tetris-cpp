//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef INVOKER_H
#define INVOKER_H

#include "Command.h"
#include "GameState.h"
#include <map>
#include <vector>
#include <string>
#include <memory>

/**
 * @class Invoker
 * @brief Manages the execution of commands based on the game's state.
 *
 * The Invoker class is responsible for executing commands. It keeps a mapping of command names
 * to their respective command objects and the game states in which they are valid. The Invoker ensures
 * that a command is only executed if the game is in an appropriate state for that command.
 */
class Invoker {
    std::multimap<std::string, std::pair<std::unique_ptr<Command>, std::vector<GameState>>> commandMap; //!< A mapping of command names to their respective command objects and game states.
    GameState currentState; //!< The current state of the game.

public:

    /**
     * Constructor for Invoker.
     * Initializes the invoker with the game starting at the MAIN_MENU state.
     */
    Invoker();

    /**
     * Registers a command with the Invoker.
     * @param commandName The name associated with the command.
     * @param command The unique_ptr to the command object.
     * @param state The game state in which the command is valid.
     */
    void registerCommand(const std::string &input, std::unique_ptr<Command> command, std::vector<GameState> state);

    /**
     * Sets the current state of the game.
     * @param newState The new state of the game.
     */
    void setState(GameState state);

    /**
     * Executes a command based on its name if the command is valid in the current game state.
     * @param commandName The name of the command to execute.
     */
    void execute(const std::string &name);

    /**
     * Get the current state of the game.
     * @return The current state of the game.
     */
    GameState getState() const;
};

#endif //INVOKER_H
