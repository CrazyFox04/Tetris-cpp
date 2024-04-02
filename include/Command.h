#ifndef COMMAND_H
#define COMMAND_H

/**
 * @class Command
 * @brief Abstract class representing a generic command in a command pattern.
 *
 * Command is an interface for all concrete command classes that will inherit from it.
 * It defines a common interface for executing operations.
 */
class Command {
public:
    /**
     * Virtual destructor.
     *
     * Important to have for a class with virtual methods.
     * Ensures that derived class destructors are called correctly,
     * preventing resource leaks and other destruction-related issues.
     */
    virtual ~Command() = default;

    /**
     * Execute the command.
     *
     * This is a pure virtual function that must be overridden in derived classes.
     * It defines the action that the command will perform when executed.
     */
    virtual void execute() = 0;
};
#endif //COMMAND_H
