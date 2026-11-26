# ✅ BAGIAN ANDA SUDAH SELESAI!
## Petunjuk Lengkap untuk Anda

---

## 📦 Yang Sudah Saya Buatkan

### ✅ Kode C++ Anda (Bagian 1):
```
parkirin/
├── include/               ◄── Header files (.h)
│   ├── Kendaraan.h       ◄── Kelas abstrak
│   ├── Motor.h
│   ├── Mobil.h
│   ├── Truk.h
│   └── Exception.h       ◄── 3 custom exceptions
│
├── src/                  ◄── Implementation files (.cpp)
│   ├── Kendaraan.cpp
│   ├── Motor.cpp
│   ├── Mobil.cpp
│   └── Truk.cpp
│
└── test_bagian1.cpp      ◄── Program test Anda
```

### ✅ Dokumentasi:
- `README_BAGIAN1.md` - Dokumentasi lengkap bagian Anda
- `PEMBAGIAN_TUGAS.md` - Pembagian tugas kelompok
- `CARA_COMPILE_WINDOWS.md` - Cara compile di Windows
- `DIAGRAM_OOP.md` - Diagram untuk presentasi
- `Makefile` - Build script (jika ada compiler)

### ✅ File untuk Teman-teman:
- `TUGAS_TEMAN_2.md` - Slot & Tiket
- `TUGAS_TEMAN_3.md` - Diskon & Tarif
- `TUGAS_TEMAN_4.md` - Gedung Parkir & Integrasi

---

## 🎯 Apa yang Sudah Dibuat di Bagian Anda?

### 1️⃣ Kelas Abstrak `Kendaraan` (Kendaraan.h)
```cpp
class Kendaraan {
public:
    virtual int hitungTarif(int durasiJam) const = 0;  // Virtual murni
    virtual UkuranSlot ukuranSlotMinimum() const = 0;
    virtual ~Kendaraan() = default;  // Virtual destructor
};
```
**Konsep:** ABSTRAKSI

---

### 2️⃣ Kelas `Motor` (Motor.h/cpp)
- Tarif: Rp2.000 (jam pertama) + Rp1.000/jam (berikutnya)
- Slot: KECIL
- Contoh: 3 jam = Rp4.000

**Konsep:** PEWARISAN, POLIMORFISME

---

### 3️⃣ Kelas `Mobil` (Mobil.h/cpp)
- Tarif: Rp5.000 (jam pertama) + Rp3.000/jam (berikutnya)
- Slot: SEDANG
- Contoh: 4 jam = Rp14.000

**Konsep:** PEWARISAN, POLIMORFISME

---

### 4️⃣ Kelas `Truk` (Truk.h/cpp)
- Tarif: Rp10.000 (jam pertama) + Rp6.000/jam (berikutnya)
- Slot: BESAR
- Contoh: 5 jam = Rp34.000

**Konsep:** PEWARISAN, POLIMORFISME

---

### 5️⃣ Custom Exceptions (Exception.h)
```cpp
ParkirPenuhError             // Parkir penuh
TiketTidakDitemukanError     // Tiket tidak ada
KendaraanSudahParkirError    // Plat duplikat
```
**Konsep:** Exception Handling

---

### 6️⃣ Program Test (test_bagian1.cpp)
Test untuk:
- ✅ Motor: tarif dan slot
- ✅ Mobil: tarif dan slot
- ✅ Truk: tarif dan slot
- ✅ Polimorfisme dengan pointer `Kendaraan*`
- ✅ Semua exception

---

## 🚀 Cara Menjalankan Kode Anda

### Opsi 1: Pakai Compiler (Jika Sudah Install)

#### Windows CMD:
```cmd
g++ -std=c++17 -Wall -Wextra -Iinclude src\Kendaraan.cpp src\Motor.cpp src\Mobil.cpp src\Truk.cpp test_bagian1.cpp -o test_bagian1.exe

test_bagian1.exe
```

#### Atau pakai Makefile:
```bash
make
make run
```

---

### Opsi 2: Online Compiler (Mudah!)

1. Buka: https://www.onlinegdb.com/online_c++_compiler
2. Copy semua file ke satu file:
   - Isi `Kendaraan.h` (tanpa `#ifndef`)
   - Isi `Motor.h`, `Mobil.h`, `Truk.h`
   - Isi `Exception.h`
   - Isi semua `.cpp`
   - Isi `test_bagian1.cpp`
3. Pilih language: C++ 17
4. Klik Run!

---

### Opsi 3: Replit (Recommended!)

1. Buka: https://replit.com/
2. Create Repl → pilih C++
3. Upload semua file (drag & drop folder)
4. Run!

---

## 📋 Checklist Tugas Anda

- [x] Kelas abstrak `Kendaraan` dengan method virtual
- [x] Kelas `Motor` dengan tarif dan slot
- [x] Kelas `Mobil` dengan tarif dan slot
- [x] Kelas `Truk` dengan tarif dan slot
- [x] Virtual destructor
- [x] 3 Custom exceptions
- [x] Program test lengkap
- [x] Dokumentasi (README_BAGIAN1.md)
- [ ] **Test di compiler** ← INI YANG PERLU ANDA LAKUKAN
- [ ] **Pastikan tidak ada error**
- [ ] **Screenshot output untuk laporan**

---

## 📊 Output yang Diharapkan

Saat Anda run `test_bagian1`, output-nya:

```
================================================
  TEST BAGIAN 1: KELAS DASAR & KENDARAAN
================================================

Konsep OOP yang didemonstrasikan:
1. ABSTRAKSI - Kelas Kendaraan sebagai interface
2. PEWARISAN - Motor, Mobil, Truk mewarisi Kendaraan
3. POLIMORFISME - Method virtual dan override
4. ENKAPSULASI - Data private dan getter

================================================
TEST MOTOR
================================================
Jenis: Motor
Plat: B 1234 XYZ
Ukuran slot minimum: KECIL

Tarif Motor:
- 1 jam: Rp2000 (Expected: Rp2000)
- 2 jam: Rp3000 (Expected: Rp3000)
- 3 jam: Rp4000 (Expected: Rp4000)

================================================
TEST MOBIL
================================================
Jenis: Mobil
Plat: B 5678 ABC
Ukuran slot minimum: SEDANG

Tarif Mobil:
- 1 jam: Rp5000 (Expected: Rp5000)
- 4 jam: Rp14000 (Expected: Rp14000)

================================================
TEST TRUK
================================================
Jenis: Truk
Plat: B 9999 TRK
Ukuran slot minimum: BESAR

Tarif Truk:
- 1 jam: Rp10000 (Expected: Rp10000)
- 5 jam: Rp34000 (Expected: Rp34000)

================================================
TEST POLIMORFISME
================================================
Memanggil method melalui pointer Kendaraan*:
1. Motor (3 jam): Rp4000
2. Mobil (3 jam): Rp11000
3. Truk (3 jam): Rp22000

Polimorfisme berfungsi dengan baik!

================================================
TEST EXCEPTION
================================================
1. Testing ParkirPenuhError...
   Caught: Parkir penuh: Tidak ada slot yang tersedia untuk Motor
2. Testing TiketTidakDitemukanError...
   Caught: Tiket tidak ditemukan: TKT-999
3. Testing KendaraanSudahParkirError...
   Caught: Kendaraan dengan plat B 1234 XYZ sudah berada di dalam gedung

Semua exception berfungsi dengan baik!

================================================
SEMUA TEST SELESAI!
================================================
```

---

## 🎓 Untuk Presentasi

### Tunjukkan 4 Konsep OOP:

#### 1. **ABSTRAKSI**
Buka `Kendaraan.h`, tunjukkan:
```cpp
virtual int hitungTarif(int durasiJam) const = 0;  // = 0 berarti abstrak
```

#### 2. **PEWARISAN**
Buka `Motor.h`, tunjukkan:
```cpp
class Motor : public Kendaraan {  // ← Mewarisi Kendaraan
```

#### 3. **POLIMORFISME**
Tunjukkan output test polimorfisme:
- Satu pointer `Kendaraan*`
- Bisa menunjuk ke Motor/Mobil/Truk
- Runtime yang menentukan method mana yang dipanggil

#### 4. **ENKAPSULASI**
Buka `Motor.h`, tunjukkan:
```cpp
private:  // ← Data disembunyikan
    static const int TARIF_JAM_PERTAMA = 2000;
```

---

## 🤝 Koordinasi dengan Teman

### Beri File Ini ke Teman-teman:

**Untuk Teman 2:**
- `TUGAS_TEMAN_2.md`
- Semua file dari `include/` dan `src/` Anda
- Mereka butuh `Kendaraan.h` dan `Exception.h`

**Untuk Teman 3:**
- `TUGAS_TEMAN_3.md`
- Semua file dari `include/` dan `src/` Anda
- Mereka butuh `Kendaraan.h` untuk test

**Untuk Teman 4:**
- `TUGAS_TEMAN_4.md`
- Mereka akan integrasi SEMUA bagian
- Paling akhir dikerjakan

---

## ⚠️ PENTING!

### Deadline Anda:
Bagian Anda harus **SELESAI DULUAN** karena Bagian 2, 3, 4 butuh file Anda!

### Yang Harus Anda Lakukan Sekarang:
1. ✅ Test kode di compiler (online/offline)
2. ✅ Pastikan tidak ada error
3. ✅ Screenshot output
4. ✅ Share file ke teman-teman
5. ✅ Baca `README_BAGIAN1.md` untuk detail
6. ✅ Baca `DIAGRAM_OOP.md` untuk presentasi

---

## 🎉 Selamat!

Bagian Anda sudah **100% COMPLETE**! 🎊

Tinggal test dan pastikan tidak ada error.

**Semangat! 🚀**

---

## 📞 Jika Ada Masalah

### Error saat compile?
1. Cek struktur folder (harus ada `include/` dan `src/`)
2. Pastikan pakai `-std=c++17`
3. Pastikan pakai `-Iinclude` (I besar)
4. Coba compile manual satu per satu

### Tidak punya compiler?
1. Pakai online compiler (onlinegdb.com atau replit.com)
2. Install MinGW (lihat CARA_COMPILE_WINDOWS.md)
3. Pakai lab komputer kampus

---

**Good luck! 🎓**
