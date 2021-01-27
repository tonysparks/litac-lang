@echo off
if [%LITAC_HOME%] == [] goto error_exit

del ".\bin\litac.*" /q
del ".\bin\litac_tests.*" /q

set BUILD_CMD="clang.exe -std=c99 -g -gcodeview -fsanitize=undefined,address %%input%% -o %%output%%  -D_CRT_SECURE_NO_WARNINGS -I../include -L../lib"
java -jar %LITAC_HOME%/target/litac.jar -buildCmd %BUILD_CMD% -outputDir "./bin" -output "litacc" "./src/main.lita" -types "none" -debug
cd bin
litacc.exe -debug -testFile -run -profile -buildCmd %BUILD_CMD% -output "litac_tests" "%1"
goto end

:error_exit
echo ERROR: It appears you do not have the 'LITAC_HOME' system variable defined.  Please make sure this is set to the home directory of litac

:end

