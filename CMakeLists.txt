cmake_minimum_required(VERSION 3.28)
project(my_notebook_cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_notebook_cpp main.cpp
        src/Note.cpp
        src/Note.h
        test/NodeTest.cpp
        test/NodeTest.h
)
