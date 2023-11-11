#!/bin/bash

set -e

wd=$(pwd)
echo Current working directory ${wd}

unameOut="$(uname -s)"
case "${unameOut}" in
    Darwin*)
        SOURCE_FILE="litac_mac.c";
    ;;
    *)
        SOURCE_FILE="litac_linux.c"
    ;;
esac

if [ -z "${LITAC_HOME}" ]; then
    export LITAC_HOME=$(pwd)
fi

sh ${wd}/build_bootstrap.sh
if [ $? -gt 0 ]; then
    return 1
fi

cd ${wd}
sh ${wd}/build.sh
if [ $? -gt 0 ]; then
    return 1
fi

cp -f "${wd}/bin/output/a.c" "${wd}/bootstrap/${SOURCE_FILE}"
if [ $? -gt 0 ]; then
    return 1
fi

cd ${wd}
sh ${wd}/build_bootstrap.sh
if [ $? -gt 0 ]; then
    return 1
fi

cd ${wd}
echo Completed.