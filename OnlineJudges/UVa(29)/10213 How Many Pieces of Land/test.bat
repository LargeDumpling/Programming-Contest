@echo off
:loop
data.py
other.exe
code.exe
fc other.out code.out
if errorlevel==1 pause
goto loop