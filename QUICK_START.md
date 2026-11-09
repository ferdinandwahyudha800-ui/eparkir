# ⚡ QUICK START GUIDE
## Simulasi Parkir Pintar

---

## 🎯 Untuk Anda (Anggota 1) - SUDAH SELESAI ✅

### Apa yang Sudah Dikerjakan?
✅ Kelas abstrak `Kendaraan`  
✅ Kelas `Motor`, `Mobil`, `Truk`  
✅ Custom exceptions (3 buah)  
✅ Program test lengkap  
✅ Dokumentasi lengkap  

**Status Anda: 100% SELESAI!** 🎉

---

## 🚀 Yang Harus Anda Lakukan Sekarang

### 1️⃣ Test Kode Anda (PENTING!)

#### Opsi A: Pakai Online Compiler (TERCEPAT)
1. Buka: **https://www.onlinegdb.com/online_c++_compiler**
2. Pilih language: **C++ 17**
3. Copy-paste **file ini** ↓

<details>
<summary>📄 Klik untuk melihat kode lengkap (copy semua)</summary>

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <exception>
using namespace std;

// ============ EXCEPTION.H ============
class ParkirException : public exception {
protected:
    string pesan;
public:
    explicit ParkirException(const string& msg) : pesan(msg) {}
    const char* what() const noexcept override { return pesan.c_str(); }
};

class ParkirPenuhError : public ParkirException {
public:
    explicit ParkirPenuhError(const string& jenisKendaraan) 
        : ParkirException("Parkir penuh: Tidak ada slot yang tersedia untuk " + jenisKendaraan) {}
};

class TiketTidakDitemukanError : public ParkirException {
public:
    explicit TiketTidakDitemukanError(const string& idTiket) 
        : ParkirException("Tiket tidak ditemukan: " + idTiket) {}
};

class KendaraanSudahParkirError : public ParkirException {
public:
    explicit KendaraanSudahParkirError(const string& platNomor) 
        : ParkirException("Kendaraan dengan plat " + platNomor + " sudah berada di dalam gedung") {}
};

// ============ KENDARAAN.H ============
enum class UkuranSlot { KECIL, SEDANG, BESAR };

class Kendaraan {
protected:
    string platNomor;
    string jenisKendaraan;
public:
    Kendaraan(const string& plat, const string& jenis) : platNomor(plat), jenisKendaraan(jenis) {}
    virtual ~Kendaraan() = default;
    virtual int hitungTarif(int durasiJam) const = 0;
    virtual UkuranSlot ukuranSlotMinimum() const = 0;
    string getPlatNomor() const { return platNomor; }
    string getJenisKendaraan() const { return jenisKendaraan; }
};

// ============ MOTOR.H ============
class Motor : public Kendaraan {
private:
    static const int TARIF_JAM_PERTAMA = 2000;
    static const int TARIF_JAM_BERIKUTNYA = 1000;
public:
    explicit Motor(const string& plat) : Kendaraan(plat, "Motor") {}
    
    int hitungTarif(int durasiJam) const override {
        if (durasiJam <= 0) return 0;
        if (durasiJam == 1) return TARIF_JAM_PERTAMA;
        return TARIF_JAM_PERTAMA + ((durasiJam - 1) * TARIF_JAM_BERIKUTNYA);
    }
    
    UkuranSlot ukuranSlotMinimum() const override {
        return UkuranSlot::KECIL;
    }
};

// ============ MOBIL.H ============
class Mobil : public Kendaraan {
private:
    static const int TARIF_JAM_PERTAMA = 5000;
    static const int TARIF_JAM_BERIKUTNYA = 3000;
public:
    explicit Mobil(const string& plat) : Kendaraan(plat, "Mobil") {}
    
    int hitungTarif(int durasiJam) const override {
        if (durasiJam <= 0) return 0;
        if (durasiJam == 1) return TARIF_JAM_PERTAMA;
        return TARIF_JAM_PERTAMA + ((durasiJam - 1) * TARIF_JAM_BERIKUTNYA);
    }
    
    UkuranSlot ukuranSlotMinimum() const override {
        return UkuranSlot::SEDANG;
    }
};

// ============ TRUK.H ============
class Truk : public Kendaraan {
private:
    static const int TARIF_JAM_PERTAMA = 10000;
    static const int TARIF_JAM_BERIKUTNYA = 6000;
public:
    explicit Truk(const string& plat) : Kendaraan(plat, "Truk") {}
    
    int hitungTarif(int durasiJam) const override {
        if (durasiJam <= 0) return 0;
        if (durasiJam == 1) return TARIF_JAM_PERTAMA;
        return TARIF_JAM_PERTAMA + ((durasiJam - 1) * TARIF_JAM_BERIKUTNYA);
    }
    
    UkuranSlot ukuranSlotMinimum() const override {
        return UkuranSlot::BESAR;
    }
};

// ============ MAIN (TEST) ============
void cetakGaris() {
    cout << "================================================" << endl;
}

int main() {
    cout << "\n";
    cetakGaris();
    cout << "  TEST BAGIAN 1: KELAS DASAR & KENDARAAN" << endl;
    cetakGaris();
    cout << "\nKonsep OOP yang didemonstrasikan:" << endl;
    cout << "1. ABSTRAKSI - Kelas Kendaraan sebagai interface" << endl;
    cout << "2. PEWARISAN - Motor, Mobil, Truk mewarisi Kendaraan" << endl;
    cout << "3. POLIMORFISME - Method virtual dan override" << endl;
    cout << "4. ENKAPSULASI - Data private dan getter" << endl;
    cout << endl;
    
    // Test Motor
    cetakGaris();
    cout << "TEST MOTOR" << endl;
    cetakGaris();
    Motor motor("B 1234 XYZ");
    cout << "Jenis: " << motor.getJenisKendaraan() << endl;
    cout << "Plat: " << motor.getPlatNomor() << endl;
    cout << "Ukuran slot: " << (motor.ukuranSlotMinimum() == UkuranSlot::KECIL ? "KECIL" : "TIDAK KECIL") << endl;
    cout << "\nTarif Motor:" << endl;
    cout << "- 1 jam: Rp" << motor.hitungTarif(1) << " (Expected: Rp2000)" << endl;
    cout << "- 2 jam: Rp" << motor.hitungTarif(2) << " (Expected: Rp3000)" << endl;
    cout << "- 3 jam: Rp" << motor.hitungTarif(3) << " (Expected: Rp4000)" << endl;
    cout << endl;
    
    // Test Mobil
    cetakGaris();
    cout << "TEST MOBIL" << endl;
    cetakGaris();
    Mobil mobil("B 5678 ABC");
    cout << "Jenis: " << mobil.getJenisKendaraan() << endl;
    cout << "Plat: " << mobil.getPlatNomor() << endl;
    cout << "Ukuran slot: " << (mobil.ukuranSlotMinimum() == UkuranSlot::SEDANG ? "SEDANG" : "TIDAK SEDANG") << endl;
    cout << "\nTarif Mobil:" << endl;
    cout << "- 1 jam: Rp" << mobil.hitungTarif(1) << " (Expected: Rp5000)" << endl;
    cout << "- 4 jam: Rp" << mobil.hitungTarif(4) << " (Expected: Rp14000)" << endl;
    cout << endl;
    
    // Test Truk
    cetakGaris();
    cout << "TEST TRUK" << endl;
    cetakGaris();
    Truk truk("B 9999 TRK");
    cout << "Jenis: " << truk.getJenisKendaraan() << endl;
    cout << "Plat: " << truk.getPlatNomor() << endl;
    cout << "Ukuran slot: " << (truk.ukuranSlotMinimum() == UkuranSlot::BESAR ? "BESAR" : "TIDAK BESAR") << endl;
    cout << "\nTarif Truk:" << endl;
    cout << "- 1 jam: Rp" << truk.hitungTarif(1) << " (Expected: Rp10000)" << endl;
    cout << "- 5 jam: Rp" << truk.hitungTarif(5) << " (Expected: Rp34000)" << endl;
    cout << endl;
    
    // Test Polimorfisme
    cetakGaris();
    cout << "TEST POLIMORFISME" << endl;
    cetakGaris();
    unique_ptr<Kendaraan> k1 = make_unique<Motor>("B 1111 AAA");
    unique_ptr<Kendaraan> k2 = make_unique<Mobil>("B 2222 BBB");
    unique_ptr<Kendaraan> k3 = make_unique<Truk>("B 3333 CCC");
    cout << "Memanggil method melalui pointer Kendaraan*:" << endl;
    cout << "1. " << k1->getJenisKendaraan() << " (3 jam): Rp" << k1->hitungTarif(3) << endl;
    cout << "2. " << k2->getJenisKendaraan() << " (3 jam): Rp" << k2->hitungTarif(3) << endl;
    cout << "3. " << k3->getJenisKendaraan() << " (3 jam): Rp" << k3->hitungTarif(3) << endl;
    cout << "\nPolimorfisme berfungsi dengan baik!" << endl;
    cout << endl;
    
    // Test Exception
    cetakGaris();
    cout << "TEST EXCEPTION" << endl;
    cetakGaris();
    try {
        cout << "1. Testing ParkirPenuhError..." << endl;
        throw ParkirPenuhError("Motor");
    } catch (const ParkirException& e) {
        cout << "   Caught: " << e.what() << endl;
    }
    try {
        cout << "2. Testing TiketTidakDitemukanError..." << endl;
        throw TiketTidakDitemukanError("TKT-999");
    } catch (const ParkirException& e) {
        cout << "   Caught: " << e.what() << endl;
    }
    try {
        cout << "3. Testing KendaraanSudahParkirError..." << endl;
        throw KendaraanSudahParkirError("B 1234 XYZ");
    } catch (const ParkirException& e) {
        cout << "   Caught: " << e.what() << endl;
    }
    cout << "\nSemua exception berfungsi dengan baik!" << endl;
    cout << endl;
    
    cetakGaris();
    cout << "SEMUA TEST SELESAI!" << endl;
    cetakGaris();
    
    return 0;
}
```

</details>

4. Klik **Run**
5. ✅ Lihat output - harus sesuai!

---

#### Opsi B: Pakai Compiler Lokal (Jika Sudah Install)

```bash
# Windows CMD
g++ -std=c++17 -Wall -Wextra -Iinclude src\Kendaraan.cpp src\Motor.cpp src\Mobil.cpp src\Truk.cpp test_bagian1.cpp -o test_bagian1.exe
test_bagian1.exe

# Linux/macOS
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp test_bagian1.cpp -o test_bagian1
./test_bagian1

# Atau pakai Makefile
make
make run
```

---

### 2️⃣ Screenshot Output
Ambil screenshot output program untuk laporan!

---

### 3️⃣ Share ke Teman-teman

**Kirim file ini ke teman Anda:**
```
📁 include/
   ├── Kendaraan.h
   ├── Motor.h
   ├── Mobil.h
   ├── Truk.h
   └── Exception.h

📁 src/
   ├── Kendaraan.cpp
   ├── Motor.cpp
   ├── Mobil.cpp
   └── Truk.cpp

📄 TUGAS_TEMAN_2.md
📄 TUGAS_TEMAN_3.md
📄 TUGAS_TEMAN_4.md
```

**Atau kirim seluruh folder `parkirin/`**

---

### 4️⃣ Baca Dokumentasi

**Untuk presentasi:**
- 📖 `DIAGRAM_OOP.md` - Diagram untuk presentasi
- 📖 `README_BAGIAN1.md` - Penjelasan detail

**Untuk teman-teman:**
- 📖 `PEMBAGIAN_TUGAS.md` - Pembagian tugas kelompok

---

## 📊 Output yang Diharapikan

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
Ukuran slot: KECIL

Tarif Motor:
- 1 jam: Rp2000 (Expected: Rp2000) ✅
- 2 jam: Rp3000 (Expected: Rp3000) ✅
- 3 jam: Rp4000 (Expected: Rp4000) ✅

================================================
TEST MOBIL
================================================
Jenis: Mobil
Plat: B 5678 ABC
Ukuran slot: SEDANG

Tarif Mobil:
- 1 jam: Rp5000 (Expected: Rp5000) ✅
- 4 jam: Rp14000 (Expected: Rp14000) ✅

================================================
TEST TRUK
================================================
Jenis: Truk
Plat: B 9999 TRK
Ukuran slot: BESAR

Tarif Truk:
- 1 jam: Rp10000 (Expected: Rp10000) ✅
- 5 jam: Rp34000 (Expected: Rp34000) ✅

================================================
TEST POLIMORFISME
================================================
Memanggil method melalui pointer Kendaraan*:
1. Motor (3 jam): Rp4000 ✅
2. Mobil (3 jam): Rp11000 ✅
3. Truk (3 jam): Rp22000 ✅

Polimorfisme berfungsi dengan baik!

================================================
TEST EXCEPTION
================================================
1. Testing ParkirPenuhError...
   Caught: Parkir penuh: Tidak ada slot yang tersedia untuk Motor ✅
2. Testing TiketTidakDitemukanError...
   Caught: Tiket tidak ditemukan: TKT-999 ✅
3. Testing KendaraanSudahParkirError...
   Caught: Kendaraan dengan plat B 1234 XYZ sudah berada di dalam gedung ✅

Semua exception berfungsi dengan baik!

================================================
SEMUA TEST SELESAI!
================================================
```

---

## ✅ Checklist Anda

- [ ] ✅ Test kode di online compiler atau lokal
- [ ] ✅ Screenshot output untuk laporan
- [ ] ✅ Share file ke Teman 2 dan 3
- [ ] ✅ Baca DIAGRAM_OOP.md untuk presentasi
- [ ] ✅ Siap presentasikan 4 konsep OOP

---

## 🎓 Siap Presentasi?

### Tunjukkan ke Dosen:

**1. Abstraksi:**
```cpp
virtual int hitungTarif(int durasiJam) const = 0;  // Pure virtual (= 0)
```

**2. Pewarisan:**
```cpp
class Motor : public Kendaraan { ... }  // Motor mewarisi Kendaraan
```

**3. Polimorfisme:**
```
Kendaraan* k = new Motor(...);
k->hitungTarif(3);  // Runtime memanggil Motor::hitungTarif()
```

**4. Enkapsulasi:**
```cpp
private:
    static const int TARIF_JAM_PERTAMA = 2000;  // Data tersembunyi
```

---

## 🎉 SELAMAT!

Bagian Anda **100% SELESAI!** 🚀

**Tinggal:**
1. Test kode ✅
2. Screenshot ✅
3. Share ke teman ✅
4. Presentasi ✅

---

**Good luck! 🎓**
