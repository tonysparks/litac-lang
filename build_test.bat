@echo off
if [%LITAC_HOME%] == [] goto error_exit

del ".\bin\litac_tests.*" /q

cd bin

set BUILD_CMD="clang.exe -std=c99 -g -fsanitize=undefined,address %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib"
litac -buildCmd %BUILD_CMD% -cFormat -profile -run -srcDir "../src" -outputDir "./" -output "litac_tests" "../test/test_suite.lita" -types "none" -debug
goto end

:error_exit
echo ERROR: It appears you do not have the 'LITAC_HOME' system variable defined.  Please make sure this is set to the home directory of litac

:end

