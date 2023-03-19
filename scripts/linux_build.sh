#!/bin/bash

BUILD_DIRS="build_dirs"
BUILD_LINUX_DEBUG="build_debug_linux"

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIRS" ]; then
    mkdir "$BUILD_DIRS"
fi
cd "$BUILD_DIRS"

if [ ! -d "$BUILD_LINUX_DEBUG" ]; then
    mkdir "$BUILD_LINUX_DEBUG"
fi
cd "$BUILD_LINUX_DEBUG"

cmake -DCMAKE_BUILD_TYPE=Debug ../..

cmake --build .

