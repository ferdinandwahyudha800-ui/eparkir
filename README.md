# 🚗 Simulasi Parkir Pintar
### Proyek Pembelajaran C++ OOP - Kelompok 4

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)
[![Status](https://img.shields.io/badge/Status-In%20Progress-yellow.svg)]()
[![Progress](https://img.shields.io/badge/Progress-25%25-orange.svg)]()

---

## 📖 Tentang Proyek

Simulasi Parkir Pintar adalah aplikasi konsol berbasis C++17 yang mensimulasikan pengelolaan gedung parkir dengan fokus pada penerapan **4 Pilar OOP** (Object-Oriented Programming):

1. ✅ **Abstraksi** - Interface tanpa implementasi
2. ✅ **Pewarisan** - Kelas turunan mewarisi parent
3. ✅ **Polimorfisme** - Satu interface, banyak bentuk
4. ✅ **Enkapsulasi** - Data private dengan getter/setter

**Plus:** Implementasi **Strategy Pattern** untuk sistem diskon.

---

## 👥 Tim Pengembang

| Nama | Bagian | Status |
|------|--------|--------|
| [Anggota 1] | Kelas Dasar & Kendaraan | ✅ SELESAI |
| [Anggota 2] | Slot & Tiket | ⏳ In Progress |
| [Anggota 3] | Diskon & Tarif | ⏳ In Progress |
| [Anggota 4] | Gedung Parkir & Integrasi | ⏳ Waiting |

---

## 🎯 Fitur Utama

### MVP (Version 1.0)
- ✅ **3 Jenis Kendaraan:** Motor, Mobil, Truk
- ⏳ **3 Ukuran Slot:** Kecil, Sedang, Besar
- ⏳ **Alokasi Slot Otomatis:** Sistem memilih slot terkecil yang muat
- ⏳ **Perhitungan Tarif:** Otomatis berdasarkan jenis kendaraan dan durasi
- ⏳ **Sistem Diskon:** Tanpa diskon atau Diskon Member 20%
- ⏳ **Exception Handling:** Parkir penuh, tiket tidak ada, plat duplikat
- ⏳ **Laporan Status:** Slot kosong dan total pendapatan

---

## 📁 Struktur Folder

```
parkirin/
├── 📂 include/          # Header files (.h)
│   ├── ✅ Kendaraan.h
│   ├── ✅ Motor.h
│   ├── ✅ Mobil.h
│   ├── ✅ Truk.h
│   ├── ✅ Exception.h
│   ├── ⏳ SlotParkir.h
│   ├── ⏳ Tiket.h
│   ├── ⏳ Struk.h
│   ├── ⏳ Diskon.h
│   ├── ⏳ TanpaDiskon.h
│   ├── ⏳ DiskonMember.h
│   ├── ⏳ HitungDurasi.h
│   └── ⏳ GedungParkir.h
│
├── 📂 src/              # Implementation (.cpp)
│   ├── ✅ Kendaraan.cpp
│   ├── ✅ Motor.cpp
│   ├── ✅ Mobil.cpp
│   ├── ✅ Truk.cpp
│   └── ⏳ (sisanya sedang dikerjakan)
│
├── 🧪 test_bagian1.cpp   # Test Bagian 1 ✅
├── ⏳ test_bagian2.cpp   # Test Bagian 2
├── ⏳ test_bagian3.cpp   # Test Bagian 3
├── ⏳ main.cpp           # Program utama
│
├── 🔨 Makefile           # Build script
├── 📄 README.md          # Dokumentasi ini
└── 📚 docs/              # Dokumentasi lengkap
```

---

## 🚀 Cara Menggunakan

### Prasyarat
- Compiler C++ yang mendukung C++17 (g++, clang++, MSVC)
- Make (opsional, untuk build otomatis)

### Instalasi Compiler

#### Windows:
```bash
# Opsi 1: MinGW-w64
Download: https://www.mingw-w64.org/

# Opsi 2: MSYS2 (Recommended)
Download: https://www.msys2.org/
pacman -S mingw-w64-x86_64-gcc
```

#### Linux:
```bash
sudo apt update
sudo apt install g++ make
```

#### macOS:
```bash
xcode-select --install
```

### Kompilasi

#### Menggunakan Makefile (Recommended):
```bash
make            # Kompilasi
make run        # Jalankan test
make clean      # Bersihkan build files
```

#### Manual (Windows):
```cmd
g++ -std=c++17 -Wall -Wextra -Iinclude src\Kendaraan.cpp src\Motor.cpp src\Mobil.cpp src\Truk.cpp test_bagian1.cpp -o test_bagian1.exe

test_bagian1.exe
```

#### Manual (Linux/macOS):
```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp test_bagian1.cpp -o test_bagian1

./test_bagian1
```

#### Batch Script (Windows):
```cmd
compile_and_run.bat
```

---

## 📊 Aturan Tarif

| Kendaraan | Jam Pertama | Jam Berikutnya | Ukuran Slot |
|-----------|-------------|----------------|-------------|
| 🏍️ Motor  | Rp 2.000    | Rp 1.000/jam   | KECIL       |
| 🚗 Mobil  | Rp 5.000    | Rp 3.000/jam   | SEDANG      |
| 🚚 Truk   | Rp 10.000   | Rp 6.000/jam   | BESAR       |

**Catatan:**
- Durasi dibulatkan ke atas per jam
- Minimal durasi adalah 1 jam
- Diskon Member: -20% dari total tarif

### Contoh Perhitungan:
```
Motor parkir 3 jam 10 menit:
→ Dihitung 4 jam
→ Rp 2.000 + (3 × Rp 1.000) = Rp 4.000

Mobil parkir 3 jam 10 menit dengan Diskon Member:
→ Dihitung 4 jam
→ Rp 5.000 + (3 × Rp 3.000) = Rp 14.000
→ Diskon 20%: Rp 14.000 - Rp 2.800 = Rp 11.200
```

---

## 🎓 Konsep OOP yang Diterapkan

### 1. Abstraksi
```cpp
class Kendaraan {
    virtual int hitungTarif(int durasiJam) const = 0;  // Pure virtual
    virtual UkuranSlot ukuranSlotMinimum() const = 0;
};
```
**Kelas abstrak** menyediakan interface tanpa implementasi.

### 2. Pewarisan
```cpp
class Motor : public Kendaraan {
    // Motor mewarisi semua member dari Kendaraan
};
```
**Motor, Mobil, Truk** mewarisi dari **Kendaraan**.

### 3. Polimorfisme
```cpp
Kendaraan* k = new Motor("B 1234 XYZ");
k->hitungTarif(3);  // Runtime memanggil Motor::hitungTarif()
```
**Satu interface, banyak implementasi.**

### 4. Enkapsulasi
```cpp
class SlotParkir {
private:
    bool kosong;  // Data tersembunyi
public:
    bool isKosong() const { return kosong; }  // Akses lewat method
};
```
**Data private, akses lewat public method.**

### 5. Strategy Pattern
```cpp
class Diskon {
    virtual int terapkanDiskon(int tarif) const = 0;
};

class TanpaDiskon : public Diskon { ... }
class DiskonMember : public Diskon { ... }
```
**Ganti algoritma diskon tanpa ubah kode lain.**

---

## 🧪 Testing

### Test Bagian 1 (Kendaraan) ✅
```bash
./test_bagian1
```

Output:
```
================================================
  TEST BAGIAN 1: KELAS DASAR & KENDARAAN
================================================
✅ Motor: Rp2000 + Rp1000/jam → Slot KECIL
✅ Mobil: Rp5000 + Rp3000/jam → Slot SEDANG
✅ Truk: Rp10000 + Rp6000/jam → Slot BESAR
✅ Polimorfisme: Kendaraan* → Motor/Mobil/Truk
✅ Exception: ParkirPenuh, TiketTidakDitemukan, KendaraanSudahParkir
================================================
SEMUA TEST SELESAI!
================================================
```

### Test Lainnya (Coming Soon)
- ⏳ `test_bagian2` - Slot & Tiket
- ⏳ `test_bagian3` - Diskon & Tarif
- ⏳ `main` - Demo lengkap semua skenario

---

## 📚 Dokumentasi Lengkap

| File | Deskripsi |
|------|-----------|
| [PEMBAGIAN_TUGAS.md](PEMBAGIAN_TUGAS.md) | Pembagian untuk 4 anggota kelompok |
| [README_BAGIAN1.md](README_BAGIAN1.md) | Dokumentasi Bagian 1 (Kendaraan) ✅ |
| [TUGAS_TEMAN_2.md](TUGAS_TEMAN_2.md) | Petunjuk Bagian 2 (Slot & Tiket) |
| [TUGAS_TEMAN_3.md](TUGAS_TEMAN_3.md) | Petunjuk Bagian 3 (Diskon) |
| [TUGAS_TEMAN_4.md](TUGAS_TEMAN_4.md) | Petunjuk Bagian 4 (Integrasi) |
| [DIAGRAM_OOP.md](DIAGRAM_OOP.md) | Diagram konsep OOP untuk presentasi |
| [CARA_COMPILE_WINDOWS.md](CARA_COMPILE_WINDOWS.md) | Panduan compile di Windows |
| [PETUNJUK_UNTUK_ANDA.md](PETUNJUK_UNTUK_ANDA.md) | Petunjuk lengkap Bagian 1 |
| [RINGKASAN_PROYEK.md](RINGKASAN_PROYEK.md) | Ringkasan keseluruhan proyek |

---

## 🎯 Skenario yang Harus Lulus

Sesuai dengan PRD (Product Requirements Document):

| # | Skenario | Expected Result | Status |
|---|----------|-----------------|--------|
| 1 | Motor masuk, slot kecil kosong | Dapat slot kecil, tiket terbit | ⏳ |
| 2 | Semua slot kecil penuh, motor ketiga masuk | Ditolak dengan pesan error | ⏳ |
| 3 | Plat yang sama masuk dua kali | `KendaraanSudahParkirError` | ✅ |
| 4 | Motor parkir 45 menit | Tarif Rp2.000 (1 jam) | ✅ |
| 5 | Mobil parkir 3 jam 10 menit dengan diskon member | Tarif Rp14.000, bayar Rp11.200 | ⏳ |
| 6 | Truk parkir 5 jam | Tarif Rp34.000 | ✅ |
| 7 | ID tiket tidak dikenal saat keluar | `TiketTidakDitemukanError` | ✅ |
| 8 | Setelah kendaraan keluar | Slot kembali kosong, pendapatan bertambah | ⏳ |

---

## 📅 Timeline Pengerjaan

```
Minggu 1:
├── Hari 1-2: ✅ Bagian 1 (Kendaraan) - SELESAI
├── Hari 3-4: ⏳ Bagian 2 (Slot & Tiket)
└── Hari 3-4: ⏳ Bagian 3 (Diskon) - paralel

Minggu 2:
├── Hari 5-7: ⏳ Bagian 4 (Integrasi & Testing)
└── Hari 8:   🎉 Presentasi & Demo
```

---

## ⚡ Quick Start

### 1. Clone atau Download Proyek
```bash
git clone [URL_REPO]
cd parkirin
```

### 2. Test Bagian 1 (Yang Sudah Selesai)
```bash
# Compile
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp test_bagian1.cpp -o test1

# Run
./test1
```

### 3. Tunggu Bagian Lain Selesai
Bagian 2, 3, 4 sedang dikerjakan oleh anggota tim lain.

---

## 🔧 Troubleshooting

### Error: `g++: command not found`
**Solusi:** Install compiler terlebih dahulu (lihat bagian Instalasi Compiler)

### Error: `No such file or directory: include/Kendaraan.h`
**Solusi:** Pastikan Anda berada di folder root proyek (`parkirin/`)

### Warning: `-Wall -Wextra`
**Solusi:** Fix semua warning! Kode harus compile tanpa warning.

### Online Compiler (Alternatif)
Jika tidak bisa install compiler:
- https://www.onlinegdb.com/online_c++_compiler
- https://replit.com/
- https://godbolt.org/

---

## 📋 Progress Checklist

### ✅ Bagian 1: Kelas Dasar & Kendaraan (100%)
- [x] Kelas abstrak Kendaraan
- [x] Motor, Mobil, Truk
- [x] Exception handling
- [x] Test lengkap
- [x] Dokumentasi

### ⏳ Bagian 2: Slot & Tiket (0%)
- [ ] SlotParkir dengan enkapsulasi
- [ ] Tiket dengan asosiasi
- [ ] Struk pembayaran
- [ ] Test lengkap

### ⏳ Bagian 3: Diskon & Tarif (0%)
- [ ] Interface Diskon (Strategy)
- [ ] TanpaDiskon
- [ ] DiskonMember 20%
- [ ] HitungDurasi helper
- [ ] Test lengkap

### ⏳ Bagian 4: Gedung Parkir & Integrasi (0%)
- [ ] GedungParkir dengan komposisi
- [ ] Demo semua skenario
- [ ] README final
- [ ] Build system final

---

## 📄 Lisensi

Proyek ini dibuat untuk tujuan pembelajaran dalam mata kuliah Pemrograman Berorientasi Objek.

---

## 🙏 Acknowledgments

- **Dosen Pengampu:** [Nama Dosen]
- **Mata Kuliah:** Pemrograman Berorientasi Objek
- **Semester:** [Semester/Tahun]
- **Universitas:** [Nama Universitas]

---

## 📞 Kontak

Untuk pertanyaan atau diskusi proyek:
- **Kelompok:** 4
- **Anggota 1:** [Nama] - [Email]
- **Anggota 2:** [Nama] - [Email]
- **Anggota 3:** [Nama] - [Email]
- **Anggota 4:** [Nama] - [Email]

---

<div align="center">

**🚀 Dibuat dengan ❤️ oleh Kelompok 4**

[![Status](https://img.shields.io/badge/Status-In%20Progress-yellow.svg)]()
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/w/cpp/17)

</div>
