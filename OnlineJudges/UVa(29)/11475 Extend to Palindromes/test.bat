@echo off
:loop
data.exe
SA.exe
other.exe
fcc SA.out other.out
if errorlevel==1 pause
goto loop
