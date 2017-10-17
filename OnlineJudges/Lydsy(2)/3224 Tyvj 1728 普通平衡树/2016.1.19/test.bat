@echo off
:loop
shuju.exe
code.exe
treap.exe
fc code.out HG.out
if errorlevel==1 pause
goto loop
