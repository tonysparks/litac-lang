# litac README

VSCode extension for the [LitaC](https://github.com/tonysparks/litac) Programming Language.

Extreme Work In Progress!

## Features

* Syntax highlighting
* Type look up (global and file scope)
* Syntax error highlighting
* Run file tests command

## Requirements

You need [LitaC](https://github.com/tonysparks/litac) installed

## Extension Settings


* `litac.languageServerPath`: Path of the LitaC language server binary (e.g. `"C:/litac-lsp.exe"`)
* `litac.languageServerArguments`: Command line arguments for the LitaC language server
* `litac.failFast`: Prevents the server from being restarted after it has crashed (defaults to `false`)
* `litac.languageServerLog`: Outputs a log file for debuging the LitaC Language Server (defaults to `false`)
* `litac.libraryPath`: The path to the LitaC library, this should be your litac/lib directory
* `litac.testOutpuPath`: The path to write out test output files
* `litac.clearTestOutput` : Clears the output before each test run (defaults to `true`)

## Known Issues

* Code completion not implemented
* Error squigglies highlight the full line

## Release Notes

Initial Release -- Enjoy :D

### 0.0.1

Initial release