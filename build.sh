#!/bin/bash

BUILD_CMD="gcc %input% -o %output% -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -ltcc -lm -lrt -lpthread -ldl"
#set BUILD_CMD="tcc.exe %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -llibtcc"


error_compiling() {
    echo ""
    echo "=========================================="
    echo "ERROR: Compiling litac compiler           "
    echo "=========================================="
    echo ""
}

build_litac() {
    echo "Running bootstrapped litaC..."
    
    cd bootstrap
    
    ./litacc -cFormat -profile -buildCmd "${BUILD_CMD}" "../src/main.lita" -outputDir "../bin/" -output "litac_linux"
    if [ $? -gt 0 ]; then
        error_compiling()
        return 1
    fi

    echo "Running litaC inception!..."
    cd ../bin
    ./litac_linux -profile -cFormat -buildCmd "${BUILD_CMD}" "../src/main.lita"
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
else 
    build_litac
fi

#del ".\bin\litacc.*" /q
#del ".\bin\litac.*" /q



