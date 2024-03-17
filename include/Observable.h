//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Observer.h"
#include <vector>
#include <memory>

class Observable {
    std::vector<std::shared_ptr<Observer>> observers;
public:
    virtual void addObserver(std::shared_ptr<Observer> observer);
    virtual void removeObserver(int pos);
    virtual void notifyObservers();
};
#endif //OBSERVABLE_H
