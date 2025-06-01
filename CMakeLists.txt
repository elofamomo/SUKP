cmake_minimum_required(VERSION 3.27)
project(SUKP)

set(CMAKE_CXX_STANDARD 17)

add_executable(SUKP main.cpp
        load.cpp
        load.h
        solver.cpp
        solver.h
        solution.cpp
        solution.h
)
