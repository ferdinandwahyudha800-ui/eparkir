@echo off
REM Script compile dan run test bagian 2
REM Untuk Windows

echo ================================================
echo   COMPILE BAGIAN 2 - SLOT PARKIR & TIKET
echo ================================================
echo.

REM Cek apakah g++ terinstall
where g++ >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Compiler g++ tidak ditemukan!
    echo.
    echo Silakan install salah satu:
    echo 1. MSYS2: https://www.msys2.org/
    echo    Lalu: pacman -S mingw-w64-x86_64-gcc
    echo    Tambahkan C:\msys64\mingw64\bin ke PATH
    echo.
    echo 2. Atau gunakan online compiler: https://www.onlinegdb.com/
    echo.
    pause
    exit /b 1
)

echo [INFO] Compiler g++ ditemukan!
echo [INFO] Memulai kompilasi Bagian 2...
echo.

g++ -std=c++17 -Wall -Wextra -Iinclude ^
    src\Kendaraan.cpp src\Motor.cpp src\Mobil.cpp src\Truk.cpp ^
    src\SlotParkir.cpp src\Tiket.cpp src\Struk.cpp ^
    test_bagian2.cpp -o test_bagian2.exe

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ================================================
    echo   KOMPILASI BERHASIL!
    echo ================================================
    echo.
    echo Menjalankan program test bagian 2...
    echo.
    echo ================================================
    test_bagian2.exe
    echo ================================================
    echo.
    echo Program selesai dijalankan.
) else (
    echo.
    echo ================================================
    echo   KOMPILASI GAGAL!
    echo ================================================
    echo Periksa error di atas.
)

echo.
pause
