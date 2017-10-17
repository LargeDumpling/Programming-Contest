@echo off
:loop
data.exe
code.exe
code_FNT2.exe
fc code.in code_FNT2.out
if errorlevel==1 pause
goto loop