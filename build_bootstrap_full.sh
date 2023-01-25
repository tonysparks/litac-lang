#!/bin/bash

wd=$(pwd)
echo Current working directory ${wd}

sh ${wd}/build_bootstrap.sh
if [ $? -gt 0 ]; then
    return 1
fi

cd ${wd}
sh ${wd}/build.sh
if [ $? -gt 0 ]; then
    return 1
fi

cp -f "${wd}/bin/output/a.c" "${wd}/bootstrap/litac_linux.c"
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