@echo off
goto skip
REM https://stackoverflow.com/questions/8526946/commenting-multiple-lines-in-dos-batch-file
REM Answer by mythofechelon
REM Thank you, random internet person!

:skip
net session >nul 2>&1
if %errorLevel% == 0 (
  exit 0
) else (
  exit 1
)
