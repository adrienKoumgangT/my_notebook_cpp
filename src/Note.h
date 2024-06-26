//
// Created by adrien koumgang tegantchouang on 18/04/24.
//

#ifndef MY_NOTEBOOK_CPP_NOTE_H
#define MY_NOTEBOOK_CPP_NOTE_H

#include <string>
#include <ctime>
#include <mutex>
/**
 * Class Note
 * */
class Note {
private:
    std::string title;
    std::string content;
    std::time_t createDate{};
    std::time_t updateDate{};
    bool locked{};
    std::mutex lockMutex; // Mutex for thread safety

public:
    Note(std::string   title, std::string   content);
    Note(const Note& note);

    Note& operator=(const Note& other);

    std::string getTitle() const;
    std::string getContent() const;
    std::time_t getCreateDate() const;
    std::time_t getUpdateDate() const;
    bool isLocked() const;

    void setTitle(const std::string& newTitle);
    void setContent(const std::string& newContent);
    void lock();
    void unlock();

    Note duplicate();

    void printNote() const;

private:
    static std::string timeToString(std::time_t time) ;
};


#endif //MY_NOTEBOOK_CPP_NOTE_H
