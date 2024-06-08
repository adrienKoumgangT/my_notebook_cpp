//
// Created by adrien koumgang tegantchouang on 27/04/24.
//

#ifndef MY_NOTEBOOK_CPP_NODE_COLLECTION_TEST_H
#define MY_NOTEBOOK_CPP_NODE_COLLECTION_TEST_H


#include "../src/NoteCollection.h"
#include "../src/NoteCollectionObserver.h"

int test_collection() {
    // Create a note collection
    NoteCollection myNoteCollection("My Collection");
    myNoteCollection.printCollection();

    // Create an observer for the note collection
    NoteCollectionObserver observer;

    // Attach the observer to the note collection
    myNoteCollection.attach(&observer);

    // Add some notes to the collection
    myNoteCollection.addNote(Note("Note 1", "Content of Note 1"));
    myNoteCollection.addNote(Note("Note 2",  "Content of Note 2"));

    myNoteCollection.printCollection();

    return 0;
}

#endif //MY_NOTEBOOK_CPP_NODE_COLLECTION_TEST_H
