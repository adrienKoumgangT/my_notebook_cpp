//
// Created by adrien koumgang tegantchouang on 27/05/24.
//

#ifndef MY_NOTEBOOK_CPP_APP_TEST_H
#define MY_NOTEBOOK_CPP_APP_TEST_H

#include <iostream>

#include "../src/App.h"


int test_app() {
    // Create the application with a default collection
    App app("Default");

    // Add notes to the default collection
    app.addNote("Default Note 1", "Content of Default Note 1");
    app.addNote("Default Note 2", "Content of Default Note 2");

    // Create a new collection and add notes to it
    app.createCollection("Work");
    app.addNoteToCollection("Work", "Work Note 1", "Content of Work Note 1");
    app.addNoteToCollection("Work", "Work Note 2", "Content of Work Note 2");

    // Create another collection and add notes to it
    app.createCollection("Personal");
    app.addNoteToCollection("Personal", "Personal Note 1", "Content of Personal Note 1");
    app.addNoteToCollection("Personal", "Personal Note 2", "Content of Personal Note 2");

    // Print all notes in the default collection
    std::cout << "\nNotes in the Default collection:" << std::endl;
    app.printNotesFromCollection("Default");

    // Print all notes in the Work collection
    std::cout << "\nNotes in the Work collection:" << std::endl;
    app.printNotesFromCollection("Work");

    // Print all notes in the Personal collection
    std::cout << "\nNotes in the Personal collection:" << std::endl;
    app.printNotesFromCollection("Personal");

    // Print all notes in all collections
    std::cout << "\nAll notes in all collections:" << std::endl;
    app.printAllNotes();

    // Remove a note from the Work collection and print again
    app.removeNoteFromCollection("Work", 1);
    std::cout << "\nNotes in the Work collection after removal:" << std::endl;
    app.printNotesFromCollection("Work");

    // List all collections
    std::cout << "\nList of all collections:" << std::endl;
    app.listCollections();

    return 0;
}

#endif //MY_NOTEBOOK_CPP_APP_TEST_H
