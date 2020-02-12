@echo off
pushd %~dp0

rem Initialize environmental variables for the VSCode setting.
set MINGW_W64_VER="8.1.0"
set MINGW_W64_BASE_PATH="C:\Program Files\mingw-w64\x86_64-%MINGW_W64_VER%-posix-seh-rt_v6-rev0\mingw64"

call setx MINGW_W64_PATH "%MINGW_W64_BASE_PATH%"
call setx MINGW_W64_CPP_PATH "%MINGW_W64_BASE_PATH%\lib\gcc\x86_64-w64-mingw32\%MINGW_W64_VER%\include\c++"

popd
@echo on
