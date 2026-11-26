@echo off
echo ================================================
echo   COMPILE ALL TESTS - BAGIAN 1
echo ================================================
echo.

echo [1/2] Compiling test_bagian1.cpp (OOP Dasar)...
g++ -std=c++17 -Wall -Wextra -Iinclude src\Kendaraan.cpp src\Motor.cpp src\Mobil.cpp src\Truk.cpp src\Exception.cpp test_bagian1.cpp -o test_bagian1.exe

if %ERRORLEVEL% EQU 0 (
    echo ✓ test_bagian1.exe compiled successfully!
) else (
    echo ✗ test_bagian1.cpp compilation failed!
    pause
    exit /b 1
)

echo.
echo [2/2] Compiling test_advanced_features.cpp (Setter, Dict, Generic)...
g++ -std=c++17 -Wall -Wextra -Iinclude src\Kendaraan.cpp src\Motor.cpp src\Mobil.cpp src\Truk.cpp test_advanced_features.cpp -o test_advanced.exe

if %ERRORLEVEL% EQU 0 (
    echo ✓ test_advanced.exe compiled successfully!
) else (
    echo ✗ test_advanced_features.cpp compilation failed!
    pause
    exit /b 1
)

echo.
echo ================================================
echo   COMPILATION SUCCESS!
echo ================================================
echo.
echo Available programs:
echo   - test_bagian1.exe        (OOP Dasar)
echo   - test_advanced.exe       (Fitur Advanced)
echo.
echo Run test_bagian1.exe to test OOP basics
echo Run test_advanced.exe to test Setter, Dictionary, Generic
echo.
pause
