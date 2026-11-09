# Cara Install Compiler C++ di Windows

Untuk menjalankan proyek ini, Anda perlu compiler C++ yang mendukung C++17.

## Pilihan 1: MinGW-w64 (Rekomendasi untuk Windows)

### Download dan Install:
1. Download MSYS2 dari: https://www.msys2.org/
2. Install MSYS2
3. Buka MSYS2 terminal
4. Jalankan command berikut:
   ```bash
   pacman -Syu
   pacman -S mingw-w64-x86_64-gcc
   ```
5. Tambahkan ke PATH:
   - Buka "Edit Environment Variables"
   - Tambahkan: `C:\msys64\mingw64\bin` ke PATH
   - Restart terminal/command prompt

### Test Instalasi:
```cmd
g++ --version
```

---

## Pilihan 2: Microsoft Visual Studio

### Download dan Install:
1. Download Visual Studio Community (gratis): https://visualstudio.microsoft.com/
2. Saat instalasi, pilih "Desktop development with C++"
3. Setelah selesai, buka "Developer Command Prompt for VS"

### Kompilasi dengan Visual Studio:
```cmd
cl /EHsc /std:c++17 Kendaraan.cpp Motor.cpp Mobil.cpp Truk.cpp Exception.cpp test_bagian1.cpp /Fe:test_bagian1.exe
```

---

## Pilihan 3: Online Compiler (Untuk Test Cepat)

Jika tidak bisa install, bisa pakai online compiler:
- **OnlineGDB:** https://www.onlinegdb.com/online_c++_compiler
- **Repl.it:** https://replit.com/languages/cpp

### Cara pakai:
1. Copy semua file .h dan .cpp
2. Paste ke online compiler
3. Set language ke C++17
4. Run

---

## Setelah Compiler Terinstall

### Kompilasi proyek:
```cmd
g++ -std=c++17 -Wall -Wextra Kendaraan.cpp Motor.cpp Mobil.cpp Truk.cpp Exception.cpp test_bagian1.cpp -o test_bagian1
```

### Jalankan program:
```cmd
test_bagian1.exe
```

---

## Troubleshooting

### Error: "g++ not recognized"
- Pastikan g++ sudah ada di PATH
- Restart terminal setelah install
- Cek dengan: `where g++`

### Error: "C++17 not supported"
- Update compiler ke versi terbaru
- MinGW-w64 versi 7.0 atau lebih baru support C++17

### Error saat kompilasi
- Pastikan semua file .h dan .cpp ada di folder yang sama
- Cek typo di nama file
- Pastikan tidak ada spasi di path folder

---

## Catatan Penting

Proyek ini sudah ditulis dengan C++17 standard dan siap dikompilasi. File-file yang sudah dibuat:

✅ **Header Files (.h):**
- Kendaraan.h
- Motor.h
- Mobil.h
- Truk.h
- Exception.h

✅ **Implementation Files (.cpp):**
- Kendaraan.cpp
- Motor.cpp
- Mobil.cpp
- Truk.cpp
- Exception.cpp
- test_bagian1.cpp

✅ **Build Tools:**
- Makefile (untuk Linux/Mac/MSYS2)

✅ **Documentation:**
- README_BAGIAN1.md
- PEMBAGIAN_TUGAS.md

Semua kode sudah sesuai standar C++17, menggunakan smart pointer, dan tanpa warning pada `-Wall -Wextra`.
