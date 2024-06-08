//
// Created by adrien koumgang tegantchouang on 27/04/24.
//

#ifndef MY_NOTEBOOK_CPP_NOTE_COLLECTION_OBSERVER_H
#define MY_NOTEBOOK_CPP_NOTE_COLLECTION_OBSERVER_H

#include <iostream>

#include "NoteCollection.h"
#include "Observer.h"

class NoteCollectionObserver: public Observer {
public:
    // NoteCollectionObserver(Observer *pObserver) : Observer(pObserver) {}

    void update(NoteCollection& collection) override;
};


#endif //MY_NOTEBOOK_CPP_NOTE_COLLECTION_OBSERVER_H
