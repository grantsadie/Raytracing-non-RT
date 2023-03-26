#!/bin/bash

BUILD_DIRS="build_dirs"

print_help() {
    echo "Usage: $0 --debug | --release"
    echo ""
    echo "Options:"
    echo "  --debug   Build in Debug mode."
    echo "  --release Build in Release mode."
}

if [ $# -eq 0 ]; then
    print_help
    exit 1
fi

BUILD_MODE=""
if [ "$1" = "--debug" ]; then
    BUILD_MODE="Debug"
elif [ "$1" = "--release" ]; then
    BUILD_MODE="Release"
else
    echo "Invalid argument: $1"
    print_help
    exit 1
fi

BUILD_TARGET="build_${BUILD_MODE,,}_linux"

if [ ! -d "$BUILD_DIRS" ]; then
    mkdir "$BUILD_DIRS"
fi
cd "$BUILD_DIRS"

if [ ! -d "$BUILD_TARGET" ]; then
    mkdir "$BUILD_TARGET"
fi
cd "$BUILD_TARGET"

cmake -DCMAKE_BUILD_TYPE=$BUILD_MODE ../..

cmake --build .