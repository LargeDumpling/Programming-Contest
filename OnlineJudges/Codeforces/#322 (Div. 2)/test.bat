@echo off
:loop
C_data.exe
C.exe
HG.exe
fc HG.out code.out
if errorlevel==1 pause
goto loop