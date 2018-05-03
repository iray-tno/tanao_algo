@echo off
cd /d %~dp0

rem Install onqtam/doctest.
powershell -C (wget https://raw.githubusercontent.com/onqtam/doctest/master/doctest/doctest.h -OutFile ..\deps\doctest.h)

@echo on
