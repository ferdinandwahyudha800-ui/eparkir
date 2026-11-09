@echo off
echo Kompilasi test bagian 1...
g++ -std=c++17 -Wall -Wextra -o test_bagian1.exe test_bagian1.cpp src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp src/Exception.cpp

if %ERRORLEVEL% EQU 0 (
    echo.
    echo Kompilasi berhasil! Menjalankan test...
    echo.
    test_bagian1.exe
) else (
    echo.
    echo Kompilasi gagal!
)
