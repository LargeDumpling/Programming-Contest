@echo off
:loop
data.py
BIT.exe
zkw.exe
fc BIT.out zkw.out
if errorlevel==1 pause
goto loop