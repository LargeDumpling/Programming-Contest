@echo off
:loop
data.py
zkw.exe
BIT.exe
fc code.out BIT.out
if errorlevel==1 pause
goto loop