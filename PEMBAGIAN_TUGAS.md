# Pembagian Tugas Proyek Simulasi Parkir Pintar

**Proyek:** Simulasi Parkir Pintar (C++ OOP)  
**Tim:** 4 Orang  
**Deadline:** Sesuai kesepakatan kelompok

---

## 👤 **BAGIAN 1: Kelas Dasar & Kendaraan** ✅ SELESAI
**Penanggung Jawab:** [Nama Anda]

### File yang Dikerjakan:
- ✅ `Kendaraan.h` - Kelas abstrak Kendaraan
- ✅ `Kendaraan.cpp` - Implementasi Kendaraan
- ✅ `Motor.h` - Header Motor
- ✅ `Motor.cpp` - Implementasi Motor
- ✅ `Mobil.h` - Header Mobil
- ✅ `Mobil.cpp` - Implementasi Mobil
- ✅ `Truk.h` - Header Truk
- ✅ `Truk.cpp` - Implementasi Truk
- ✅ `Exception.h` - Custom exceptions
- ✅ `Exception.cpp` - Implementasi exceptions
- ✅ `test_bagian1.cpp` - Program test
- ✅ `Makefile` - Build script
- ✅ `README_BAGIAN1.md` - Dokumentasi

### Konsep OOP:
- ✅ Abstraksi (kelas Kendaraan abstrak)
- ✅ Pewarisan (Motor, Mobil, Truk extend Kendaraan)
- ✅ Polimorfisme (method virtual, override)
- ✅ Enkapsulasi (protected/private members)
- ✅ Exception handling

### Cara Test:
```bash
# Kompilasi
g++ -std=c++17 -Wall -Wextra Kendaraan.cpp Motor.cpp Mobil.cpp Truk.cpp Exception.cpp test_bagian1.cpp -o test_bagian1

# Jalankan
./test_bagian1
```

---

## 👤 **BAGIAN 2: Slot & Tiket**
**Penanggung Jawab:** [Nama Teman 1]

### File yang Harus Dikerjakan:

#### 1. `SlotParkir.h` dan `SlotParkir.cpp`
**Tanggung jawab:**
- Class `SlotParkir` dengan atribut private:
  - `std::string kodeSlot` (contoh: "A01", "B12")
  - `UkuranSlot ukuran` (enum dari Kendaraan.h)
  - `bool terisi`
  - `Kendaraan* kendaraanTerparkir` (pointer ke kendaraan yang parkir)

**Method yang perlu dibuat:**
- Constructor: `SlotParkir(string kode, UkuranSlot ukuran)`
- `bool isTerisi() const` - cek apakah slot terisi
- `UkuranSlot getUkuran() const` - ambil ukuran slot
- `string getKode() const` - ambil kode slot
- `void isi(Kendaraan* kendaraan)` - isi slot dengan kendaraan
- `void kosongkan()` - kosongkan slot
- `Kendaraan* getKendaraan() const` - ambil pointer kendaraan

**Konsep OOP:** ENKAPSULASI (semua atribut private, akses via method)

---

#### 2. `Tiket.h` dan `Tiket.cpp`
**Tanggung jawab:**
- Class `Tiket` dengan atribut private:
  - `std::string idTiket` (contoh: "TK-001")
  - `Kendaraan* kendaraan` (pointer)
  - `SlotParkir* slot` (pointer)
  - `std::chrono::system_clock::time_point waktuMasuk`

**Method yang perlu dibuat:**
- Constructor: `Tiket(string id, Kendaraan* kend, SlotParkir* slot, time_point waktu)`
- Getter untuk semua atribut
- `int hitungDurasi(time_point waktuKeluar) const` - hitung durasi dalam jam (dibulatkan ke atas)

**Konsep OOP:** ASOSIASI (Tiket menghubungkan Kendaraan dan SlotParkir)

---

#### 3. `Struk.h` dan `Struk.cpp`
**Tanggung jawab:**
- Struct `Struk` untuk menyimpan hasil perhitungan saat keluar:
  - `std::string idTiket`
  - `std::string jenisKendaraan`
  - `std::string platNomor`
  - `std::string kodeSlot`
  - `int durasiJam`
  - `int tarifDasar`
  - `int potonganDiskon`
  - `int totalBayar`

**Method:**
- `void cetak() const` - tampilkan struk ke console dengan format rapi

---

#### 4. `test_bagian2.cpp`
Program test untuk menguji SlotParkir, Tiket, dan Struk.

**Test yang harus dilakukan:**
- Buat beberapa slot parkir
- Isi dan kosongkan slot
- Buat tiket dan hitung durasi
- Tampilkan struk

---

### Dependencies:
- **Membutuhkan dari Bagian 1:** `Kendaraan.h`, `Motor.h`, `Mobil.h`, `Truk.h`

### Cara Kompilasi (setelah selesai):
```bash
g++ -std=c++17 -Wall -Wextra Kendaraan.cpp Motor.cpp Mobil.cpp Truk.cpp SlotParkir.cpp Tiket.cpp Struk.cpp test_bagian2.cpp -o test_bagian2
```

---

## 👤 **BAGIAN 3: Diskon & Tarif (Strategy Pattern)**
**Penanggung Jawab:** [Nama Teman 2]

### File yang Harus Dikerjakan:

#### 1. `Diskon.h` dan `Diskon.cpp`
**Tanggung jawab:**
- Class abstrak `Diskon` dengan method virtual murni:
  - `virtual int terapkanDiskon(int tarifDasar) const = 0`
  - `virtual std::string getNamaDiskon() const = 0`
  - Destruktor virtual

**Konsep OOP:** STRATEGY PATTERN - bisa ganti algoritma diskon tanpa ubah kode lain

---

#### 2. `TanpaDiskon.h` dan `TanpaDiskon.cpp`
**Tanggung jawab:**
- Class `TanpaDiskon` extends `Diskon`
- Method `terapkanDiskon()` mengembalikan tarif tanpa potongan
- Method `getNamaDiskon()` return "Tanpa Diskon"

---

#### 3. `DiskonMember.h` dan `DiskonMember.cpp`
**Tanggung jawab:**
- Class `DiskonMember` extends `Diskon`
- Method `terapkanDiskon()` mengembalikan tarif - 20%
- Method `getNamaDiskon()` return "Diskon Member (20%)"

---

#### 4. Helper Functions (bisa di file terpisah atau di Diskon.cpp)
**Fungsi utilitas:**
```cpp
// Hitung durasi dalam jam (dibulatkan ke atas)
int hitungDurasiJam(chrono::system_clock::time_point waktuMasuk,
                    chrono::system_clock::time_point waktuKeluar);

// Contoh: 3 jam 10 menit -> 4 jam
```

---

#### 5. `test_bagian3.cpp`
Program test untuk menguji sistem diskon.

**Test yang harus dilakukan:**
- Buat objek Motor, Mobil, Truk
- Hitung tarif dengan TanpaDiskon
- Hitung tarif dengan DiskonMember
- Verifikasi perhitungan sesuai aturan bisnis

**Contoh test case:**
- Mobil parkir 4 jam tanpa diskon: Rp 14.000
- Mobil parkir 4 jam dengan diskon member: Rp 11.200 (80% dari 14.000)

---

### Dependencies:
- **Membutuhkan dari Bagian 1:** `Kendaraan.h` dan turunannya

### Cara Kompilasi (setelah selesai):
```bash
g++ -std=c++17 -Wall -Wextra Kendaraan.cpp Motor.cpp Mobil.cpp Truk.cpp Diskon.cpp TanpaDiskon.cpp DiskonMember.cpp test_bagian3.cpp -o test_bagian3
```

---

## 👤 **BAGIAN 4: Gedung Parkir & Integrasi**
**Penanggung Jawab:** [Nama Teman 3]

### File yang Harus Dikerjakan:

#### 1. `GedungParkir.h` dan `GedungParkir.cpp`
**Tanggung jawab:**
- Class `GedungParkir` - class utama yang mengelola semuanya

**Atribut private:**
- `std::string namaGedung`
- `std::vector<SlotParkir> daftarSlot` - semua slot
- `std::map<std::string, std::unique_ptr<Tiket>> tiketAktif` - tiket yang masih aktif (key: ID tiket)
- `int totalPendapatan` - akumulasi pendapatan

**Method yang perlu dibuat:**

**Constructor:**
```cpp
GedungParkir(string nama, int jumlahKecil, int jumlahSedang, int jumlahBesar);
// Otomatis generate slot dengan kode A01, A02, ..., B01, B02, dst.
```

**Method utama:**
```cpp
// Kendaraan masuk
Tiket* masuk(unique_ptr<Kendaraan> kendaraan, time_point waktuMasuk);
// Return: pointer ke tiket
// Throw: ParkirPenuhError, KendaraanSudahParkirError

// Kendaraan keluar
Struk keluar(string idTiket, time_point waktuKeluar, const Diskon& diskon);
// Return: Struk dengan detail pembayaran
// Throw: TiketTidakDitemukanError

// Tampilkan status
void tampilkanStatus() const;
// Output: jumlah slot kosong per ukuran, total pendapatan

// Cek apakah plat sudah parkir
bool isPlatSudahParkir(const string& platNomor) const;
```

**Konsep OOP:** KOMPOSISI (GedungParkir "has-a" banyak SlotParkir dan Tiket)

---

#### 2. `main.cpp` - Demo Lengkap
**Tanggung jawab:**
- Buat skenario demo sesuai kriteria penerimaan di PRD
- Jalankan semua test case dari bagian 11 PRD

**Skenario yang harus dijalankan:**

```cpp
int main() {
    // 1. Buat gedung parkir
    GedungParkir gedung("Parkir Pintar", 2, 2, 2);
    
    // 2. Test motor masuk ke slot kecil
    // 3. Test semua slot kecil penuh, motor ketiga ditolak
    // 4. Test plat yang sama masuk dua kali (error)
    // 5. Test motor parkir 45 menit (1 jam)
    // 6. Test mobil parkir 3 jam 10 menit dengan diskon member
    // 7. Test truk parkir 5 jam
    // 8. Test ID tiket tidak dikenal saat keluar
    // 9. Test slot kembali kosong setelah keluar
    // 10. Tampilkan status akhir
    
    return 0;
}
```

---

#### 3. `README.md` - Dokumentasi Utama Proyek
**Tanggung jawab:**
- Penjelasan proyek secara keseluruhan
- Cara kompilasi dan menjalankan
- Penjelasan konsep OOP yang diterapkan
- Screenshot output program
- Pembagian tugas kelompok

**Template:**
```markdown
# Simulasi Parkir Pintar (C++ OOP)

## Anggota Kelompok
1. [Nama 1] - Bagian 1: Kelas Kendaraan & Exception
2. [Nama 2] - Bagian 2: Slot & Tiket
3. [Nama 3] - Bagian 3: Diskon (Strategy Pattern)
4. [Nama 4] - Bagian 4: Gedung Parkir & Integrasi

## Cara Kompilasi
...

## Cara Menjalankan
...

## Konsep OOP
...
```

---

### Dependencies:
- **Membutuhkan SEMUA bagian:** 1, 2, dan 3

### Cara Kompilasi (setelah semua selesai):
```bash
g++ -std=c++17 -Wall -Wextra *.cpp -o parkir_pintar
./parkir_pintar
```

---

## 📅 Timeline Pengerjaan (Saran)

| Hari | Kegiatan |
|------|----------|
| Hari 1-2 | Bagian 1 selesai ✅ (sudah done) |
| Hari 2-3 | Bagian 2 & 3 dikerjakan parallel |
| Hari 4 | Bagian 4 integrasi semua |
| Hari 5 | Testing bersama & dokumentasi |

---

## 🤝 Koordinasi Tim

### Komunikasi:
- Buat grup WhatsApp/Discord untuk koordinasi
- Share file via GitHub atau Google Drive
- Pastikan semua pakai C++17 standard

### Jika Ada Masalah:
- Bagian 2 stuck? Chat ke Bagian 1 (punya base class)
- Bagian 4 butuh test? Minta bantuan semua bagian

### Testing Bersama:
- Setiap bagian test sendiri dulu
- Hari ke-4 test integrasi bersama
- Siapkan skenario demo untuk presentasi

---

## ✅ Checklist Sebelum Submit

### Setiap Anggota:
- [ ] File .h dan .cpp sudah lengkap
- [ ] Kompilasi tanpa warning (`-Wall -Wextra`)
- [ ] Program test sudah jalan
- [ ] Dokumentasi README bagian masing-masing

### Tim:
- [ ] Semua file terintegrasi
- [ ] Program utama (main.cpp) jalan
- [ ] Semua kriteria penerimaan terpenuhi
- [ ] README.md lengkap
- [ ] Siap presentasi (bisa tunjuk konsep OOP di kode)

---

**Catatan:** Bagian 1 sudah 100% selesai! File-file yang sudah dibuat bisa langsung dipakai oleh bagian lain. Semangat! 💪
