@echo off
if [%LITAC_HOME%] == [] goto error_exit

del ".\bin\litacc.*" /q
del ".\bin\litac.*" /q

REM set BUILD_CMD="clang.exe -std=c99 -g -gcodeview -fsanitize=undefined,address %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS"
set BUILD_CMD="clang.exe -std=c99 %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS"

echo Running bootstrapped litaC...
cp "bootstrap\litacc.exe" "bin\litacc.exe"
cd bin

litacc.exe -version
litacc.exe -disableLine -cFormat -profile -buildCmd %BUILD_CMD% "../src/main.lita" -outputDir "./" -output "litac" -maxMemory 1GiB
if errorlevel 1 (
    goto error_compiling
)


echo Running litaC inception!...
litac.exe -disableLine -verbose -profile -cFormat -debug -buildCmd %BUILD_CMD% "../src/main.lita" -maxMemory 1GiB
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
