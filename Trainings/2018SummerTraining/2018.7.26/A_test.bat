@echo off
:loop
A_data.exe %random%
A.exe
A_BL.exe
fc A.out A_BL.out
if errorlevel==1 pause
goto loop