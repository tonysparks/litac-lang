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

    DOCKER_DEFINE=""
    if docker info > /dev/null 2>&1; then
        DOCKER_DEFINE="-DDOCKER_AVAILABLE"
    fi

    # valgrind --leak-check=full --show-leak-kinds=all ./litac_tests $1
    if [ -n "$1" ]; then
        ./bin/output/litac test $DOCKER_DEFINE -regex "singleOnly" -file "./test/compiler_test.lita" -output "litac_tests"
        result=$?
    else
        ./bin/output/litac test -output "litac_tests"
        result=$?

        # Run Docker-dependent tests separately when Docker is available, because the
        # full-suite runner compiles each file independently and doesn't propagate
        # top-level -D defines to individual file compilations.
        if [ -n "$DOCKER_DEFINE" ] && [ $result -eq 0 ]; then
            ./bin/output/litac test $DOCKER_DEFINE -file "./test/std/testcontainers/testcontainers_test.lita" -output "litac_tests"
            result=$?
        fi
        if [ -n "$DOCKER_DEFINE" ] && [ $result -eq 0 ]; then
            ./bin/output/litac test $DOCKER_DEFINE -file "./test/std/db/db_api_test.lita" -output "litac_tests"
            result=$?
        fi
        if [ -n "$DOCKER_DEFINE" ] && [ $result -eq 0 ]; then
            ./bin/output/litac test $DOCKER_DEFINE -file "./test/std/db/postgres/postgres_test.lita" -output "litac_tests"
            result=$?
        fi
    fi

    if [ $result -gt 0 ]; then
        error_tests
    fi

    echo Completed.
}


export LITAC_HOME=${LITAC_HOME:-${PWD}}
echo "Environment variable: ${LITAC_HOME}"
run_tests $1
