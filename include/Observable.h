//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Observer.h"

class Observable {
    std::vector<Observer> observers;
public:
    virtual void addObserver(Observer observer);
    virtual void removeObserver(int pos);
    virtual void notifyObservers();
};
#endif //OBSERVABLE_H
