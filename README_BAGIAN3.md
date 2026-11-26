# Bagian 3: Diskon & Tarif

**Pengembang:** Teman 3  
**Bagian:** Diskon & Tarif (Strategy Pattern untuk Diskon dan Perhitungan Durasi)

## 📋 Deskripsi

Bagian ini mengimplementasikan sistem diskon parkir dengan Strategy Pattern, yaitu:
- Interface `Diskon` sebagai abstraksi strategi diskon
- `TanpaDiskon` untuk pelanggan non-member
- `DiskonMember` untuk pelanggan member dengan potongan 20%
- `HitungDurasi` sebagai helper perhitungan durasi parkir

## 🎯 Konsep OOP yang Diterapkan

### 1. **Strategy Pattern (Abstraksi)**
- Kelas `Diskon` adalah interface dengan method virtual murni
- Memisahkan algoritma diskon dari penggunanya
- Strategi dapat diganti saat runtime tanpa mengubah kode pemanggil

### 2. **Polimorfisme**
- Method `terapkanDiskon()` dan `getNama()` di-override di setiap implementasi
- Pointer `Diskon*` dapat menunjuk `TanpaDiskon` atau `DiskonMember`
- Perilaku bergantung pada tipe objek sebenarnya (dynamic binding)

### 3. **Enkapsulasi**
- Konstanta `PERSENTASE_DISKON` bersifat `private` di `DiskonMember`
- Akses hanya melalui method publik `terapkanDiskon()` dan `getNama()`

## 📁 Struktur File

```
include/Diskon.h        # Interface Diskon (abstrak)
include/TanpaDiskon.h   # Header TanpaDiskon
src/TanpaDiskon.cpp     # Implementasi TanpaDiskon
include/DiskonMember.h  # Header DiskonMember
src/DiskonMember.cpp    # Implementasi DiskonMember
include/HitungDurasi.h  # Header HitungDurasi (helper)
src/HitungDurasi.cpp    # Implementasi HitungDurasi
test_bagian3.cpp        # Program test
README_BAGIAN3.md       # Dokumentasi ini
```

## 🔨 Cara Kompilasi dan Menjalankan

### Windows (cmd):
```cmd
g++ -std=c++17 -Wall -Wextra -Iinclude src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp src/TanpaDiskon.cpp src/DiskonMember.cpp src/HitungDurasi.cpp test_bagian3.cpp -o test_bagian3
test_bagian3.exe
```

### Linux/macOS:
```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp src/TanpaDiskon.cpp src/DiskonMember.cpp src/HitungDurasi.cpp test_bagian3.cpp -o test_bagian3
./test_bagian3
```

## 📊 Aturan Diskon

| Strategi | Persentase | Contoh (Rp 10.000) |
|----------|-----------|---------------------|
| TanpaDiskon  | 0%  | Rp 10.000 |
| DiskonMember | 20% | Rp 8.000  |

**Formula diskon:** `tarifAsli * (100 - persentase) / 100`

## 📊 Aturan Durasi

| Skenario | Durasi Aktual | Hasil (jam) |
|----------|--------------|-------------|
| 45 menit | 45 menit     | 1 jam       |
| 3 jam 10 menit | 190 menit | 4 jam       |
| 0 menit (sama) | 0 menit   | 1 jam (minimal) |

**Formula:** `(menit + 59) / 60`, minimal 1 jam

## ✅ Test yang Dilakukan

Program `test_bagian3.cpp` menguji:
1. ✅ TanpaDiskon: Rp10.000 → Rp10.000
2. ✅ DiskonMember: Rp10.000 → Rp8.000 (diskon 20%)
3. ✅ HitungDurasi: 45 menit → 1 jam, 3 jam 10 menit → 4 jam, 0 menit → 1 jam
4. ✅ Polimorfisme dengan pointer `Diskon*`
5. ✅ Skenario lengkap: Motor 3 jam (Rp4.000) + DiskonMember → Rp3.200
6. ✅ Array polimorfik dengan `vector<unique_ptr<Diskon>>`

## 🔗 Integrasi dengan Bagian Lain

Bagian ini bergantung pada:
- **Bagian 1 (Kendaraan)**: Method `hitungTarif()` dari kelas `Motor`, `Mobil`, `Truk`

Bagian ini akan digunakan oleh:
- **Bagian 2 (Slot & Tiket)**: Tiket dapat menyimpan strategi diskon yang dipilih
- **Bagian 4 (Gedung Parkir)**: `GedungParkir` akan menggunakan `HitungDurasi` dan strategi `Diskon` saat menghitung total bayar

## 🎓 Penjelasan untuk Presentasi

**Untuk menunjukkan OOP dalam kode ini:**

1. **Tunjukkan Strategy Pattern:**
   - Buka `Diskon.h`, tunjukkan interface dengan method virtual murni (`= 0`)
   - Jelaskan bahwa strategi diskon dapat diganti tanpa mengubah kode pemanggil

2. **Tunjukkan Polimorfisme:**
   - Buka `test_bagian3.cpp`, tunjukkan baris:
     ```cpp
     unique_ptr<Diskon> diskon1 = make_unique<TanpaDiskon>();
     unique_ptr<Diskon> diskon2 = make_unique<DiskonMember>();
     ```
   - Jelaskan pointer kelas dasar menunjuk objek turunan
   - Method `terapkanDiskon()` dipanggil sesuai tipe objek sebenarnya

3. **Tunjukkan Enkapsulasi:**
   - Tunjukkan konstanta `private` `PERSENTASE_DISKON` di `DiskonMember`
   - Akses hanya melalui method publik

## 📝 Catatan Pengembangan

- Tidak menggunakan `new`/`delete` manual, semua pakai smart pointer
- Destruktor virtual di interface `Diskon` untuk menghindari memory leak
- Konstanta diskon disimpan sebagai `static const` di `DiskonMember`
- `HitungDurasi` menggunakan method static (tidak perlu instansiasi)
- Pembulatan durasi menggunakan integer arithmetic `(menit + 59) / 60`

## 🚀 Pengembangan Selanjutnya

Jika proyek dikembangkan lebih lanjut, bisa ditambahkan:
- `DiskonPromo` untuk diskon hari tertentu (mis. weekend 10%)
- `DiskonLoyalty` berdasarkan jumlah kunjungan
- Durasi gratis untuk parkir di bawah 15 menit (grace period)
- Diskon berjenjang berdasarkan total tarif

---

**Status:** ✅ Selesai dan siap diintegrasikan  
**Tanggal:** 18 November 2026
