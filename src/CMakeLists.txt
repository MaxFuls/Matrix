cmake_minimum_required(VERSION 3.27)

project(MatrixProg)

set(CMAKE_CXX_STANDART 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_library(MatrixLib MatrixProg.cpp MatrixHeader.h)

link_libraries(MatrixLib)

add_executable(Matrix MatrixMain.cpp)