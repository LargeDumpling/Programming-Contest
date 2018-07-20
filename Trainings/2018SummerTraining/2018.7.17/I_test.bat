@echo off
:loop
I_data.exe %random%
I.exe
I_BL.exe
fc I.out I_BL.out
if errorlevel==1 pause
goto loop