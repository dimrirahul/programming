cmake_minimum_required(VERSION 3.1)
project(D)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    D.cc
    makefile)

add_executable(D ${SOURCE_FILES})