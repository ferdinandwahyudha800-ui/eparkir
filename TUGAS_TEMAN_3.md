# Bagian 3: Diskon & Tarif
## Untuk: Teman 3

### 🎯 Tugas Anda
Membuat sistem diskon dengan Strategy Pattern

### 📋 File yang Harus Dibuat

#### 1. `include/Diskon.h` (Interface)
```cpp
class Diskon {
public:
    virtual ~Diskon() = default;
    
    /**
     * Terapkan diskon ke tarif asli
     * @param tarifAsli Tarif sebelum diskon
     * @return Tarif setelah diskon
     */
    virtual int terapkanDiskon(int tarifAsli) const = 0;
    
    /**
     * Nama diskon untuk ditampilkan
     */
    virtual std::string getNama() const = 0;
};
```

**Konsep OOP:** Strategy Pattern (Abstraksi)

---

#### 2. `include/TanpaDiskon.h` dan `src/TanpaDiskon.cpp`
```cpp
class TanpaDiskon : public Diskon {
public:
    int terapkanDiskon(int tarifAsli) const override {
        return tarifAsli; // Tidak ada diskon
    }
    
    std::string getNama() const override {
        return "Tanpa Diskon";
    }
};
```

---

#### 3. `include/DiskonMember.h` dan `src/DiskonMember.cpp`
```cpp
class DiskonMember : public Diskon {
private:
    static const int PERSENTASE_DISKON = 20; // 20%

public:
    int terapkanDiskon(int tarifAsli) const override {
        int potongan = tarifAsli * PERSENTASE_DISKON / 100;
        return tarifAsli - potongan;
    }
    
    std::string getNama() const override {
        return "Diskon Member 20%";
    }
};
```

---

#### 4. `include/HitungDurasi.h` dan `src/HitungDurasi.cpp`
Helper untuk menghitung durasi parkir:

```cpp
class HitungDurasi {
public:
    /**
     * Hitung durasi dalam jam, dibulatkan ke atas
     * Minimal 1 jam
     * Contoh: 30 menit = 1 jam, 3 jam 10 menit = 4 jam
     */
    static int hitungJam(std::time_t masuk, std::time_t keluar);
    
    /**
     * Format waktu menjadi string
     */
    static std::string formatWaktu(std::time_t waktu);
};
```

**Formula:**
```cpp
int detik = keluar - masuk;
int menit = detik / 60;
int jam = (menit + 59) / 60; // Pembulatan ke atas
if (jam < 1) jam = 1; // Minimal 1 jam
```

---

#### 5. `test_bagian3.cpp`
Test untuk:
- TanpaDiskon: Rp10.000 → Rp10.000
- DiskonMember: Rp10.000 → Rp8.000 (diskon 20%)
- HitungDurasi: 45 menit → 1 jam, 3 jam 10 menit → 4 jam
- Polimorfisme Diskon*

---

### 🔗 Ketergantungan
Anda HARUS menunggu **Bagian 1 selesai** karena:
- Butuh method `hitungTarif()` dari kelas Kendaraan
- Akan dipakai untuk menghitung tarif dasar

### ⚙️ Cara Compile Test Anda
```bash
g++ -std=c++17 -Wall -Wextra -Iinclude \
    src/Kendaraan.cpp src/Motor.cpp src/Mobil.cpp src/Truk.cpp \
    src/TanpaDiskon.cpp src/DiskonMember.cpp src/HitungDurasi.cpp \
    test_bagian3.cpp -o test_bagian3
```

### ✅ Checklist
- [ ] Diskon.h (interface)
- [ ] TanpaDiskon.h/cpp
- [ ] DiskonMember.h/cpp dengan diskon 20%
- [ ] HitungDurasi.h/cpp untuk hitung durasi
- [ ] test_bagian3.cpp dengan test polimorfisme
- [ ] Kompilasi tanpa warning
- [ ] README_BAGIAN3.md

### 📝 Tips
- Gunakan `#include <ctime>` dan `#include <cmath>` untuk pembulatan
- Pointer Diskon* bisa menunjuk TanpaDiskon atau DiskonMember
- Formula diskon: `tarifAsli * (100 - persentase) / 100`
- Minimal durasi adalah 1 jam (sesuai PRD)

### 🎯 Contoh Skenario Test

```cpp
// Test DiskonMember
Motor motor("B 1234 XYZ");
int tarifAsli = motor.hitungTarif(4); // Rp4000
DiskonMember diskon;
int tarifSetelah = diskon.terapkanDiskon(tarifAsli); // Rp3200

// Test HitungDurasi
time_t masuk = ...; // 10:00
time_t keluar = ...; // 13:10 (3 jam 10 menit)
int durasi = HitungDurasi::hitungJam(masuk, keluar); // 4 jam
```

**Estimasi:** 2 hari  
**Deadline:** [Isi sendiri]
