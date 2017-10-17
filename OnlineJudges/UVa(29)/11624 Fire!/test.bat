@echo off
:loop
data.exe
code.exe
LRJ.exe
fc code.out LRJ.out
if errorlevel==1 pause
goto loop