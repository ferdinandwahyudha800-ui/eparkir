@echo off
REM Script compile dan jalankan demo lengkap - Bagian 4

echo ================================================
echo   COMPILE DEMO LENGKAP - SIMULASI PARKIR PINTAR
echo ================================================
echo.

REM Cek apakah g++ terinstall
where g++ >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] Compiler g++ tidak ditemukan!
    echo.
    echo Silakan install salah satu:
    echo 1. MinGW-w64: https://www.mingw-w64.org/
    echo 2. MSYS2: https://www.msys2.org/
    echo 3. Atau gunakan online compiler: https://www.onlinegdb.com/
    echo.
    pause
    exit /b 1
)

echo [INFO] Compiler g++ ditemukan!
echo [INFO] Memulai kompilasi...
echo.

REM Compile
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src\Kendaraan.cpp src\Motor.cpp src\Mobil.cpp src\Truk.cpp src\Exception.cpp src\SlotParkir.cpp src\Tiket.cpp src\Struk.cpp src\TanpaDiskon.cpp src\DiskonMember.cpp src\HitungDurasi.cpp src\GedungParkir.cpp main.cpp -o parkir_pintar.exe

REM Cek hasil compile
if %ERRORLEVEL% EQU 0 (
    echo.
    echo ================================================
    echo   KOMPILASI BERHASIL!
    echo ================================================
    echo.
    echo Menjalankan program test...
    echo.
    echo ================================================
    parkir_pintar.exe
    echo ================================================
    echo.
    echo Program selesai dijalankan.
) else (
    echo.
    echo ================================================
    echo   KOMPILASI GAGAL!
    echo ================================================
    echo.
    echo Periksa error di atas dan perbaiki kode.
)

echo.
pause
