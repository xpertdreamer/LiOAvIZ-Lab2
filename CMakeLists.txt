cmake_minimum_required(VERSION 3.31)
project(MatrixMultiplication)

set(CMAKE_CXX_STANDARD 20)

add_executable(matrix_mult
        src/main.cpp
        src/matrix.cpp
        src/matrix.h
)

include_directories(src)