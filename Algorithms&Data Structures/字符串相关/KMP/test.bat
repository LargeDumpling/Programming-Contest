@echo off
:loop
data.exe
Hash.exe
����ѵ��2015_12_24.exe
fc code.out Hash.out
if errorlevel==1 pause
goto loop