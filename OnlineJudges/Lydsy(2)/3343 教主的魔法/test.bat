@echo off
:loop
data.exe
code.exe
BL.exe
fc code.out BL.out
if errorlevel==1 pause
goto loop