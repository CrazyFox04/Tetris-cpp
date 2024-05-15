#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "Observer.h"

class Observable {
public:
    /**
     * Virtual destructor for safe polymorphic usage.
     */
    virtual ~Observable() = default;

    /**
     * Adds an observer to the list of observers.
     * Pure virtual function overridden in Game class.
     * @param observer the observer to add.
     */
    virtual void addObserver(Observer* observer) = 0;

    /**
     * Removes an observer from the list of observers.
     * Pure virtual function overridden in Game class.
     * @param observer the observer to remove.
     */
    virtual void removeObserver(Observer* observer) = 0;

    /**
     * Notifies all observers of a change.
     * Pure virtual function overridden in Game class.
     */
    virtual void notifyObservers() = 0;
};
#endif //OBSERVABLE_H
