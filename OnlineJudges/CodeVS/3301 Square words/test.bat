@echo off
:loop
data.exe
BL.exe
code.exe
fc BL.out code.out
if errorlevel==1 pause
goto loop