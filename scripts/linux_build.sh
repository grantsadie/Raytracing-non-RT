#!/bin/bash

# Name of the build directory
BUILD_DIR="build"

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# Change to the build directory
cd "$BUILD_DIR"

# Run CMake to generate the build system files
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Build the project using the generated build system files
cmake --build .

# Optionally, run any tests or execute the built binary here
