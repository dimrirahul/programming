cmake_minimum_required(VERSION 2.8.4)
project(drazilFact)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    date.cc)

add_executable(drazilFact ${SOURCE_FILES})