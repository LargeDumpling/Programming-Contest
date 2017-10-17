@echo off
:loop
data.exe %random%
code.exe
zls.exe
fc code.out zls.out
if errorlevel==1 pause
goto loop