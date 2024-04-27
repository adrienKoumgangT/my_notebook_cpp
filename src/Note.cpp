//
// Created by adrien koumgang tegantchouang on 18/04/24.
//

#include "Note.h"

#include <utility>
#include <iostream>

Note::Note(std::string  title, std::string  content)
    : title(std::move(title)), content(std::move(content)), createDate(std::time(nullptr)), updateDate(createDate) {}

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

void Note::print() const {
    std::cout << "Note{" << std::endl <<
    "\t" << "title: " << getTitle() << std::endl <<
    "\t" << "content: " << getContent() << std::endl <<
    "\t" << "create date: " << getCreateDate() << std::endl <<
    "\t" << "update date: " << getUpdateDate() << std::endl <<
    "}" << std::endl;
}
