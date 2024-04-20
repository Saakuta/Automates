cmake_minimum_required(VERSION 3.28)
project(Automates)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Automates
        main.c
        main.h
        README.md
        lecture.h
        lecture.c
        verification.h
        verification.c)
