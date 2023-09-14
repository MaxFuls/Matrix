cmake_minimum_required(VERSION 3.16)

project(MatrixProg)

set(CMAKE_CXX_STANDART 20)

add_library(MatrixProg MatrixProg.cpp MatrixHeader.h)

link_libraries(MatrixProg)

add_executable(main MatrixMain.cpp)