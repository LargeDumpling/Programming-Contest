@echo off
:loop
data.exe %random%
code.exe
again.exe
fc code.out again.out
if errorlevel==1 pause
goto loop