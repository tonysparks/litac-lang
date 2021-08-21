#!/bin/bash

cd bootstrap
gcc -o "litacc" "litac_linux.c" -D_CRT_SECURE_NO_WARNINGS -D_DEFAULT_SOURCE -I../include -L../lib -ltcc -lm -lrt -lpthread -ldl
echo "Successfully built bootstrap"