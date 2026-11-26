@echo off
echo ================================================
echo   COMPILE TEST ADVANCED FEATURES
echo ================================================
echo.

echo Compiling with g++...
g++ -std=c++17 -Wall -Wextra -Iinclude src\Kendaraan.cpp src\Motor.cpp src\Mobil.cpp src\Truk.cpp test_advanced_features.cpp -o test_advanced_features.exe

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ================================================
    echo   COMPILATION SUCCESS!
    echo ================================================
    echo.
    echo Running test_advanced_features.exe...
    echo.
    test_advanced_features.exe
    echo.
    echo ================================================
    echo   TEST COMPLETED!
    echo ================================================
) else (
    echo.
    echo ================================================
    echo   COMPILATION FAILED!
    echo ================================================
    echo Please check the error messages above.
)

echo.
pause
