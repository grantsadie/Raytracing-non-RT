cmake_minimum_required(VERSION 3.10)

project(math)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES vec3.cpp)

add_library(math ${SOURCES})

target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})