#!/bin/bash

set -e

# BUILD_CMD="clang -std=gnu11 -g -gcodeview %input% -o %output%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib ${LIBS}"
BUILD_CMD="gcc -std=gnu11 -g %input% -o %output%  -D_CRT_SECURE_NO_WARNINGS"

error_compiling() {
    echo ""
    echo "=========================================="
    echo "ERROR: Compiling litac compiler           "
    echo "=========================================="
    echo ""
    exit 2;
}

build_litac() {
    echo "Running bootstrapped litaC..."

    cd bootstrap

    ./litacc -disableLine -verbose -cFormat -profile -buildCmd "${BUILD_CMD}" "../src/main.lita" -outputDir "../bin/" -output "litac" -maxMemory 1GiB
    if [ $? -gt 0 ]; then
        error_compiling
        return 1;
    fi

    echo "Running litaC inception!..."
    cd ../bin
    #valgrind --leak-check=full --show-leak-kinds=all ./litac -disableLine -verbose -profile -cFormat -buildCmd "${BUILD_CMD}" "../src/main.lita" -maxMemory 1GiB -outputDir "./output/"
    ./litac -disableLine -verbose -profile -cFormat -buildCmd "${BUILD_CMD}" "../src/main.lita" -maxMemory 1GiB -outputDir "./output/"
    if [ $? -gt 0 ]; then
        error_compiling
        return 1;
    fi

    echo Completed.
}

export LITAC_HOME=${LITAC_HOME:-${PWD}}
echo "Environment variable: ${LITAC_HOME}"
build_litac

