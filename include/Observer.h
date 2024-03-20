//
// Created by Enzo Renard on 05/03/2024.
//

#ifndef OBSERVER_H
#define OBSERVER_H
class Observer {
public:
    Observer();
    virtual ~Observer() = 0;
    virtual void update() = 0;
};
#endif //OBSERVER_H
