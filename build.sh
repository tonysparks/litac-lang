#!/bin/bash

LFLAGS=""
OUT_FILE="litac_"
if [[ "$OSTYPE" == "darwin"* ]]; then
  LFLAGS="-L../lib/mac -ltcc -L../lib -lm -lpthread -ldl -lcurl"
  OUT_FILE="${OUT_FILE}mac"
else
  LFLAGS="-L../lib -ltcc -lm -lrt -lpthread -ldl"
  OUT_FILE="${OUT_FILE}linux"
fi

BUILD_CMD="gcc %input% -o %output% -D_CRT_SECURE_NO_WARNINGS -I../include $LFLAGS"
#set BUILD_CMD="tcc.exe %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -llibtcc"


error_compiling() {
    echo ""
    echo "=========================================="
    echo "ERROR: Compiling litac compiler           "
    echo "=========================================="
    echo ""
    exit 2
}

build_litac() {
    echo "Running bootstrapped litaC..."

    cd bootstrap

    ./litacc -cFormat -profile -buildCmd "${BUILD_CMD}" "../src/main.lita" -outputDir "../bin/" -output "$OUT_FILE" -maxMemory 1GiB
    if [ $? -gt 0 ]; then
        error_compiling()
        return 1
    fi

    echo "Running litaC inception!..."
    cd ../bin
    ./${OUT_FILE} -profile -cFormat -buildCmd "${BUILD_CMD}" "../src/main.lita" -maxMemory 1GiB
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
    build_litac
fi

#del ".\bin\litacc.*" /q
#del ".\bin\litac.*" /q
