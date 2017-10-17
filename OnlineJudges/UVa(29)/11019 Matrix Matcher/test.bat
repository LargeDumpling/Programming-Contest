@echo off
:loop
data.exe
code.exe
other.exe
fc other.txt code.out
if errorlevel==1 pause
goto loop