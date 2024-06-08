//
// Created by adrien koumgang tegantchouang on 27/04/24.
//

#ifndef MY_NOTEBOOK_CPP_OBSERVER_H
#define MY_NOTEBOOK_CPP_OBSERVER_H

// #include "NoteCollection.h"

class NoteCollection;

class Observer {
public:
    // Observer(Observer *pObserver);

    virtual void update(NoteCollection& collection) = 0;
};


#endif //MY_NOTEBOOK_CPP_OBSERVER_H
