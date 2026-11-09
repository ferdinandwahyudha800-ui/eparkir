# Bagian 1: Kelas Dasar & Kendaraan

**Pengembang:** [Nama Anda]  
**Bagian:** Kelas Dasar & Kendaraan (Hierarki Kendaraan dan Exception)

## 📋 Deskripsi

Bagian ini mengimplementasikan fondasi sistem parkir pintar, yaitu:
- Hierarki kelas `Kendaraan` (abstrak) dengan turunan `Motor`, `Mobil`, dan `Truk`
- Custom exception untuk penanganan kesalahan
- Perhitungan tarif parkir sesuai aturan bisnis

## 🎯 Konsep OOP yang Diterapkan

### 1. **Abstraksi**
- Kelas `Kendaraan` adalah kelas abstrak dengan method virtual murni
- Menyediakan interface umum tanpa implementasi konkret

### 2. **Pewarisan (Inheritance)**
- `Motor`, `Mobil`, dan `Truk` mewarisi dari `Kendaraan`
- Mewarisi atribut `platNomor` dan `pemilik`

### 3. **Polimorfisme**
- Method `hitungTarif()`, `ukuranSlotMinimum()`, dan `jenisKendaraan()` di-override
- Dapat menggunakan pointer `Kendaraan*` untuk menunjuk objek turunan mana saja
- Perilaku bergantung pada tipe objek sebenarnya (dynamic binding)

### 4. **Enkapsulasi**
- Atribut `platNomor` dan `pemilik` bersifat `protected`
- Tarif disimpan sebagai konstanta `private` di setiap kelas
- Akses melalui method getter dan method publik

### 5. **Exception Handling**
- Custom exception: `ParkirPenuhError`, `TiketTidakDitemukanError`, `KendaraanSudahParkirError`
- Mewarisi dari `std::exception`

## 📁 Struktur File

```
Kendaraan.h           # Kelas abstrak Kendaraan
Kendaraan.cpp         # Implementasi Kendaraan
Motor.h/cpp           # Kelas Motor (turunan)
Mobil.h/cpp           # Kelas Mobil (turunan)
Truk.h/cpp            # Kelas Truk (turunan)
Exception.h/cpp       # Custom exceptions
test_bagian1.cpp      # Program test
Makefile              # Build script
README_BAGIAN1.md     # Dokumentasi ini
```

## 🔨 Cara Kompilasi dan Menjalankan

### Windows (cmd):
```cmd
g++ -std=c++17 -Wall -Wextra Kendaraan.cpp Motor.cpp Mobil.cpp Truk.cpp Exception.cpp test_bagian1.cpp -o test_bagian1
test_bagian1.exe
```

### Linux/macOS (atau Windows dengan Make):
```bash
make
./test_bagian1
```

### Membersihkan file hasil kompilasi:
```bash
make clean
```

## 📊 Aturan Tarif

| Kendaraan | Jam Pertama | Jam Berikutnya | Slot Minimum |
|-----------|-------------|----------------|--------------|
| Motor     | Rp 2.000    | Rp 1.000/jam   | KECIL        |
| Mobil     | Rp 5.000    | Rp 3.000/jam   | SEDANG       |
| Truk      | Rp 10.000   | Rp 6.000/jam   | BESAR        |

**Contoh perhitungan:**
- Motor parkir 3 jam: Rp 2.000 + (2 × Rp 1.000) = **Rp 4.000**
- Mobil parkir 4 jam: Rp 5.000 + (3 × Rp 3.000) = **Rp 14.000**
- Truk parkir 5 jam: Rp 10.000 + (4 × Rp 6.000) = **Rp 34.000**

## ✅ Test yang Dilakukan

Program `test_bagian1.cpp` menguji:
1. ✅ Polimorfisme dengan pointer kelas dasar
2. ✅ Perhitungan tarif untuk Motor, Mobil, Truk
3. ✅ Ukuran slot minimum
4. ✅ Exception handling
5. ✅ Array polimorfik dengan `vector<unique_ptr<Kendaraan>>`

## 🔗 Integrasi dengan Bagian Lain

Bagian ini akan digunakan oleh:
- **Bagian 2 (Slot & Tiket)**: Tiket akan menyimpan pointer ke objek `Kendaraan`
- **Bagian 3 (Diskon)**: Method `hitungTarif()` akan digunakan untuk perhitungan sebelum diskon
- **Bagian 4 (Gedung Parkir)**: `GedungParkir` akan menyimpan dan mengelola koleksi `Kendaraan`

## 🎓 Penjelasan untuk Presentasi

**Untuk menunjukkan OOP dalam kode ini:**

1. **Tunjukkan Abstraksi:**
   - Buka `Kendaraan.h`, tunjukkan method virtual murni (`= 0`)
   - Jelaskan bahwa kita tidak bisa membuat objek `Kendaraan` langsung

2. **Tunjukkan Pewarisan:**
   - Buka `Motor.h`, tunjukkan `: public Kendaraan`
   - Jelaskan bahwa Motor mewarisi semua member dari Kendaraan

3. **Tunjukkan Polimorfisme:**
   - Buka `test_bagian1.cpp`, tunjukkan baris:
     ```cpp
     unique_ptr<Kendaraan> motor = make_unique<Motor>(...);
     ```
   - Jelaskan pointer kelas dasar menunjuk objek turunan
   - Tunjukkan method yang dipanggil sesuai tipe objek sebenarnya

4. **Tunjukkan Enkapsulasi:**
   - Tunjukkan `protected` members dan `private` constants
   - Jelaskan akses hanya melalui method publik

## 📝 Catatan Pengembangan

- Tidak menggunakan `new`/`delete` manual, semua pakai smart pointer
- Destruktor virtual untuk menghindari memory leak
- Konstanta tarif disimpan sebagai `static const` di setiap kelas
- Exception menyimpan pesan dalam atribut `string` untuk fleksibilitas

## 🚀 Pengembangan Selanjutnya

Jika proyek dikembangkan lebih lanjut, bisa ditambahkan:
- Kelas `MobilListrik` dengan tarif berbeda
- Method untuk menyimpan/membaca dari file
- Validasi plat nomor dengan regex
- Tarif progresif berdasarkan durasi

---

**Status:** ✅ Selesai dan siap diintegrasikan  
**Tanggal:** 9 November 2026
