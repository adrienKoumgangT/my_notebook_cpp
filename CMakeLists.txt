cmake_minimum_required(VERSION 3.28)
project(my_notebook_cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_notebook_cpp main.cpp
        src/Note.cpp
        src/Note.h
        test/NodeTest.h
        src/NoteCollection.cpp
        src/NoteCollection.h
        src/Observer.h
        src/Subject.h
        src/NoteCollectionObserver.h
        test/NodeCollectionTest.h
        src/NoteCollectionObserver.cpp
        src/NoteCollectionObserver.cpp
        src/App.cpp
        src/App.h
        src/utils.h
        test/AppTest.h
)
