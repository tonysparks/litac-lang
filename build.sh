#!/bin/bash

unameOut="$(uname -s)"
case "${unameOut}" in
    Darwin*)
        LIBS="-lm -lpthread -lcurl -ldl";
        EXE_NAME="litac_mac";
    ;;
    *)
        LIBS="-lm -lrt -lpthread -lcurl -ltcc -ldl";
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

    ./litacc -cFormat -profile -buildCmd "${BUILD_CMD}" "../src/main.lita" -outputDir "../bin/" -output "${EXE_NAME}" -maxMemory 1GiB
    if [ $? -gt 0 ]; then
        error_compiling
        return 1;
    fi

    echo "Running litaC inception!..."
    cd ../bin
    ./$EXE_NAME -profile -cFormat -buildCmd "${BUILD_CMD}" "../src/main.lita" -maxMemory 1GiB
    if [ $? -gt 0 ]; then
        error_compiling
        return 1;
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

