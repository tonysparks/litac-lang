@echo off
if [%LITAC_HOME%] == [] goto error_exit

del ".\bin\litac.*" /q

REM set BUILD_CMD="clang.exe -std=c99 -g -gcodeview -fsanitize=undefined,address %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib"
set BUILD_CMD="tcc.exe %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib"
java -jar %LITAC_HOME%/target/litac.jar -profile -buildCmd %BUILD_CMD% -outputDir "./bin" -output "litacc" "./src/main.lita" -types "none" -debug
if errorlevel 1 (
    goto error_compiling
)
cd bin
echo Running litaC...
litacc.exe -debug -cFormat -profile -buildCmd %BUILD_CMD% "../src/main.lita" -outputDir "./" -output "inception"
REM litacc.exe -cFormat -types all -debug -run -profile "../test/test_single.lita"
REM litaC.exe -run -profile -buildCmd %BUILD_CMD% "../src/lsp.lita"

echo Running litaC inception!...
REM a.exe -debug -profile -instrument -cFormat -buildCmd %BUILD_CMD% "../../src/main.lita"
REM inception.exe -run -debug -profile -cFormat -buildCmd %BUILD_CMD% "../test/test_single.lita"
inception.exe -run -debug -profile -cFormat -buildCmd %BUILD_CMD% "../test/test_interfaces.lita"
REM echo Inception complete
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
