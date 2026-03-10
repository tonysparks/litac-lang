@echo off
if [%LITAC_HOME%] == [] goto error_exit

del ".\bin\litac_tests.*" /q


echo "Running litaC tests..."
litac test -output "litac_tests"

if errorlevel 1 (
    goto error_tests
)

goto end

:error_exit
echo ERROR: It appears you do not have the 'LITAC_HOME' system variable defined.  Please make sure this is set to the home directory of litac
exit 31

:error_tests
echo ERROR: One or more tests have failed
exit 31


:end
echo All tests have passed!
