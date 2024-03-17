//
// Created by Julien Delcombel on 17/03/2024.
//

#include "observable.h"

void Observable::addObserver(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Observable::removeObserver(int pos) {
    if (pos >= 0 && pos < observers.size()) {
        observers.erase(observers.begin() + pos);
    }
}

void Observable::notifyObservers() {
    for (auto & observer : observers) {
        observer->update();
    }
}