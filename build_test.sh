#!/bin/bash

BUILD_CMD="gcc %input% -o %output% -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -ltcc -lm -lrt -lpthread -ldl"
#set BUILD_CMD="tcc.exe %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -llibtcc"


error_compiling() {
    echo ""
    echo "=========================================="
    echo "ERROR: Compiling litac compiler           "
    echo "=========================================="
    echo ""
    exit 1
}

run_tests() {
    echo "Running litaC tests..."
    
    cd ./bin
    ./litac_linux -buildCmd "${BUILD_CMD}" -cFormat -profile -srcDir "../src" -outputDir "./" -output "litac_tests" "../test/test_suite.lita" -types "none" -debug
    ./litac_tests
    if [ $? -gt 0 ]; then
        error_compiling()
        return 1
    fi

    echo Completed.
}
echo "Environment variable: ${LITAC_HOME}"
if [ -z "${LITAC_HOME}" ]; then
    echo ""
    echo "=========================================="
    echo "ERROR: It appears you do not have the 'LITAC_HOME' system variable defined.  Please make sure this is set to the home directory of litac"
    echo "=========================================="
    echo ""
    exit 2
else 
    run_tests
fi
