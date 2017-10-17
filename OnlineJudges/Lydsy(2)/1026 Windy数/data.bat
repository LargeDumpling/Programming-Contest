@echo off
:loop
data.pyw
code.exe
showson.exe
fc code.out showson.out
if errorlevel==1 pause
goto loop