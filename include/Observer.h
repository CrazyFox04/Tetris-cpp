#ifndef OBSERVER_H
#define OBSERVER_H
class Observer {
public:
    /**
     * Virtual destructor for safe polymorphic usage.
     */
    virtual ~Observer() = default;

    /**
     * Updates the observer.
     * Pure virtual function overridden in TetrisView class.
     */
    virtual void update() = 0;
};
#endif //OBSERVER_H
