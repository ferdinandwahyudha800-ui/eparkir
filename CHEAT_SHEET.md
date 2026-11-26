# 📝 CHEAT SHEET: 3 Konsep Baru

## Quick Reference untuk Presentasi & Demo

---

## 1️⃣ SETTER

### Kode:
```cpp
motor->setPlatNomor("B 9999 NEW");
motor->setJenisKendaraan("Motor Besar");
```

### Penjelasan 1 Kalimat:
"Method untuk **mengubah nilai atribut** setelah objek dibuat."

### Lokasi di Kode:
- **Header:** `include/Kendaraan.h` line 70-80
- **Implementation:** `src/Kendaraan.cpp` line 30-42

### Demo Script:
```
1. Buat objek Motor dengan plat B 1234 XYZ
2. Tampilkan plat awal
3. Ubah plat dengan setPlatNomor("B 9999 NEW")
4. Tampilkan plat baru → BERHASIL BERUBAH! ✅
```

---

## 2️⃣ DICTIONARY (std::map)

### Kode:
```cpp
mobil->setProperti("warna", "Merah");
mobil->setProperti("tahun", "2023");
cout << mobil->getProperti("warna"); // Output: Merah
```

### Penjelasan 1 Kalimat:
"Struktur data **key-value pair** untuk menyimpan metadata kendaraan secara dinamis."

### Lokasi di Kode:
- **Variable:** `include/Kendaraan.h` line 20-22
- **Methods:** `include/Kendaraan.h` line 85-115
- **Implementation:** `src/Kendaraan.cpp` line 45-80

### 5 Method Penting:
| Method | Fungsi |
|--------|--------|
| `setProperti(key, value)` | Tambah/update properti |
| `getProperti(key)` | Ambil nilai properti |
| `hasProperti(key)` | Cek apakah ada |
| `getAllProperti()` | Ambil semua properti |
| `hapusProperti(key)` | Hapus properti |

### Demo Script:
```
1. Buat objek Mobil
2. Tambah properti: warna, tahun, pemilik, merk
3. Tampilkan semua properti → TERSIMPAN! ✅
4. Cek apakah punya properti "warna" → ADA! ✅
5. Hapus properti "catatan" → TERHAPUS! ✅
```

---

## 3️⃣ GENERIC/TEMPLATE

### Kode:
```cpp
// Hitung total tarif SEMUA jenis kendaraan
int total = hitungTotalTarif(parkiran, 3);

// Filter dengan lambda
auto motorSaja = filterKendaraan(parkiran,
    [](auto* k) { return k->getJenisKendaraan() == "Motor"; });
```

### Penjelasan 1 Kalimat:
"Fungsi **template** yang dapat bekerja dengan berbagai tipe container (vector, list, array)."

### Lokasi di Kode:
- **Template Functions:** `include/Kendaraan.h` line 125-170

### 3 Template Function:

#### A. hitungTotalTarif<Container>()
```cpp
template<typename Container>
int hitungTotalTarif(const Container& container, int durasiJam)
```
**Fungsi:** Hitung total tarif semua kendaraan

#### B. filterKendaraan<T, Predicate>()
```cpp
template<typename T, typename Predicate>
std::vector<T> filterKendaraan(const std::vector<T>& container, Predicate predicate)
```
**Fungsi:** Filter kendaraan berdasarkan kriteria (pakai lambda)

#### C. hitungRataRataTarif<Container>()
```cpp
template<typename Container>
double hitungRataRataTarif(const Container& container, int durasiJam)
```
**Fungsi:** Hitung rata-rata tarif

### Demo Script:
```
1. Buat 5 kendaraan (Motor, Mobil, Truk campur)
2. Hitung total tarif pakai hitungTotalTarif() → BERHASIL! ✅
3. Hitung rata-rata pakai hitungRataRataTarif() → BERHASIL! ✅
4. Filter hanya Motor pakai filterKendaraan() → BERHASIL! ✅
5. Tunjukkan: "Satu fungsi untuk SEMUA tipe!" 
```

---

## 🎤 SCRIPT PRESENTASI (60 detik)

### Opening (5 detik):
"Saya menambahkan 3 konsep: Setter, Dictionary, dan Generic."

### 1. Setter (15 detik):
"Pertama, SETTER. Ini method untuk mengubah data setelah objek dibuat. Contoh: Motor plat B 1234 XYZ saya ubah jadi B 9999 NEW pakai setPlatNomor(). Kode ada di Kendaraan.h line 70."

### 2. Dictionary (20 detik):
"Kedua, DICTIONARY pakai std::map. Ini key-value pair untuk menyimpan metadata kendaraan. Mobil ini saya beri properti: warna Merah, tahun 2023, pemilik Budi. Ada 5 method: set, get, has, getAll, hapus. Fleksibel, bisa tambah properti apapun tanpa ubah structure class."

### 3. Generic (15 detik):
"Ketiga, GENERIC TEMPLATE. Fungsi hitungTotalTarif bisa dipakai untuk vector, list, atau array. Satu fungsi untuk SEMUA tipe container. Ini keuntungan template: type-safe, reusable, dan flexible."

### Closing (5 detik):
"Test berhasil semua. Kode lengkap: variable, getter, setter, dictionary, generic, plus 4 pilar OOP."

---

## 🎯 PERTANYAAN UMUM + JAWABAN

### Q: "Apa bedanya Getter dan Setter?"
**A:** "Getter mengambil nilai, Setter mengubah nilai. getPlatNomor() ambil data, setPlatNomor() ubah data."

### Q: "Kenapa pakai std::map?"
**A:** "std::map adalah implementasi dictionary di C++, struktur key-value pair seperti HashMap di Java."

### Q: "Apa keuntungan Generic?"
**A:** "Reusable, satu fungsi untuk banyak tipe. Tidak perlu buat fungsi terpisah untuk vector, list, array."

### Q: "Dictionary untuk apa?"
**A:** "Menyimpan metadata tambahan yang bervariasi per kendaraan, seperti warna, tahun, pemilik, tanpa harus tambah atribut baru di class."

### Q: "Setter melanggar enkapsulasi?"
**A:** "Tidak, karena akses tetap lewat method publik, bisa tambah validasi jika perlu."

---

## 📸 SCREENSHOT CHECKLIST

Ambil screenshot untuk laporan:

- [ ] Code `include/Kendaraan.h` (tunjukkan dictionary & template)
- [ ] Code `src/Kendaraan.cpp` (tunjukkan setter implementation)
- [ ] Output test setter (plat berubah)
- [ ] Output test dictionary (properti tersimpan)
- [ ] Output test generic (total tarif, filter)
- [ ] Ringkasan akhir (semua konsep ✅)

---

## 📊 TABEL RINGKAS

| Konsep | Method Utama | Use Case |
|--------|-------------|----------|
| **Getter** | `getPlatNomor()` | Ambil data |
| **Setter** | `setPlatNomor()` | Ubah data |
| **Dictionary** | `setProperti()`, `getProperti()` | Metadata dinamis |
| **Generic** | `hitungTotalTarif<>()` | Fungsi fleksibel |

---

## ⏱️ TIMING DEMO (Total: 3 menit)

| Waktu | Aktivitas |
|-------|-----------|
| 0:00-0:30 | Intro & overview 3 konsep |
| 0:30-1:00 | Demo SETTER (plat berubah) |
| 1:00-2:00 | Demo DICTIONARY (properti) |
| 2:00-2:45 | Demo GENERIC (total & filter) |
| 2:45-3:00 | Closing & Q&A |

---

## ✅ CHECKLIST SEBELUM PRESENTASI

- [ ] Test kode di compiler (online/offline)
- [ ] Screenshot semua output
- [ ] Baca FITUR_ADVANCED.md sekali
- [ ] Hafal 3 penjelasan 1 kalimat di atas
- [ ] Siapkan contoh use case dunia nyata
- [ ] Print atau buka cheat sheet ini

---

## 🚀 CONFIDENCE BOOSTER

**Anda sudah punya:**
- ✅ Kode lengkap & berfungsi
- ✅ Test yang comprehensive
- ✅ Dokumentasi detail
- ✅ Semua konsep OOP + 3 tambahan

**Anda SIAP!** 💪

---

**Good luck! 🎉**
