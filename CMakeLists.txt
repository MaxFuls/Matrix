cmake_minimum_required(VERSION 3.16)

project(Matrix)

set(CMAKE_CXX_STANDART 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_library(matrix MatrixProg.cpp)

link_libraries(matrix)

add_executable(Matrix MatrixProg.cpp)
