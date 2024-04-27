//
// Created by adrien koumgang tegantchouang on 18/04/24.
//

#ifndef MY_NOTEBOOK_CPP_NODE_TEST_H
#define MY_NOTEBOOK_CPP_NODE_TEST_H

#include <iostream>
#include <cassert>
#include "../src/Note.h"

class NodeTest {

};

int test_note() {
    // Test Note creation and getters
    Note note("Test Title", "Test Content");
    assert(note.getTitle() == "Test Title");
    assert(note.getContent() == "Test Content");

    // Test Note update
    note.setTitle("Updated Title");
    note.setContent("Updated Content");
    assert(note.getTitle() == "Updated Title");
    assert(note.getContent() == "Updated Content");

    std::cout << "All tests passed!" << std::endl;

    note.print();
    
    return 0;
}

#endif //MY_NOTEBOOK_CPP_NODE_TEST_H
