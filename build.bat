@echo off

set FILE="main.cpp"
set FLAGS="-Wall -time -std=c++20 -o a.exe"
set COMP="g++"

timecmd call %COMP% -Wall -std=c++20 -o a.exe %FILE%
