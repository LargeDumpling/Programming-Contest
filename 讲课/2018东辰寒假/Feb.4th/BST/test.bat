@echo off
:loop
data.exe %random%
BST.exe
Set.exe
fc BST.out Set.out
if errorlevel==1 pause
goto loop