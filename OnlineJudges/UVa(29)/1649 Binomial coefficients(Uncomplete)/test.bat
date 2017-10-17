@echo off
:loop
data.py
code.exe
BL.exe
fc code.out other.out
if errorlevel==1 pause
goto loop