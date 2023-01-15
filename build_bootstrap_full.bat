@echo off
set wd=%cd%
echo Current working directory '%wd%'

call %wd%\build_bootstrap.bat

cd %wd%
call build.bat

cp "%wd%\bin\litac.c" "%wd%\bootstrap"
move /y "%wd%\bootstrap\litac.c" "%wd%\bootstrap\litac_windows.c"

cd %wd%
call %wd%\build_bootstrap.bat

:end
cd %wd%
echo Completed.