# 📦 SUBMISSION BAGIAN 1 - KELAS KENDARAAN & FITUR ADVANCED

**Nama:** [Nama Anda]  
**NIM:** [NIM Anda]  
**Bagian:** 1 - Kelas Dasar Kendaraan + Fitur Advanced (Setter, Dictionary, Generic)  
**Repository:** https://github.com/ferdinandwahyudha800-ui/eparkir

---

## 📋 Deskripsi

Folder ini berisi **HANYA pekerjaan Bagian 1** yang merupakan kontribusi saya dalam proyek kelompok Sistem Parkir Pintar. Folder ini terpisah dari pekerjaan teman-teman (Bagian 2, 3, 4).

---

## 🎯 Fitur yang Diimplementasi

### **Commit 1: Bagian 1 Awal (2 weeks ago)**
1. ✅ Kelas Abstrak `Kendaraan` (Interface)
2. ✅ Kelas `Motor` (Inheritance)
3. ✅ Kelas `Mobil` (Inheritance)
4. ✅ Kelas `Truk` (Inheritance)
5. ✅ Custom Exceptions (3 jenis)
6. ✅ Test program dasar

### **Commit 2: Fitur Advanced (Latest)**
7. ✅ **SETTER** - Method untuk mengubah data
8. ✅ **DICTIONARY** - std::map untuk metadata dinamis
9. ✅ **GENERIC/TEMPLATE** - Template functions
10. ✅ Test program advanced
11. ✅ Dokumentasi lengkap

---

## 📁 Struktur Folder

```
SUBMISSION_BAGIAN_1/
├── include/
│   ├── Kendaraan.h       ← Abstract class + setter + dictionary + generic
│   ├── Motor.h           ← Child class 1
│   ├── Mobil.h           ← Child class 2
│   ├── Truk.h            ← Child class 3
│   └── Exception.h       ← Custom exceptions
│
├── src/
│   ├── Kendaraan.cpp     ← Implementation + setter + dictionary
│   ├── Motor.cpp         ← Motor implementation
│   ├── Mobil.cpp         ← Mobil implementation
│   ├── Truk.cpp          ← Truk implementation
│   └── Exception.cpp     ← Exception implementation
│
├── test_bagian1.cpp              ← Test OOP dasar
├── test_advanced_features.cpp    ← Test setter, dict, generic
├── compile_test_advanced.bat     ← Compile script
│
├── POTONGAN_KODE_PROGRES.md      ← ⭐ File potongan kode untuk dikumpulkan
├── FITUR_ADVANCED.md             ← Dokumentasi fitur baru
├── CHEAT_SHEET.md                ← Quick reference presentasi
├── RINGKASAN_UPDATE.md           ← Summary update
├── README_BAGIAN1.md             ← Dokumentasi bagian 1 awal
├── RINGKASAN_BAGIAN_ANDA.md      ← Ringkasan pekerjaan
├── PETUNJUK_UNTUK_ANDA.md        ← Petunjuk lengkap
├── DIAGRAM_OOP.md                ← Diagram untuk presentasi
└── README.md                     ← File ini
```

---

## 🔧 Cara Compile & Run

### **Opsi 1: Test OOP Dasar**
```bash
# Windows CMD
g++ -std=c++17 -Wall -Wextra -Iinclude src\*.cpp test_bagian1.cpp -o test_bagian1.exe
test_bagian1.exe
```

### **Opsi 2: Test Fitur Advanced (Setter, Dictionary, Generic)**
```bash
# Windows CMD
compile_test_advanced.bat

# Atau manual:
g++ -std=c++17 -Wall -Wextra -Iinclude src\*.cpp test_advanced_features.cpp -o test_advanced.exe
test_advanced.exe
```

### **Opsi 3: Online Compiler**
1. Buka https://www.onlinegdb.com/online_c++_compiler
2. Copy semua file header + source + test
3. Pilih C++ 17
4. Run

---

## 📊 Konsep OOP yang Diimplementasi

### **4 Pilar OOP:**
| Konsep | Implementasi | Lokasi |
|--------|--------------|--------|
| **Abstraksi** | Class `Kendaraan` dengan pure virtual | `Kendaraan.h` |
| **Pewarisan** | Motor, Mobil, Truk extends Kendaraan | `Motor.h`, `Mobil.h`, `Truk.h` |
| **Polimorfisme** | Virtual method override | Semua child classes |
| **Enkapsulasi** | Private/protected + getter/setter | Semua classes |

### **Konsep Tambahan:**
| Konsep | Implementasi | Lokasi |
|--------|--------------|--------|
| **Variable** | Member, static, local | Semua files |
| **Getter** | getPlatNomor(), getProperti() | `Kendaraan.h/cpp` |
| **Setter** | setPlatNomor(), setProperti() | `Kendaraan.h/cpp` |
| **Method** | Regular, virtual, constructor | Semua files |
| **Interface** | Abstract class Kendaraan | `Kendaraan.h` |
| **Abstract** | Pure virtual methods (= 0) | `Kendaraan.h` |
| **Collection** | Vector, Map | `test_advanced_features.cpp` |
| **Dictionary** | std::map propertiTambahan | `Kendaraan.h/cpp` |
| **Generic** | Template functions | `Kendaraan.h` |
| **Exception** | Custom exception classes | `Exception.h/cpp` |

---

## 📄 File Penting untuk Dikumpulkan

### **1. POTONGAN_KODE_PROGRES.md** ⭐ PRIORITAS UTAMA
Berisi potongan kode lengkap untuk 10 konsep OOP:
- Variable, Getter, Setter
- Method, Inheritance, Interface, Abstract
- Collection, Dictionary, Generic

**Format:** Sudah siap copy-paste ke laporan/dokumen

### **2. FITUR_ADVANCED.md**
Dokumentasi lengkap untuk fitur baru:
- Penjelasan Setter
- Penjelasan Dictionary (std::map)
- Penjelasan Generic/Template
- Use case dan contoh

### **3. CHEAT_SHEET.md**
Quick reference untuk presentasi:
- Script 60 detik
- Demo checklist
- Jawaban Q&A
- Timing guide

### **4. Source Code**
- `include/*.h` - Header files
- `src/*.cpp` - Implementation files
- `test_*.cpp` - Test programs

---

## 🎓 Untuk Presentasi

### **Demo 1: OOP Dasar (2 menit)**
1. Tunjukkan abstract class `Kendaraan`
2. Tunjukkan inheritance: Motor, Mobil, Truk
3. Demo polymorphism dengan test_bagian1.cpp
4. Tunjukkan exception handling

### **Demo 2: Fitur Advanced (3 menit)**
1. **Setter**: Demo mengubah plat nomor
2. **Dictionary**: Demo properti tambahan (warna, tahun, pemilik)
3. **Generic**: Demo hitungTotalTarif(), filterKendaraan()

### **Tips:**
- Buka `CHEAT_SHEET.md` untuk script lengkap
- Screenshot output program untuk backup
- Siapkan jawaban untuk Q&A umum

---

## 📸 Screenshot yang Dibutuhkan

1. ✅ Output `test_bagian1.exe` (OOP dasar)
2. ✅ Output `test_advanced_features.exe` (fitur baru)
3. ✅ Code editor: `include/Kendaraan.h` (tunjukkan dictionary & generic)
4. ✅ Code editor: `src/Kendaraan.cpp` (tunjukkan setter implementation)
5. ✅ GitHub commit history
6. ✅ File `POTONGAN_KODE_PROGRES.md` terbuka

---

## 🔗 Link Repository

**Main Repository:**
```
https://github.com/ferdinandwahyudha800-ui/eparkir
```

**Folder Ini di Repository:**
```
https://github.com/ferdinandwahyudha800-ui/eparkir/tree/main/SUBMISSION_BAGIAN_1
```

---

## 📝 Catatan

### **Perbedaan dengan Folder Utama:**
- Folder utama (`/`) berisi **semua bagian** (1, 2, 3, 4) dari kelompok
- Folder ini (`/SUBMISSION_BAGIAN_1/`) berisi **HANYA Bagian 1** (pekerjaan saya)

### **Kenapa Terpisah?:**
- Untuk pengumpulan individual per anggota kelompok
- Memudahkan identifikasi kontribusi masing-masing
- File lebih terorganisir untuk review

### **Dependensi:**
Bagian ini **standalone** dan bisa dicompile sendiri tanpa file dari Bagian 2, 3, 4.

---

## ✅ Checklist Submission

- [x] Semua source code lengkap
- [x] Test program berfungsi
- [x] Dokumentasi lengkap
- [x] Potongan kode tersedia
- [x] Screenshot diambil
- [x] Presentasi disiapkan
- [ ] File di-zip untuk submission
- [ ] Dikumpulkan ke dosen

---

## 🎉 Status: SIAP DIKUMPULKAN!

Semua file dalam folder ini adalah **100% pekerjaan Bagian 1** yang merupakan kontribusi saya dalam proyek kelompok. File sudah lengkap, tertest, dan terdokumentasi dengan baik.

---

**Dibuat:** 26 November 2026  
**Last Update:** 26 November 2026  
**Version:** 2.0 (dengan fitur advanced)
