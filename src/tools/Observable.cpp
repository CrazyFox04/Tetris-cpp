//
// Created by Enzo Renard on 19/03/2024.
//

#include "Observable.h"
#include <vector>
Observable::Observable() {
    observers = std::vector<Observer>();
}
Observable::~Observable() {

}


void Observable::addObserver(Observer& observer) {
    observers.push_back(observer);
}

void Observable::removeObserver(int pos) {
    observers.erase(observers.begin() + pos);
}

void Observable::notifyObservers() {
    for (auto &observer : observers) {
        observer.update();
    }
}
