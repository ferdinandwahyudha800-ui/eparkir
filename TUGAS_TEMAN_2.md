# Bagian 2: Slot & Tiket
## Untuk: Teman 2

### 🎯 Tugas Anda
Membuat sistem slot parkir dan tiket

### 📋 File yang Harus Dibuat

#### 1. `include/SlotParkir.h` dan `src/SlotParkir.cpp`
```cpp
class SlotParkir {
private:
    UkuranSlot ukuran;
    bool kosong;
    Kendaraan* kendaraanTerparkir; // atau nullptr jika kosong
    std::string kode; // Misal: "A1", "B2", dll

public:
    SlotParkir(UkuranSlot ukuran, const std::string& kode);
    
    bool isKosong() const;
    void isi(Kendaraan* kendaraan);
    void kosongkan();
    UkuranSlot getUkuran() const;
    std::string getKode() const;
    Kendaraan* getKendaraan() const;
};
```

**Konsep OOP:** Enkapsulasi (status slot adalah private)

---

#### 2. `include/Tiket.h` dan `src/Tiket.cpp`
```cpp
class Tiket {
private:
    std::string id;              // Format: TKT-001, TKT-002
    Kendaraan* kendaraan;
    SlotParkir* slot;
    std::time_t waktuMasuk;

public:
    Tiket(const std::string& id, Kendaraan* kendaraan, 
          SlotParkir* slot, std::time_t waktu);
    
    std::string getId() const;
    Kendaraan* getKendaraan() const;
    SlotParkir* getSlot() const;
    std::time_t getWaktuMasuk() const;
};
```

**Konsep OOP:** Asosiasi (Tiket menghubungkan Kendaraan dan Slot)

---

#### 3. `include/Struk.h` dan `src/Struk.cpp`
```cpp
struct Struk {
    std::string idTiket;
    std::string platNomor;
    std::string jenisKendaraan;
    std::string kodeSlot;
    std::time_t waktuMasuk;
    std::time_t waktuKeluar;
    int durasiJam;
    int tarifDasar;
    int diskon;
    int totalBayar;
    
    void cetak() const; // Tampilkan struk ke console
};
```

---

#### 4. `test_bagian2.cpp`
Program test untuk:
- Membuat slot parkir berbagai ukuran
- Isi dan kosongkan slot
- Buat tiket dengan data kendaraan
- Tampilkan struk

---

### 🔗 Ketergantungan
Anda HARUS menunggu **Bagian 1 selesai** karena:
- Butuh `Kendaraan*` dari Bagian 1
- Butuh `UkuranSlot` enum dari Bagian 1

### ⚙️ Cara Compile Test Anda
```bash
g++ -std=c++17 -Wall -Wextra -Iinclude \
    src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp \
    src/SlotParkir.cpp src/Tiket.cpp src/Struk.cpp \
    test_bagian2.cpp -o test_bagian2
```

### ✅ Checklist
- [ ] SlotParkir.h/cpp dengan enkapsulasi
- [ ] Tiket.h/cpp dengan asosiasi
- [ ] Struk.h/cpp dengan method cetak()
- [ ] test_bagian2.cpp yang lengkap
- [ ] Kompilasi tanpa warning
- [ ] README_BAGIAN2.md

### 📝 Tips
- Gunakan `#include <ctime>` untuk `std::time_t`
- Pointer boleh nullptr, cek dulu sebelum akses
- Status slot harus private, akses lewat getter/setter

**Estimasi:** 2 hari  
**Deadline:** [Isi sendiri]
