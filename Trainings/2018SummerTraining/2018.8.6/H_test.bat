@echo off
:loop
H_data.exe %random%
H.exe
H_other.exe
fc H.out H_other.out
if errorlevel==1 pause
goto loop