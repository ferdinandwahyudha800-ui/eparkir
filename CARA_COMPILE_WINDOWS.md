# Cara Kompilasi di Windows

## ⚠️ Perlu Install Compiler Dulu

Kode C++ perlu compiler untuk dijalankan. Pilih salah satu:

### Opsi 1: MinGW-w64 (Recommended)
1. Download dari: https://www.mingw-w64.org/
2. Install dan tambahkan ke PATH
3. Verify: buka cmd, ketik `g++ --version`

### Opsi 2: Visual Studio
1. Download Visual Studio Community (gratis)
2. Pilih "Desktop development with C++"
3. Gunakan Developer Command Prompt

### Opsi 3: MSYS2 (Paling Mudah)
1. Download dari: https://www.msys2.org/
2. Install, lalu buka MSYS2 terminal
3. Jalankan: `pacman -S mingw-w64-x86_64-gcc`
4. Tambahkan `C:\msys64\mingw64\bin` ke PATH

---

## 🔨 Cara Compile

### Setelah Compiler Terinstall:

#### Windows CMD:
```cmd
g++ -std=c++17 -Wall -Wextra -Iinclude src\Kendaraan.cpp src\Motor.cpp src\Mobil.cpp src\Truk.cpp test_bagian1.cpp -o test_bagian1.exe
```

#### PowerShell:
```powershell
g++ -std=c++17 -Wall -Wextra -Iinclude src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp test_bagian1.cpp -o test_bagian1.exe
```

#### Jika sudah ada Make (MSYS2):
```bash
make
```

---

## ▶️ Cara Jalankan

Setelah compile berhasil:

```cmd
test_bagian1.exe
```

Atau double-click file `test_bagian1.exe`

---

## 🎓 Untuk Presentasi

Jika tidak bisa install compiler sendiri:
1. Gunakan **Online Compiler**:
   - https://www.onlinegdb.com/online_c++_compiler
   - https://replit.com/
   - https://godbolt.org/

2. Minta bantuan teman yang sudah install compiler

3. Gunakan lab komputer kampus

---

## ✅ Pastikan Struktur Folder

```
parkirin/
├── include/
│   ├── Kendaraan.h
│   ├── Motor.h
│   ├── Mobil.h
│   ├── Truk.h
│   └── Exception.h
├── src/
│   ├── Kendaraan.cpp
│   ├── Motor.cpp
│   ├── Mobil.cpp
│   └── Truk.cpp
└── test_bagian1.cpp
```

Struktur folder harus seperti ini agar `-Iinclude` bekerja!
