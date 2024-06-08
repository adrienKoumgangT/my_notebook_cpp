//
// Created by adrien koumgang tegantchouang on 27/05/24.
//

#ifndef MY_NOTEBOOK_CPP_APP_H
#define MY_NOTEBOOK_CPP_APP_H

#include <unordered_map>
#include <memory>

#include "NoteCollection.h"
#include "NoteCollectionObserver.h"


class App {
private:
    std::unordered_map<std::string, std::unique_ptr<NoteCollection>> collections;
    NoteCollection defaultCollection;
    NoteCollectionObserver observer;

public:
    App(const std::string& defaultCollectionName);

    void addNote(const std::string& title, const std::string& content);
    void addNoteToCollection(const std::string& collectionName, const std::string& title, const std::string& content);
    void removeNoteFromCollection(const std::string& collectionName, size_t index);
    void printNotesFromCollection(const std::string& collectionName) const;
    void printAllNotes() const;
    void createCollection(const std::string& collectionName);
    void listCollections() const;
};



#endif //MY_NOTEBOOK_CPP_APP_H
