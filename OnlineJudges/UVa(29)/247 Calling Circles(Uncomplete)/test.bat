@echo off
:loop
data.exe
code.exe
szzq.exe
fc code.out szzq.out
if errorlevel==1 pause
goto loop