cmake_minimum_required(VERSION 3.16)
project(oop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_program(CLANG_TIDY clang-tidy)

if (CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY})
endif ()

add_subdirectory(task0b)
