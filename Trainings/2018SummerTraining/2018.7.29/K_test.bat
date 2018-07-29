@echo off
:loop
K_data.exe %random%
K.exe
K_checker.exe
if errorlevel==1 pause
goto loop