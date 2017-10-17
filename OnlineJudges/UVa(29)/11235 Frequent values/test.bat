@echo off
:loop
python data.py
code.exe
BL.exe
fc code.out Bl.out
if errorlevel==1 pause
goto loop
