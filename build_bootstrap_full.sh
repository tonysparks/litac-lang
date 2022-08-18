#!/bin/bash
wd=$(pwd)
echo Current working directory '$wd'

sh ./build.sh

cp -f "${wd}/bin/output/a.c" "${wd}/bootstrap/litac_linux.c"

cd ${wd}
sh ${wd}/build_bootstrap.sh

cd ${wd}
echo Completed.