# Bagian 2: Slot Parkir & Tiket

## Deskripsi
Bagian ini mengimplementasikan sistem slot parkir dan tiket untuk sistem e-Parkir.

## File yang Dibuat

| File | Keterangan |
|------|-----------|
| `include/SlotParkir.h` | Header kelas SlotParkir |
| `src/SlotParkir.cpp` | Implementasi SlotParkir |
| `include/Tiket.h` | Header kelas Tiket |
| `src/Tiket.cpp` | Implementasi Tiket |
| `include/Struk.h` | Header struct Struk |
| `src/Struk.cpp` | Implementasi Struk::cetak() |
| `test_bagian2.cpp` | Program uji coba lengkap |

---

## Konsep OOP yang Digunakan

### 1. Enkapsulasi – `SlotParkir`
Data `kosong`, `kendaraanTerparkir`, dan `ukuran` bersifat **private**. Perubahan status slot hanya bisa dilakukan lewat method `isi()` dan `kosongkan()`. Method `isi()` juga melakukan validasi: slot yang sudah terisi akan melempar `std::runtime_error`.

### 2. Asosiasi – `Tiket`
`Tiket` **tidak memiliki** (own) objek `Kendaraan` maupun `SlotParkir`. Ia hanya menyimpan pointer ke keduanya — ini adalah relasi **asosiasi**, bukan komposisi. Lifetime kendaraan dan slot dikelola di luar Tiket.

### 3. Struct dengan Method – `Struk`
`Struk` menggunakan `struct` karena semua fieldnya publik dan hanya bertugas merangkum data transaksi. Method `cetak()` memformat dan menampilkan struk ke console menggunakan `std::iomanip`.

---

## Cara Compile

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude \
    src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp \
    src/SlotParkir.cpp src/Tiket.cpp src/Struk.cpp \
    test_bagian2.cpp -o test_bagian2
```

Jalankan:
```bash
./test_bagian2        # Linux/macOS
test_bagian2.exe      # Windows
```

---

## Contoh Output

```
=== TEST 1: SlotParkir ===
Slot A1 (KECIL) kosong: YA
...
[OK] Exception saat isi slot penuh: Slot B1 sudah terisi.

=== TEST 2: Tiket ===
ID Tiket   : TKT-001
...

========================================
          STRUK PARKIR E-PARKIR         
========================================
ID Tiket          : TKT-002
Plat Nomor        : H 7777 TT
...
========================================
```

---

## Ketergantungan
Bagian ini bergantung pada **Bagian 1** (`Kendaraan`, `Motor`, `Mobil`, `Truk`, `UkuranSlot`) yang harus sudah tersedia di `include/` dan `src/`.
