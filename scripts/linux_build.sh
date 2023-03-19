#!/bin/bash

BUILD_DIR="build_debug_linux"

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR"

cmake -DCMAKE_BUILD_TYPE=Debug ..

cmake --build .

