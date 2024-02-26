cmake_minimum_required(VERSION 3.26)
project(Notes)

set(CMAKE_CXX_STANDARD 17)

add_executable(functions ./Functions/src/main.cpp
        ./Functions/src/print.cpp
        ./Functions/src/print.h)

add_executable(file ./Handling_Files/src/main.cpp)