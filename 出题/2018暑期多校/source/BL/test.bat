@echo off
:loop
data.exe %random%
Problem.exe
BL.exe
fc Problem.out BL.out
if errorlevel==1 pause
goto loop