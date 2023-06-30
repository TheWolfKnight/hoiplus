@echo off

set FILE="main.cpp"
set FLAGS="-Wall -time -std=c++20 -o a.exe"
set COMP="g++"

set "TIME_FUNC= "

rem If you want to use a command to time your exe time
rem you can change the timecmd.cmd with the name of your desired command
where /Q timecmd.cmd
if %errorlevel% equ 0 set TIME_FUNC="timecmd"

%TIME_FUNC% call %COMP% -Wall -std=c++20 -o a.exe %FILE%
