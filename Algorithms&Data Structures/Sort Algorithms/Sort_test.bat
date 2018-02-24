@echo off
:loop
Sort_data.exe
Sort.exe
Quick_Sort.exe
fc Quick_Sort.out Sort.out
if errorlevel==1 pause
goto loop