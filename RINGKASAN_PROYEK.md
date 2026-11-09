# 📊 RINGKASAN PROYEK
## Simulasi Parkir Pintar - C++ OOP

---

## 🎯 Tujuan Proyek
Membuat aplikasi konsol simulasi parkir untuk belajar **4 Pilar OOP**:
1. ✅ **Abstraksi** - Kelas abstrak Kendaraan & Diskon
2. ✅ **Pewarisan** - Motor, Mobil, Truk mewarisi Kendaraan
3. ✅ **Polimorfisme** - Method virtual dan override
4. ✅ **Enkapsulasi** - Data private dengan getter/setter

Plus: **Strategy Pattern** untuk diskon

---

## 👥 Pembagian Tugas (4 Orang)

### 🚗 Bagian 1: Kelas Dasar & Kendaraan ✅ (SUDAH SELESAI)
**File:**
- `include/Kendaraan.h` - Kelas abstrak
- `include/Motor.h`, `Mobil.h`, `Truk.h` - 3 jenis kendaraan
- `include/Exception.h` - Custom exceptions
- `src/*.cpp` - Implementasi
- `test_bagian1.cpp` - Program test

**Konsep OOP:** Abstraksi, Pewarisan, Polimorfisme, Enkapsulasi

**Status:** ✅ 100% SELESAI

---

### 🎫 Bagian 2: Slot & Tiket
**File yang harus dibuat:**
- `include/SlotParkir.h/cpp` - Enkapsulasi slot
- `include/Tiket.h/cpp` - Tiket parkir
- `include/Struk.h/cpp` - Struk pembayaran
- `test_bagian2.cpp`

**Konsep OOP:** Enkapsulasi, Asosiasi

**Ketergantungan:** Butuh Bagian 1 selesai dulu

**Estimasi:** 2 hari

---

### 💰 Bagian 3: Diskon & Tarif
**File yang harus dibuat:**
- `include/Diskon.h` - Interface (Strategy)
- `include/TanpaDiskon.h/cpp`
- `include/DiskonMember.h/cpp` - Diskon 20%
- `include/HitungDurasi.h/cpp` - Helper durasi
- `test_bagian3.cpp`

**Konsep OOP:** Strategy Pattern, Polimorfisme

**Ketergantungan:** Butuh Bagian 1 selesai dulu

**Estimasi:** 2 hari

---

### 🏢 Bagian 4: Gedung Parkir & Integrasi
**File yang harus dibuat:**
- `include/GedungParkir.h/cpp` - Kelas utama
- `main.cpp` - Demo semua skenario PRD
- `README.md` - Dokumentasi final
- `Makefile` atau `CMakeLists.txt` - Build final

**Konsep OOP:** Komposisi, Agregasi

**Ketergantungan:** Butuh Bagian 1, 2, 3 selesai SEMUA

**Estimasi:** 3 hari

---

## 📦 Struktur Folder Akhir

```
parkirin/
├── include/               # Header files (.h)
│   ├── Kendaraan.h       ✅ Bagian 1
│   ├── Motor.h           ✅ Bagian 1
│   ├── Mobil.h           ✅ Bagian 1
│   ├── Truk.h            ✅ Bagian 1
│   ├── Exception.h       ✅ Bagian 1
│   ├── SlotParkir.h      ⏳ Bagian 2
│   ├── Tiket.h           ⏳ Bagian 2
│   ├── Struk.h           ⏳ Bagian 2
│   ├── Diskon.h          ⏳ Bagian 3
│   ├── TanpaDiskon.h     ⏳ Bagian 3
│   ├── DiskonMember.h    ⏳ Bagian 3
│   ├── HitungDurasi.h    ⏳ Bagian 3
│   └── GedungParkir.h    ⏳ Bagian 4
│
├── src/                   # Implementation files (.cpp)
│   ├── Kendaraan.cpp     ✅ Bagian 1
│   ├── Motor.cpp         ✅ Bagian 1
│   ├── Mobil.cpp         ✅ Bagian 1
│   ├── Truk.cpp          ✅ Bagian 1
│   ├── SlotParkir.cpp    ⏳ Bagian 2
│   ├── Tiket.cpp         ⏳ Bagian 2
│   ├── Struk.cpp         ⏳ Bagian 2
│   ├── TanpaDiskon.cpp   ⏳ Bagian 3
│   ├── DiskonMember.cpp  ⏳ Bagian 3
│   ├── HitungDurasi.cpp  ⏳ Bagian 3
│   └── GedungParkir.cpp  ⏳ Bagian 4
│
├── test_bagian1.cpp      ✅ Test Bagian 1
├── test_bagian2.cpp      ⏳ Test Bagian 2
├── test_bagian3.cpp      ⏳ Test Bagian 3
├── main.cpp              ⏳ Demo final (Bagian 4)
│
├── Makefile              ✅ Build Bagian 1
├── README.md             ⏳ Dokumentasi final (Bagian 4)
│
└── docs/                 # Dokumentasi
    ├── PEMBAGIAN_TUGAS.md
    ├── DIAGRAM_OOP.md
    ├── README_BAGIAN1.md ✅
    ├── README_BAGIAN2.md ⏳
    ├── README_BAGIAN3.md ⏳
    └── README_BAGIAN4.md ⏳
```

---

## 🎯 Skenario yang Harus Lulus (dari PRD)

| # | Skenario | Bagian | Status |
|---|----------|--------|--------|
| 1 | Motor masuk dapat slot kecil | 4 | ⏳ |
| 2 | Slot kecil penuh, motor ditolak | 4 | ⏳ |
| 3 | Plat sama masuk 2x → error | 4 | ⏳ |
| 4 | Motor 45 menit → Rp2.000 | 1,3 | ✅ (tarif), ⏳ (durasi) |
| 5 | Mobil 3j 10m + diskon → Rp11.200 | 1,3 | ✅ (tarif), ⏳ (diskon) |
| 6 | Truk 5 jam → Rp34.000 | 1 | ✅ |
| 7 | Tiket palsu → error | 4 | ⏳ |
| 8 | Setelah keluar slot kosong | 2,4 | ⏳ |

---

## ⏰ Timeline Pengerjaan

### Minggu 1:
```
Hari 1-2: Bagian 1 (Kendaraan) ✅ SELESAI
          │
          ├── Share file ke Bagian 2 & 3
          │
Hari 3-4: Bagian 2 (Slot) ⏳
          Bagian 3 (Diskon) ⏳ (paralel)
```

### Minggu 2:
```
Hari 5-7: Bagian 4 (Integrasi) ⏳
          │
          ├── Gabung semua bagian
          ├── Test semua skenario
          └── Dokumentasi final

Hari 8:   Presentasi & Demo 🎉
```

---

## 🔧 Cara Compile

### Per Bagian (Testing):
```bash
# Bagian 1
g++ -std=c++17 -Wall -Wextra -Iinclude src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp test_bagian1.cpp -o test1

# Bagian 2 (setelah selesai)
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp test_bagian2.cpp -o test2

# Bagian 3 (setelah selesai)
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp test_bagian3.cpp -o test3
```

### Final (Semua Bagian):
```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp main.cpp -o parkir_simulator
```

Atau pakai Makefile:
```bash
make
./parkir_simulator
```

---

## 📊 Kriteria Keberhasilan

### Code Quality:
- ✅ Kompilasi tanpa error dan warning (`-Wall -Wextra`)
- ✅ Menggunakan C++17
- ✅ Tidak ada memory leak
- ✅ Tidak pakai `new`/`delete` manual
- ✅ Pakai smart pointer dan STL

### OOP:
- ✅ Keempat pilar OOP terlihat jelas
- ✅ Strategy pattern untuk diskon
- ✅ Virtual destructor
- ✅ Enkapsulasi data private

### Functionality:
- ✅ Semua skenario PRD lulus
- ✅ Exception handling bekerja
- ✅ Tarif dihitung benar
- ✅ Diskon diterapkan benar

---

## 📚 Aturan Tarif

| Kendaraan | Jam 1 | Jam Berikutnya | Slot |
|-----------|-------|----------------|------|
| Motor     | 2000  | 1000/jam       | KECIL |
| Mobil     | 5000  | 3000/jam       | SEDANG |
| Truk      | 10000 | 6000/jam       | BESAR |

**Diskon Member:** -20%

**Contoh:**
- Motor 3 jam: 2000 + (2×1000) = **Rp4.000**
- Mobil 4 jam: 5000 + (3×3000) = **Rp14.000**
- Mobil 4 jam (member): 14000 - 20% = **Rp11.200**

---

## 📄 Dokumentasi yang Sudah Ada

✅ **PEMBAGIAN_TUGAS.md** - Pembagian untuk 4 orang  
✅ **README_BAGIAN1.md** - Dokumentasi Bagian 1 lengkap  
✅ **TUGAS_TEMAN_2.md** - Petunjuk untuk Bagian 2  
✅ **TUGAS_TEMAN_3.md** - Petunjuk untuk Bagian 3  
✅ **TUGAS_TEMAN_4.md** - Petunjuk untuk Bagian 4  
✅ **DIAGRAM_OOP.md** - Diagram untuk presentasi  
✅ **CARA_COMPILE_WINDOWS.md** - Cara compile di Windows  
✅ **PETUNJUK_UNTUK_ANDA.md** - Petunjuk lengkap bagian Anda  

⏳ **README_BAGIAN2.md** - Tunggu Bagian 2 selesai  
⏳ **README_BAGIAN3.md** - Tunggu Bagian 3 selesai  
⏳ **README_BAGIAN4.md** - Tunggu Bagian 4 selesai  
⏳ **README.md** (final) - Dokumentasi lengkap proyek  

---

## ✅ Status Proyek

```
Progress: ███████░░░░░░░░░░░░░░░░░░░░░░░░ 25%

Bagian 1: ████████████████████████████ 100% ✅
Bagian 2: ░░░░░░░░░░░░░░░░░░░░░░░░░░░░   0% ⏳
Bagian 3: ░░░░░░░░░░░░░░░░░░░░░░░░░░░░   0% ⏳
Bagian 4: ░░░░░░░░░░░░░░░░░░░░░░░░░░░░   0% ⏳
```

---

## 🎉 Next Steps

### Untuk Anggota 1 (Anda):
1. ✅ Test kode di compiler
2. ✅ Screenshot output
3. ✅ Share file ke Bagian 2 & 3
4. ✅ Baca dokumentasi

### Untuk Anggota 2:
1. ⏳ Ambil file dari Bagian 1
2. ⏳ Baca TUGAS_TEMAN_2.md
3. ⏳ Mulai coding Slot & Tiket

### Untuk Anggota 3:
1. ⏳ Ambil file dari Bagian 1
2. ⏳ Baca TUGAS_TEMAN_3.md
3. ⏳ Mulai coding Diskon & Tarif

### Untuk Anggota 4:
1. ⏳ Tunggu Bagian 1, 2, 3 selesai
2. ⏳ Baca TUGAS_TEMAN_4.md
3. ⏳ Siapkan skenario integrasi

---

## 📞 Koordinasi Tim

### Meeting Checkpoint:
- **Hari 2:** Review Bagian 1 (sudah selesai ✅)
- **Hari 4:** Review Bagian 2 & 3
- **Hari 6:** Integrasi awal Bagian 4
- **Hari 7:** Final testing & dokumentasi

### Communication:
- Gunakan grup WhatsApp/Telegram
- Share progress harian
- Tanya jika ada masalah

---

**Semangat tim! 🚀 Bagian 1 sudah selesai, tinggal 3 bagian lagi!**
