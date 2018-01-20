@echo off
:loop
C_data.exe %random%
C.exe
C_BL.exe
fc C.out C_BL.out
if errorlevel==1 pause
goto loop