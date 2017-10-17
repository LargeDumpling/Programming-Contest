@echo off
:loop
T1_data.exe
T1.exe
T1_Std.exe
fc T1.out T1_Std.out
if errorlevel==1 pause
goto loop