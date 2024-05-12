#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "Observer.h"

class Observable {
public:
    virtual ~Observable() = default;

    virtual void addObserver(Observer* observer) = 0;

    virtual void removeObserver(Observer* observer) = 0;

    virtual void notifyObservers() = 0;
};
#endif //OBSERVABLE_H
