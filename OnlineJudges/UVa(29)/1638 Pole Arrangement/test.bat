@echo off
:loop
data.py
BL.exe
code.exe
fc BL.out code.out
if errorlevel==1 pause
goto loop