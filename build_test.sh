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
    exit 1
}

error_tests() {
    echo ""
    echo "=========================================="
    echo "Test failures!"
    echo "=========================================="
    echo ""
    exit 4
}

run_tests() {
    echo "Compiling litaC tests..."

    cd ./bin
    ./litac -verbose -buildCmd "${BUILD_CMD}" -cFormat -profile -srcDir "../src" -outputDir "./" -output "litac_tests" "../test/test_suite.lita" -types "none" -debug -maxMemory 1GiB
    result=$?
    if [ $result -gt 0 ]; then
        error_compiling
    fi

    echo "Running litaC tests..."
    ./litac_tests
    result=$?

    echo "Result: " $result
    if [ $result -gt 0 ]; then
        error_tests
    fi

    echo Completed.
}


export LITAC_HOME=${LITAC_HOME:-${PWD}}
echo "Environment variable: ${LITAC_HOME}"
run_tests
