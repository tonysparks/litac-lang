#!/bin/bash

set -e

unameOut="$(uname -s)"
case "${unameOut}" in
    Darwin*)
        LIBS="-lm -lpthread";
        EXE_NAME="litac_mac";
    ;;
    *)
        LIBS="-lm -lrt -lpthread";
        EXE_NAME="litac_linux";
    ;;
esac

BUILD_CMD="gcc %input% -o %output% -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib ${LIBS}"

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

    ./litacc -verbose -cFormat -profile -buildCmd "${BUILD_CMD}" "../src/main.lita" -outputDir "../bin/" -output "${EXE_NAME}" -maxMemory 1GiB
    if [ $? -gt 0 ]; then
        error_compiling
        return 1;
    fi

    echo "Running litaC inception!..."
    cd ../bin
    ./$EXE_NAME -profile -cFormat -buildCmd "${BUILD_CMD}" "../src/main.lita" -maxMemory 1GiB -outputDir "./output/"
    if [ $? -gt 0 ]; then
        error_compiling
        return 1;
    fi

    echo Completed.
}
LITAC_HOME=${LITAC_HOME:-${PWD}}
echo "Environment variable: ${LITAC_HOME}"
build_litac

