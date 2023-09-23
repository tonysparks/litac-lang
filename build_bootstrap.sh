#!/bin/bash

unameOut="$(uname -s)"
case "${unameOut}" in
    Darwin*)
        LIBS="-lm -lpthread -lcurl -ldl";
        SOURCE_FILE="litac_mac.c";
    ;;
    # CYGWIN*)    ;;
    # MINGW*)     ;;
    # MSYS_NT*)   ;;
    # Linux*)     ;;
    *)
        LIBS="-lm -lrt -lpthread -lcurl -ltcc -ldl"
        SOURCE_FILE="litac_linux.c"
    ;;
esac

cd bootstrap
gcc -o "litacc" "${SOURCE_FILE}" -D_CRT_SECURE_NO_WARNINGS -D_DEFAULT_SOURCE -I../include -L../lib -I../stdlib/std/http/libcurl/include ${LIBS}
echo "Successfully built bootstrap"