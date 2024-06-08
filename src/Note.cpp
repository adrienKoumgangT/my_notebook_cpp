//
// Created by adrien koumgang tegantchouang on 18/04/24.
//

#include "Note.h"

#include <utility>
#include <iostream>

Note::Note(std::string   title, std::string   content)
    : title(std::move(title)),
    content(std::move(content)),
    createDate(std::time(nullptr)),
    updateDate(createDate),
    locked(false) {}

    // Copy constructor
Note::Note(const Note& other)
    : title(other.title),
    content(other.content),
    createDate(std::time(nullptr)),
    updateDate(createDate),
    locked(other.locked) {}

// Copy assignment operator
Note& Note::operator=(const Note& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }
    title = other.title;
    content = other.content;
    // createDate = other.createDate;
    // updateDate = other.updateDate;
    // locked = other.locked;
    return *this;
}



std::string Note::getTitle() const {
    return title;
}

std::string Note::getContent() const {
    return content;
}

std::time_t Note::getCreateDate() const {
    return createDate;
}

std::time_t Note::getUpdateDate() const {
    return updateDate;
}

bool Note::isLocked() const {
    return locked;
}




void Note::setTitle(const std::string& newTitle) {
    std::lock_guard<std::mutex> lock(lockMutex); // Lock the mutex
    if (!locked) {
        title = newTitle;
        updateDate = std::time(nullptr);
    }
}

void Note::setContent(const std::string& newContent) {
    std::lock_guard<std::mutex> lock(lockMutex); // Lock the mutex
    if (!locked) {
        content = newContent;
        updateDate = std::time(nullptr);
    }
}


void Note::lock() {
    std::lock_guard<std::mutex> lock(lockMutex); // Lock the mutex
    locked = true;
}

void Note::unlock() {
    std::lock_guard<std::mutex> lock(lockMutex); // Lock the mutex
    locked = false;
}

Note Note::duplicate() {
    std::lock_guard<std::mutex> lock(lockMutex);
    return Note(*this);
}

void Note::printNote() const {
    std::cout << "Note{" << std::endl <<
              "\t" << "title: " << getTitle() << std::endl <<
              "\t" << "content: " << getContent() << std::endl <<
              "\t" << "create date: " << timeToString(getCreateDate()) << std::endl <<
              "\t" << "update date: " << timeToString(getUpdateDate()) << std::endl <<
              "\t" << "locked: " << (isLocked() ? "true" : "false") << std::endl <<
            "}" << std::endl;
}

std::string Note::timeToString(std::time_t time) {
    char buffer[80];
    struct tm* time_info = std::localtime(&time);
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
    return {buffer};
}

