@echo off
if [%LITAC_HOME%] == [] goto error_exit

del ".\bin\litacc.*" /q
del ".\bin\litac.*" /q

echo Running bootstrapped litaC...

bootstrap\litacc.exe build -profile -outputDir "./bin"
if errorlevel 1 (
    goto error_compiling
)

echo Running litaC inception!...
bin\litac build -profile -output "litac_inception"
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
