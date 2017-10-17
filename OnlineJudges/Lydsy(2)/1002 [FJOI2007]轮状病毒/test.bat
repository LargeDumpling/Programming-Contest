@echo off
:loop
data.py
code.exe
HZWER.exe
fc code.out HZWER.out
if errorlevel==1 pause
goto loop