@echo off
:loop
data.exe
code.exe
uva10054.exe
test.exe
fc 0.txt test.out
if errorlevel==1 pause
goto loop