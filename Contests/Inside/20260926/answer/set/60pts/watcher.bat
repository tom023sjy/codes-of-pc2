@echo off
:loop
tasklist > tmp.txt && find "run.exe" tmp.txt
timeout /t 1 1>nul 2>nul
cls
goto loop