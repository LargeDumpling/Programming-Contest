@echo off
:loop
J_data.exe %random%
J.exe
J_BL.exe
fc J.out J_BL.out
if errorlevel==1 pause
goto loop