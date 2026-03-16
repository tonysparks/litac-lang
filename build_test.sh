#!/bin/bash

set -e

error_tests() {
    echo ""
    echo "=========================================="
    echo "Test failures!"
    echo "=========================================="
    echo ""
    exit 4
}

run_tests() {
    echo "Running litaC tests..."
    litac build

    # valgrind --leak-check=full --show-leak-kinds=all ./litac_tests $1
    if [ -n "$1" ]; then
        ./bin/litac test -regex "singleOnly" -file "./test/compiler_test.lita" -output "litac_tests"
    else
        ./bin/litac test -output "litac_tests"
    fi

    result=$?

    if [ $result -gt 0 ]; then
        error_tests
    fi

    echo Completed.
}


export LITAC_HOME=${LITAC_HOME:-${PWD}}
echo "Environment variable: ${LITAC_HOME}"
run_tests $1
