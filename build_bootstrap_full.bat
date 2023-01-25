@echo off
set wd=%cd%
echo Current working directory '%wd%'

call %wd%\build_bootstrap.bat
if errorlevel 1 (
    goto end
)

cd %wd%
call build.bat
if errorlevel 1 (
    goto end
)

cp "%wd%\bin\litac.c" "%wd%\bootstrap"
move /y "%wd%\bootstrap\litac.c" "%wd%\bootstrap\litac_windows.c"
if errorlevel 1 (
    goto end
)

cd %wd%
call %wd%\build_bootstrap.bat
if errorlevel 1 (
    goto end
)

:end
cd %wd%
echo Completed.
