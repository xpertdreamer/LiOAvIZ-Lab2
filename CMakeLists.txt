cmake_minimum_required(VERSION 3.31)
project(LiOAvIZ-Lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(matrix_mult
        src/main.cpp
        src/matrix.cpp
        src/matrix.h
        src/sorts.h
        src/sorts.cpp
)

include_directories(src)