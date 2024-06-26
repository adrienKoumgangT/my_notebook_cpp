//
// Created by adrien koumgang tegantchouang on 27/04/24.
//

#include "NoteCollection.h"

#include <utility>

NoteCollection::NoteCollection(std::string name)
    : name(std::move(name)),
    createDate(std::time(nullptr)),
    updateDate(createDate) {}

std::string NoteCollection::getName() const {
    return name;
}

std::time_t NoteCollection::getCreateDate() const {
    return createDate;
}

std::time_t NoteCollection::getUpdateDate() const {
    return updateDate;
}

std::vector<Note> NoteCollection::getNotes() const {
    return notes;
}

void NoteCollection::attach(Observer *observer) {
    observers.push_back(observer);
}

void NoteCollection::detach(Observer *observer) {
    observers.erase(
            std::remove(
                    observers.begin(),
                    observers.end(),
                    observer
                    ),
                    observers.end()
            );
    updateDate = std::time(nullptr);
}

void NoteCollection::notify() {
    for (auto observer : observers) {
            observer->update(*this);
        }
}

void NoteCollection::setName(const std::string &newName) {
    name = newName;
    updateDate = std::time(nullptr);
}

void NoteCollection::addNote(const Note& note) {
    NoteCollection::notes.push_back(note);
    updateDate = std::time(nullptr);
    notify();
}

void NoteCollection::removeNote(size_t index) {
    if(index < notes.size()) {
        notes.erase(notes.begin() + index);
        updateDate = std::time(nullptr);
        notify();
    } else {
        std::cerr << "Invalid index. Note not found." << std::endl;
    }
}

std::string NoteCollection::timeToString(std::time_t time) {
    char buffer[80];
    struct tm* timeinfo = std::localtime(&time);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return {buffer};
}

void NoteCollection::printCollection() const {
    std::cout << "NoteCollection{" << std::endl;
    std::cout << "Collection name: " << name << std::endl;
    std::cout << "Collection created: " << timeToString(createDate) << std::endl;
    std::cout << "Collection updated: " << timeToString(updateDate) << std::endl;
    std::cout << "Collection notes: [" << std::endl;
    for (const auto& note : notes) {
        note.printNote();
    }
    std::cout << "]" << std::endl;
    std::cout << "}" << std::endl;
}
