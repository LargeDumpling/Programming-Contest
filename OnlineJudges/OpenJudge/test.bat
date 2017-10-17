@echo off
:loop
data.exe
2704.exe
2704_.exe
fc code.out BL.out
if errorlevel==1 pause
goto loop