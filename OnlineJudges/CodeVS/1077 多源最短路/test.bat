@echo off
:loop
data.py
code.exe
Floyd.exe
fc code.out Floyd.out
if errorlevel==1 pause
goto loop