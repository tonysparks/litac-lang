#!/bin/zsh

set -e

if [ ! -d libtcc-cmake ]; then
  git clone https://github.com/Alex2804/libtcc-cmake
fi
cd libtcc-cmake
if [ ! -d build ]; then
  mkdir build
fi
cd build
cmake ..
make
cd ../..

if [ ! -d lib/mac ]; then
  mkdir lib/mac
fi
cp libtcc-cmake/build/libtcc.a lib/mac/libtcc.a
rm -rf libtcc-cmake

cd bootstrap
gcc -o "litacc" "litac_linux.c" -D_CRT_SECURE_NO_WARNINGS -D_DEFAULT_SOURCE -I../include -L../lib/mac -ltcc -L../lib -I../stdlib/std/http/libcurl/include -lm -lpthread -lcurl -ldl
echo "Successfully built bootstrap"
