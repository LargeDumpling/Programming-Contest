@echo off
:loop
data.exe "python data.py
Faster.exe
other.exe
fc code.out other.out
if errorlevel==1 pause
goto loop
