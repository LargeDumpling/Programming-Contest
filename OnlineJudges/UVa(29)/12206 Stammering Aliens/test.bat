@echo off
:loop
data.exe
hash.exe
code.exe
fc hash.out code.out
if errorlevel==1 pause
goto loop
