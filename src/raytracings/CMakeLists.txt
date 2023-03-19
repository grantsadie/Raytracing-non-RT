cmake_minimum_required(VERSION 3.10)

project(raytracings)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES ray.cpp)

add_library(raytracings ${SOURCES})

target_include_directories(raytracings PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})