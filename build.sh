#!/bin/bash

set -e

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

    ./bootstrap/litacc build -profile -outputDir "./bin"
    if [ $? -gt 0 ]; then
        error_compiling
        return 1;
    fi

    echo "Running litaC inception!..."

    #valgrind --leak-check=full --show-leak-kinds=all ./litac -disableLine -verbose -profile -cFormat -buildCmd "${BUILD_CMD}" "../src/main.lita" -maxMemory 1GiB -outputDir "./output/"
    ./bin/litac build -profile -output "litac_inception"
    if [ $? -gt 0 ]; then
        error_compiling
        return 1;
    fi

    echo Completed.
}

export LITAC_HOME=${LITAC_HOME:-${PWD}}
echo "Environment variable: ${LITAC_HOME}"
build_litac

