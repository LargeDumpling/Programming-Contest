@echo off
:loop
data.exe %random%
code.exe
other.exe
fc code.out other.out
if errorlevel==1 pause
goto loop