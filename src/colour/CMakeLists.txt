cmake_minimum_required(VERSION 3.10)

project(colour)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES colour.cpp)

add_library(colour ${SOURCES})

target_include_directories(colour PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})