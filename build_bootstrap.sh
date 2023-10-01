#!/bin/bash

osType="$(uname -s)"
case "${osType}" in
    Darwin*)
        LIBS="-lm -lpthread -lcurl";
        SOURCE_FILE="litac_mac.c";
    ;;
    # CYGWIN*)    ;;
    # MINGW*)     ;;
    # MSYS_NT*)   ;;
    # Linux*)     ;;
    *)
        LIBS="-lm -lrt -lpthread -lcurl"
        SOURCE_FILE="litac_linux.c"
    ;;
esac

archType="$(uname -m)"
case "${archType}" in
    x86_64|i386|i686)
        LIBS="${LIBS} -ltcc -ldl";
    ;;
esac

error_compiling() {
    echo ""
    echo "=========================================="
    echo "ERROR: Compiling litac compiler           "
    echo "=========================================="
    echo ""
    exit 2;
}

cd bootstrap
gcc -o "litacc" "${SOURCE_FILE}" -D_CRT_SECURE_NO_WARNINGS -D_DEFAULT_SOURCE -I../include -L../lib -I../stdlib/std/http/libcurl/include ${LIBS}
if [ $? -gt 0 ]; then
    error_compiling
    return 1;
fi

echo "Successfully built bootstrap"