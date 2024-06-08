//
// Created by adrien koumgang tegantchouang on 27/05/24.
//

#include <iostream>

#if __cplusplus < 201402L
#include "utils.h"
#endif

#include "App.h"

App::App(const std::string& defaultCollectionName)
    : defaultCollection(defaultCollectionName) {
    defaultCollection.attach(&observer);
    collections[defaultCollectionName] = std::make_unique<NoteCollection>(defaultCollectionName);
}

void App::addNote(const std::string& title, const std::string& content) {
    defaultCollection.addNote(Note(title, content));
}

void App::addNoteToCollection(const std::string& collectionName, const std::string& title, const std::string& content) {
    if (collections.find(collectionName) != collections.end()) {
        collections[collectionName]->addNote(Note(title, content));
    } else {
        std::cerr << "Collection " << collectionName << " does not exist." << std::endl;
    }
}

void App::removeNoteFromCollection(const std::string& collectionName, size_t index) {
    if (collections.find(collectionName) != collections.end()) {
        collections[collectionName]->removeNote(index);
    } else {
        std::cerr << "Collection " << collectionName << " does not exist." << std::endl;
    }
}

void App::printNotesFromCollection(const std::string& collectionName) const {
    if (collections.find(collectionName) != collections.end()) {
        for (const auto& note : collections.at(collectionName)->getNotes()) {
            note.printNote();
        }
    } else {
        std::cerr << "Collection " << collectionName << " does not exist." << std::endl;
    }
}

void App::printAllNotes() const {
    for (const auto& pair : collections) {
        std::cout << "Collection: " << pair.first << std::endl;
        for (const auto& note : pair.second->getNotes()) {
            note.printNote();
        }
    }
}

void App::createCollection(const std::string& collectionName) {
    if (collections.find(collectionName) == collections.end()) {
        collections[collectionName] = std::make_unique<NoteCollection>(collectionName);
        collections[collectionName]->attach(&observer);
    } else {
        std::cerr << "Collection " << collectionName << " already exists." << std::endl;
    }
}

void App::listCollections() const {
    for (const auto& pair : collections) {
        std::cout << "Collection: " << pair.first << std::endl;
    }
}

