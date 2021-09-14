@echo off
if [%LITAC_HOME%] == [] goto error_exit

del ".\bin\litacc.*" /q
del ".\bin\litac.*" /q

set BUILD_CMD="clang.exe -std=c99 -g -gcodeview -fsanitize=undefined,address %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -llibtcc"
REM set BUILD_CMD="tcc.exe %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -llibtcc"


echo Running bootstrapped litaC...
cd bootstrap
litacc.exe -cFormat -profile -buildCmd %BUILD_CMD% "../src/main.lita" -outputDir "../bin/" -output "litac" -maxMemory 1GiB
REM litacc.exe -cFormat -types all -debug -run -profile "../test/test_single.lita"
REM litaC.exe -run -profile -buildCmd %BUILD_CMD% "../src/lsp.lita"
if errorlevel 1 (
    goto error_compiling
)


REM echo Running litaC inception!...
REM cd ../bin
REM a.exe -debug -profile -instrument -cFormat -buildCmd %BUILD_CMD% "../../src/main.lita"
REM inception.exe -run -debug -profile -cFormat -buildCmd %BUILD_CMD% "../test/test_single.lita"
REM litacc.exe -run -debug -profile -cFormat -buildCmd %BUILD_CMD% "../test/test_interfaces.lita"
REM litacc.exe -run -debug -profile -cFormat -buildCmd %BUILD_CMD% "../src/main.lita"
REM echo Inception complete

echo Running litaC inception!...
cd ../bin
litac.exe -profile -cFormat -buildCmd %BUILD_CMD% "../src/main.lita" -maxMemory 1GiB
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
