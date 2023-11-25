#!/bin/bash

set -e

unameOut="$(uname -s)"
case "${unameOut}" in
    Darwin*)
        LIBS="-lm -lpthread";
    ;;
    *)
        LIBS="-lm -lrt -lpthread";
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

profile_litac() {
    echo "Profiling build"
    cd bin
    valgrind --tool=callgrind --callgrind-out-file=profile.data.txt ./litac -disableLine -buildCmd "${BUILD_CMD}" "../src/main.lita" -maxMemory 1GiB -outputDir "./output/"
    if [ $? -gt 0 ]; then
        error_compiling
        return 1;
    fi

    echo Completed.
    kcachegrind profile.data.txt
}

export LITAC_HOME=${LITAC_HOME:-${PWD}}
echo "Environment variable: ${LITAC_HOME}"
profile_litac

