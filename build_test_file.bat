@echo off
if [%LITAC_HOME%] == [] goto error_exit

del ".\bin\litacc.*" /q
del ".\bin\litac_tests.*" /q

set BUILD_CMD="clang.exe -march=native -msse2 -mavx2 -mbmi2 -mpopcnt -mfma -mcx16 -mtune=znver1 -std=c99 -g -gcodeview -fsanitize=undefined,address %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -llibtcc"
REM set BUILD_CMD="tcc.exe %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib -llibtcc"


echo Running %1 tests...
cd bin
REM litac.exe  -debug -testFile -run -profile -buildCmd %BUILD_CMD% -output "litac_tests" "%1"
REM cd bootstrap
litac.exe -debug -testFile -run -profile -buildCmd %BUILD_CMD% -output "litac_tests" "%1"
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


