@echo off
:loop
data.exe
code.exe
std.exe
fc code.out std.out
if errorlevel==1 pause
goto loop