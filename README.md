# Simulasi Parkir Pintar (C++ OOP)

Proyek ini mensimulasikan masuk, keluar, alokasi slot, diskon, dan pembayaran kendaraan pada gedung parkir menggunakan C++17.

## Anggota Kelompok

1. Bagian 1 - Kendaraan dan exception
2. Bagian 2 - Slot parkir, tiket, dan struk
3. Bagian 3 - Diskon dan perhitungan durasi
4. Bagian 4 - GedungParkir dan integrasi

## Struktur Utama

- `include/` dan `src/`: implementasi kelas proyek
- `main.cpp`: demo semua skenario penerimaan
- `test_bagian1.cpp`, `test_bagian2.cpp`, `test_bagian3.cpp`: pengujian per bagian
- `Makefile`: build Linux/macOS
- `compile_and_run.bat`: build Windows dengan MinGW

## Kompilasi dan Menjalankan

### Windows (MinGW/MSYS2)

```cmd
compile_and_run.bat
```

atau:

```cmd
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src\*.cpp main.cpp -o parkir_pintar.exe
parkir_pintar.exe
```

### Linux/macOS

```bash
make
make run
```

Build manual:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude \
  src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp \
  src/Exception.cpp src/SlotParkir.cpp src/Tiket.cpp src/Struk.cpp \
  src/TanpaDiskon.cpp src/DiskonMember.cpp src/HitungDurasi.cpp \
  src/GedungParkir.cpp main.cpp -o parkir_pintar
./parkir_pintar
```

## Konsep OOP

- **Abstraksi:** `Kendaraan` dan `Diskon` menggunakan method virtual murni.
- **Pewarisan:** `Motor`, `Mobil`, dan `Truk` mewarisi `Kendaraan`; `DiskonMember` dan `TanpaDiskon` mewarisi `Diskon`.
- **Polimorfisme:** Tarif dan strategi diskon dipanggil melalui pointer kelas dasar.
- **Enkapsulasi:** data internal `SlotParkir`, `Tiket`, dan `GedungParkir` diakses melalui method.
- **Asosiasi:** `Tiket` menghubungkan kendaraan dan slot parkir.
- **Komposisi:** `GedungParkir` memiliki slot dan mengelola tiket serta kendaraan aktif.
- **Strategy Pattern:** algoritma diskon dapat diganti tanpa mengubah proses keluar kendaraan.
- **Exception Handling:** sistem melaporkan parkir penuh, plat duplikat, dan tiket tidak ditemukan.

## Aturan Tarif

| Kendaraan | Jam pertama | Jam berikutnya | Slot minimum |
|---|---:|---:|---|
| Motor | Rp2.000 | Rp1.000 | Kecil |
| Mobil | Rp5.000 | Rp3.000 | Sedang |
| Truk | Rp10.000 | Rp6.000 | Besar |

Durasi dibulatkan ke atas per jam dengan minimum satu jam. Diskon member memotong 20% dari tarif dasar.

Contoh: Mobil 3 jam 10 menit = 4 jam -> Rp14.000, lalu diskon member menjadi Rp11.200. Truk 5 jam = Rp34.000.

## Skenario Integrasi

Program `main.cpp` menguji:

- Motor masuk ke slot kecil.
- Dua motor mengisi seluruh slot kecil.
- Motor ketiga ditolak dengan `ParkirPenuhError`.
- Plat duplikat ditolak dengan `KendaraanSudahParkirError`.
- Mobil keluar setelah 3 jam 10 menit dengan diskon member.
- Truk parkir selama 5 jam.
- ID tiket palsu menimbulkan `TiketTidakDitemukanError`.
- Slot dikosongkan setelah kendaraan keluar dan pendapatan bertambah.
