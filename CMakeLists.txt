cmake_minimum_required(VERSION 4.0)
project(oop)

set(CMAKE_CXX_STANDARD 20)


find_program(CLANG_TIDY clang-tidy)

if (CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY})
endif ()


add_executable(oop main.cpp)
