@echo off
:loop
T1_data.exe
T1.exe
T1_BL.exe
fc T1.out T1_BL.out
if errorlevel==1 pause
goto loop