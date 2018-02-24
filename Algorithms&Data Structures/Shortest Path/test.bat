@echo off
:loop
data.exe
SPFA.exe
Hijkstra.exe
fc SPFA.txt Hijkstra.txt
if errorlevel==1 pause
goto loop