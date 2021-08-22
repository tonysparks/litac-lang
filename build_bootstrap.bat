@echo off
if [%LITAC_HOME%] == [] goto error_exit

cd bootstrap
clang -std=c99 -g -gcodeview -fsanitize=undefined,address -o litacc.exe litacc.c -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -llibtcc
REM clang -std=c99 -O3 -o litacc.exe litacc.c -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -llibtcc

if errorlevel 1 (
    goto error_compiling
)

goto end


:error_compiling
echo.
echo ==========================================
echo ERROR: Compiling litac compiler
echo ==========================================
echo.
goto end

:error_exit
echo.
echo ==========================================
echo ERROR: It appears you do not have the 'LITAC_HOME' system variable defined.  Please make sure this is set to the home directory of litac
echo ==========================================
echo.

:end
echo Completed.
