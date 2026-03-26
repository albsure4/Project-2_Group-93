cmake_minimum_required(VERSION 3.20)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyProject main.cpp
        dataEntries.h
        dataEntries.cpp)

file(COPY Data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})