@echo off
set wd=%cd%
echo Current working directory '%wd%'

call build.bat

cp "%wd%\bin\litac.c" "%wd%\bootstrap"
move /y "%wd%\bootstrap\litac.c" "%wd%\bootstrap\litacc.c"

cd %wd%
call %wd%\build_bootstrap.bat

:end
cd %wd%
echo Completed.