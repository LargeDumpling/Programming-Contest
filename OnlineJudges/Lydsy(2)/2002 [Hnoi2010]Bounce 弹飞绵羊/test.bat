@echo off
:loop
code_data.exe %random%
code.exe
code_BL.exe
fc code.out code_BL.out
if errorlevel==1 pause
goto loop