//
// Created by adrien koumgang tegantchouang on 27/05/24.
//

#ifndef MY_NOTEBOOK_CPP_UTILS_H
#define MY_NOTEBOOK_CPP_UTILS_H

#ifndef MAKE_UNIQUE_H
#define MAKE_UNIQUE_H

#include <memory>

namespace std {
    template<typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

#endif // MAKE_UNIQUE_H


#endif //MY_NOTEBOOK_CPP_UTILS_H
