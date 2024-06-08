//
// Created by adrien koumgang tegantchouang on 27/04/24.
//

#ifndef MY_NOTEBOOK_CPP_SUBJECT_H
#define MY_NOTEBOOK_CPP_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};


#endif //MY_NOTEBOOK_CPP_SUBJECT_H
