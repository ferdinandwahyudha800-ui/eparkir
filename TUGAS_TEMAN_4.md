# Bagian 4: Gedung Parkir & Integrasi
## Untuk: Teman 4

### 🎯 Tugas Anda
Membuat kelas utama GedungParkir dan mengintegrasikan SEMUA bagian

### 📋 File yang Harus Dibuat

#### 1. `include/GedungParkir.h` dan `src/GedungParkir.cpp`

```cpp
class GedungParkir {
private:
    std::vector<SlotParkir> slots;
    std::vector<std::unique_ptr<Tiket>> tiketAktif;
    int totalPendapatan;
    int counterTiket; // Untuk generate ID tiket

    // Helper methods
    SlotParkir* cariSlotKosong(UkuranSlot ukuranMinimum);
    bool cekPlatSudahAda(const std::string& plat) const;
    std::string generateIdTiket();

public:
    /**
     * Constructor
     * @param jumlahKecil Jumlah slot kecil
     * @param jumlahSedang Jumlah slot sedang
     * @param jumlahBesar Jumlah slot besar
     */
    GedungParkir(int jumlahKecil, int jumlahSedang, int jumlahBesar);
    
    /**
     * Kendaraan masuk, dapat tiket
     * @throws ParkirPenuhError jika tidak ada slot
     * @throws KendaraanSudahParkirError jika plat sudah ada
     */
    Tiket* masuk(std::unique_ptr<Kendaraan> kendaraan, std::time_t waktu);
    
    /**
     * Kendaraan keluar, dapat struk
     * @throws TiketTidakDitemukanError jika ID tiket tidak ada
     */
    Struk keluar(const std::string& idTiket, std::time_t waktu, const Diskon& diskon);
    
    /**
     * Tampilkan status gedung parkir
     */
    void tampilkanStatus() const;
    
    int getTotalPendapatan() const;
};
```

**Konsep OOP:** Komposisi (Gedung "memiliki" banyak Slot)

---

#### 2. `main.cpp` - Demo Lengkap

Harus menjalankan SEMUA skenario dari PRD:

```cpp
int main() {
    // Buat gedung dengan 2 slot kecil, 2 sedang, 1 besar
    GedungParkir gedung(2, 2, 1);
    
    // === SKENARIO 1: Motor masuk dapat slot kecil ===
    auto motor1 = make_unique<Motor>("B 1234 XYZ");
    Tiket* tiket1 = gedung.masuk(move(motor1), waktuSekarang());
    
    // === SKENARIO 2: Motor keluar, bayar ===
    DiskonMember diskonMember;
    Struk struk1 = gedung.keluar(tiket1->getId(), waktu1JamKemudian(), diskonMember);
    
    // === SKENARIO 3: Parkir penuh ===
    // Masukkan kendaraan hingga penuh
    // Coba masuk lagi → harus throw ParkirPenuhError
    
    // === SKENARIO 4: Plat duplikat ===
    // Coba masukkan kendaraan dengan plat yang sama
    // Harus throw KendaraanSudahParkirError
    
    // === SKENARIO 5: Tiket tidak ada ===
    // Coba keluar dengan ID tiket palsu
    // Harus throw TiketTidakDitemukanError
    
    // Tampilkan status akhir
    gedung.tampilkanStatus();
    
    return 0;
}
```

---

#### 3. `README.md` - Dokumentasi Final

Isi:
- Penjelasan proyek
- Cara compile di Linux/macOS/Windows
- Cara menjalankan
- Penjelasan konsep OOP di setiap bagian
- Contoh output
- Anggota kelompok

---

#### 4. `CMakeLists.txt` atau `Makefile` Final

Compile semua file dari Bagian 1, 2, 3, 4

---

### 🔗 Ketergantungan
Anda HARUS menunggu **Bagian 1, 2, 3 selesai SEMUA** karena:
- Butuh Kendaraan dari Bagian 1
- Butuh SlotParkir dan Tiket dari Bagian 2
- Butuh Diskon dan HitungDurasi dari Bagian 3

### ⚙️ Cara Compile Final
```bash
g++ -std=c++17 -Wall -Wextra -Iinclude \
    src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp \
    src/SlotParkir.cpp src/Tiket.cpp src/Struk.cpp \
    src/TanpaDiskon.cpp src/DiskonMember.cpp src/HitungDurasi.cpp \
    src/GedungParkir.cpp \
    main.cpp -o parkir_simulator
```

### ✅ Checklist Skenario (Sesuai PRD)

- [ ] Motor masuk dapat slot kecil → PASS
- [ ] Semua slot kecil penuh, motor ketiga ditolak → PASS
- [ ] Plat sama masuk 2x → throw KendaraanSudahParkirError
- [ ] Motor parkir 45 menit → tarif Rp2.000
- [ ] Mobil parkir 3 jam 10 menit dengan diskon member → Rp11.200
- [ ] Truk parkir 5 jam → Rp34.000
- [ ] ID tiket palsu → throw TiketTidakDitemukanError
- [ ] Setelah keluar, slot kosong & pendapatan bertambah → PASS

---

### 📝 Tips Implementasi

#### cariSlotKosong():
```cpp
SlotParkir* GedungParkir::cariSlotKosong(UkuranSlot ukuranMinimum) {
    // Cari slot terkecil yang muat dan kosong
    // Urutan: KECIL → SEDANG → BESAR
    // Return nullptr jika tidak ada
}
```

#### cekPlatSudahAda():
```cpp
bool GedungParkir::cekPlatSudahAda(const string& plat) const {
    for (const auto& tiket : tiketAktif) {
        if (tiket->getKendaraan()->getPlatNomor() == plat) {
            return true;
        }
    }
    return false;
}
```

#### masuk():
```cpp
Tiket* GedungParkir::masuk(unique_ptr<Kendaraan> kendaraan, time_t waktu) {
    // 1. Cek plat duplikat → throw jika ada
    // 2. Cari slot kosong → throw ParkirPenuhError jika tidak ada
    // 3. Isi slot dengan kendaraan
    // 4. Buat tiket baru
    // 5. Simpan ke tiketAktif
    // 6. Return pointer tiket
}
```

#### keluar():
```cpp
Struk GedungParkir::keluar(const string& idTiket, time_t waktu, const Diskon& diskon) {
    // 1. Cari tiket → throw jika tidak ada
    // 2. Hitung durasi dengan HitungDurasi
    // 3. Hitung tarif dengan kendaraan->hitungTarif()
    // 4. Terapkan diskon
    // 5. Kosongkan slot
    // 6. Hapus tiket dari tiketAktif
    // 7. Tambah pendapatan
    // 8. Return struk
}
```

---

### 🎯 Output yang Diharapkan

```
================================================
SIMULASI PARKIR PINTAR v1.0
================================================

[10:00] Motor B 1234 XYZ masuk
  → Slot: A1 (KECIL)
  → Tiket: TKT-001

[11:00] Motor B 1234 XYZ keluar (TKT-001)
  → Durasi: 1 jam
  → Tarif: Rp2000
  → Diskon: Tanpa Diskon
  → Total Bayar: Rp2000

...

================================================
STATUS GEDUNG PARKIR
================================================
Slot Kecil: 2/2 kosong
Slot Sedang: 1/2 kosong
Slot Besar: 1/1 kosong
Total Pendapatan: Rp24000
================================================
```

---

### ✅ Checklist Final
- [ ] GedungParkir.h/cpp lengkap
- [ ] main.cpp dengan SEMUA skenario PRD
- [ ] README.md final
- [ ] Build system (Makefile/CMakeLists.txt)
- [ ] Semua skenario lulus
- [ ] Kompilasi tanpa warning
- [ ] Dokumentasi konsep OOP

**Estimasi:** 3 hari  
**Deadline:** [Isi sendiri]

**Selamat mengintegrasikan! Ini bagian paling menantang!** 🚀
