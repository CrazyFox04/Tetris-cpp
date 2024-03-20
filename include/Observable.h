//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <vector>
#include "Observer.h"

class Observable {
    std::vector<Observer> observers;
public:
    Observable();
    virtual ~Observable() = 0;
    virtual void addObserver(Observer& observer) = 0;
    virtual void removeObserver(int pos) = 0;
    virtual void notifyObservers() = 0;
};
#endif //OBSERVABLE_H
