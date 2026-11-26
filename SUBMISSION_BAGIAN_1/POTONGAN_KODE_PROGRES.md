# 📝 POTONGAN KODE PROGRES - SEMUA KONSEP OOP

**Nama:** [Nama Anda]  
**NIM:** [NIM Anda]  
**Tanggal:** 26 November 2026

---

## 📋 DAFTAR ISI

1. [Variable](#1-variable)
2. [Getter](#2-getter)
3. [Setter](#3-setter)
4. [Method](#4-method)
5. [Inheritance (Pewarisan)](#5-inheritance-pewarisan)
6. [Interface (Abstract Class)](#6-interface-abstract-class)
7. [Abstract Method](#7-abstract-method)
8. [Collection (Vector/Map)](#8-collection-vectormap)
9. [Dictionary (std::map)](#9-dictionary-stdmap)
10. [Generic/Template](#10-generictemplate)

---

## 1. VARIABLE

### Member Variables (Atribut)
```cpp
// File: include/Kendaraan.h

class Kendaraan {
protected:
    // Variable instance - menyimpan data objek
    std::string platNomor;        // Variable untuk plat nomor
    std::string jenisKendaraan;   // Variable untuk jenis
    
    // Dictionary - Variable untuk properti tambahan
    std::map<std::string, std::string> propertiTambahan;
};
```

### Static Constants (Variable Kelas)
```cpp
// File: include/Motor.h

class Motor : public Kendaraan {
private:
    // Static variable - berlaku untuk semua objek Motor
    static const int TARIF_JAM_PERTAMA = 2000;
    static const int TARIF_JAM_BERIKUTNYA = 1000;
};
```

### Local Variables (Variable Lokal)
```cpp
// File: src/Motor.cpp

int Motor::hitungTarif(int durasiJam) const {
    // Local variable - hanya ada dalam scope function
    int tarif = TARIF_JAM_PERTAMA;
    
    if (durasiJam > 1) {
        tarif += (durasiJam - 1) * TARIF_JAM_BERIKUTNYA;
    }
    
    return tarif;
}
```

---

## 2. GETTER

### Getter untuk String
```cpp
// File: include/Kendaraan.h (Declaration)
class Kendaraan {
public:
    /**
     * Getter untuk plat nomor
     * @return Nomor plat kendaraan
     */
    std::string getPlatNomor() const;
    
    /**
     * Getter untuk jenis kendaraan
     * @return Jenis kendaraan (Motor/Mobil/Truk)
     */
    std::string getJenisKendaraan() const;
};

// File: src/Kendaraan.cpp (Implementation)
std::string Kendaraan::getPlatNomor() const {
    return platNomor;
}

std::string Kendaraan::getJenisKendaraan() const {
    return jenisKendaraan;
}
```

### Getter untuk Dictionary
```cpp
// File: include/Kendaraan.h
class Kendaraan {
public:
    /**
     * Getter untuk mendapatkan satu properti dari dictionary
     * @param key Nama properti
     * @return Nilai properti (string kosong jika tidak ada)
     */
    std::string getProperti(const std::string& key) const;
    
    /**
     * Getter untuk mendapatkan semua properti
     * @return Map semua properti
     */
    std::map<std::string, std::string> getAllProperti() const;
};

// File: src/Kendaraan.cpp
std::string Kendaraan::getProperti(const std::string& key) const {
    auto it = propertiTambahan.find(key);
    if (it != propertiTambahan.end()) {
        return it->second;
    }
    return "";  // Return string kosong jika tidak ditemukan
}

std::map<std::string, std::string> Kendaraan::getAllProperti() const {
    return propertiTambahan;
}
```

### Getter Virtual (Polymorphic)
```cpp
// File: include/Motor.h
class Motor : public Kendaraan {
public:
    /**
     * Virtual getter - override method dari parent
     */
    UkuranSlot ukuranSlotMinimum() const override;
};

// File: src/Motor.cpp
UkuranSlot Motor::ukuranSlotMinimum() const {
    return UkuranSlot::KECIL;
}
```

---

## 3. SETTER

### Setter untuk Atribut Dasar
```cpp
// File: include/Kendaraan.h (Declaration)
class Kendaraan {
public:
    /**
     * Setter untuk plat nomor
     * Mengubah nilai atribut platNomor
     * @param plat Nomor plat baru
     */
    void setPlatNomor(const std::string& plat);
    
    /**
     * Setter untuk jenis kendaraan
     * @param jenis Jenis kendaraan baru
     */
    void setJenisKendaraan(const std::string& jenis);
};

// File: src/Kendaraan.cpp (Implementation)
void Kendaraan::setPlatNomor(const std::string& plat) {
    platNomor = plat;  // Mengubah nilai atribut
}

void Kendaraan::setJenisKendaraan(const std::string& jenis) {
    jenisKendaraan = jenis;
}
```

### Setter untuk Dictionary
```cpp
// File: include/Kendaraan.h
class Kendaraan {
public:
    /**
     * Setter untuk menambah/update properti dalam dictionary
     * @param key Nama properti (contoh: "warna", "tahun")
     * @param value Nilai properti
     */
    void setProperti(const std::string& key, const std::string& value);
};

// File: src/Kendaraan.cpp
void Kendaraan::setProperti(const std::string& key, const std::string& value) {
    propertiTambahan[key] = value;  // Insert or update
}
```

### Contoh Penggunaan Setter
```cpp
// File: test_advanced_features.cpp
unique_ptr<Kendaraan> motor = make_unique<Motor>("B 1234 XYZ");

// Menggunakan setter untuk mengubah data
motor->setPlatNomor("B 9999 NEW");  // Plat berubah
motor->setProperti("warna", "Merah");  // Tambah properti
```

---

## 4. METHOD

### Method Biasa (Non-Virtual)
```cpp
// File: include/Kendaraan.h
class Kendaraan {
public:
    /**
     * Method untuk mengecek apakah properti ada
     * @param key Nama properti
     * @return true jika ada, false jika tidak
     */
    bool hasProperti(const std::string& key) const;
    
    /**
     * Method untuk menghapus properti
     * @param key Nama properti yang akan dihapus
     */
    void hapusProperti(const std::string& key);
};

// File: src/Kendaraan.cpp
bool Kendaraan::hasProperti(const std::string& key) const {
    return propertiTambahan.find(key) != propertiTambahan.end();
}

void Kendaraan::hapusProperti(const std::string& key) {
    propertiTambahan.erase(key);
}
```

### Method Virtual (Dapat Di-override)
```cpp
// File: include/Kendaraan.h
class Kendaraan {
public:
    /**
     * Virtual method - dapat di-override oleh child class
     * @param durasiJam Durasi parkir dalam jam
     * @return Total tarif parkir
     */
    virtual int hitungTarif(int durasiJam) const = 0;  // Pure virtual
};

// File: include/Motor.h
class Motor : public Kendaraan {
public:
    /**
     * Override method hitungTarif untuk Motor
     */
    int hitungTarif(int durasiJam) const override;
};

// File: src/Motor.cpp
int Motor::hitungTarif(int durasiJam) const {
    if (durasiJam <= 0) return 0;
    
    int tarif = TARIF_JAM_PERTAMA;
    if (durasiJam > 1) {
        tarif += (durasiJam - 1) * TARIF_JAM_BERIKUTNYA;
    }
    
    return tarif;
}
```

### Constructor (Special Method)
```cpp
// File: include/Motor.h
class Motor : public Kendaraan {
public:
    /**
     * Constructor Motor
     * @param plat Nomor plat motor
     */
    explicit Motor(const std::string& plat);
};

// File: src/Motor.cpp
Motor::Motor(const std::string& plat)
    : Kendaraan(plat, "Motor") {  // Memanggil constructor parent
    // Inisialisasi tambahan jika perlu
}
```

---

## 5. INHERITANCE (Pewarisan)

### Single Inheritance
```cpp
// File: include/Motor.h

/**
 * Class Motor mewarisi dari class Kendaraan
 * - Mewarisi semua member (platNomor, jenisKendaraan, propertiTambahan)
 * - Mewarisi semua method (getter, setter, dll)
 * - Harus implement abstract method (hitungTarif, ukuranSlotMinimum)
 */
class Motor : public Kendaraan {
private:
    // Member tambahan khusus Motor
    static const int TARIF_JAM_PERTAMA = 2000;
    static const int TARIF_JAM_BERIKUTNYA = 1000;

public:
    // Constructor
    explicit Motor(const std::string& plat);
    
    // Override abstract method dari parent
    int hitungTarif(int durasiJam) const override;
    UkuranSlot ukuranSlotMinimum() const override;
};
```

### Multiple Child Classes
```cpp
// File: include/Mobil.h
/**
 * Class Mobil - Child class kedua dari Kendaraan
 */
class Mobil : public Kendaraan {
private:
    static const int TARIF_JAM_PERTAMA = 5000;
    static const int TARIF_JAM_BERIKUTNYA = 3000;

public:
    explicit Mobil(const std::string& plat);
    int hitungTarif(int durasiJam) const override;
    UkuranSlot ukuranSlotMinimum() const override;
};

// File: include/Truk.h
/**
 * Class Truk - Child class ketiga dari Kendaraan
 */
class Truk : public Kendaraan {
private:
    static const int TARIF_JAM_PERTAMA = 10000;
    static const int TARIF_JAM_BERIKUTNYA = 6000;

public:
    explicit Truk(const std::string& plat);
    int hitungTarif(int durasiJam) const override;
    UkuranSlot ukuranSlotMinimum() const override;
};
```

### Hierarchy Diagram
```
        Kendaraan (Abstract)
              |
      +-------+-------+
      |       |       |
    Motor   Mobil   Truk
```

---

## 6. INTERFACE (Abstract Class)

```cpp
// File: include/Kendaraan.h

/**
 * Class Kendaraan sebagai INTERFACE (Abstract Class)
 * 
 * Karakteristik Interface/Abstract Class:
 * 1. Memiliki minimal 1 pure virtual method (= 0)
 * 2. Tidak bisa dibuat objeknya langsung
 * 3. Harus di-inherit oleh class lain
 * 4. Child class WAJIB implement semua pure virtual method
 */
class Kendaraan {
protected:
    // Protected members - bisa diakses oleh child class
    std::string platNomor;
    std::string jenisKendaraan;
    std::map<std::string, std::string> propertiTambahan;

public:
    // Constructor
    Kendaraan(const std::string& plat, const std::string& jenis);
    
    // Virtual destructor - WAJIB untuk interface/abstract class
    virtual ~Kendaraan() = default;

    // PURE VIRTUAL METHODS - Mendefinisikan interface
    // Child class WAJIB implement method ini
    virtual int hitungTarif(int durasiJam) const = 0;
    virtual UkuranSlot ukuranSlotMinimum() const = 0;

    // Concrete methods - sudah ada implementasi
    std::string getPlatNomor() const;
    std::string getJenisKendaraan() const;
    void setPlatNomor(const std::string& plat);
    void setJenisKendaraan(const std::string& jenis);
    
    // Dictionary methods
    void setProperti(const std::string& key, const std::string& value);
    std::string getProperti(const std::string& key) const;
    bool hasProperti(const std::string& key) const;
    std::map<std::string, std::string> getAllProperti() const;
    void hapusProperti(const std::string& key);
};
```

### Penggunaan Interface (Polymorphism)
```cpp
// File: test_advanced_features.cpp

// Tidak bisa buat objek Kendaraan langsung (abstract)
// Kendaraan k("B 1234 XYZ", "Motor");  // ERROR! ❌

// Harus lewat child class
unique_ptr<Kendaraan> motor = make_unique<Motor>("B 1234 XYZ");  // ✅
unique_ptr<Kendaraan> mobil = make_unique<Mobil>("B 5678 ABC");  // ✅

// Polymorphism - method yang dipanggil sesuai tipe objek sebenarnya
cout << motor->hitungTarif(3);  // Memanggil Motor::hitungTarif()
cout << mobil->hitungTarif(3);  // Memanggil Mobil::hitungTarif()
```

---

## 7. ABSTRACT METHOD

### Pure Virtual Method (Abstract Method)
```cpp
// File: include/Kendaraan.h

class Kendaraan {
public:
    /**
     * Abstract Method - harus diimplementasi oleh child class
     * Ditandai dengan = 0 di akhir deklarasi
     * 
     * @param durasiJam Durasi parkir
     * @return Total tarif parkir
     */
    virtual int hitungTarif(int durasiJam) const = 0;  // Abstract!
    
    /**
     * Abstract Method kedua
     * @return Ukuran slot minimum yang dibutuhkan
     */
    virtual UkuranSlot ukuranSlotMinimum() const = 0;  // Abstract!
};
```

### Implementasi Abstract Method di Child Class
```cpp
// File: include/Motor.h
class Motor : public Kendaraan {
public:
    /**
     * Implementasi abstract method hitungTarif untuk Motor
     * WAJIB diimplementasi, jika tidak Motor juga jadi abstract
     */
    int hitungTarif(int durasiJam) const override;
    
    /**
     * Implementasi abstract method ukuranSlotMinimum untuk Motor
     */
    UkuranSlot ukuranSlotMinimum() const override;
};

// File: src/Motor.cpp
int Motor::hitungTarif(int durasiJam) const {
    if (durasiJam <= 0) return 0;
    
    int tarif = TARIF_JAM_PERTAMA;  // Rp 2.000
    
    if (durasiJam > 1) {
        tarif += (durasiJam - 1) * TARIF_JAM_BERIKUTNYA;  // +Rp 1.000/jam
    }
    
    return tarif;
}

UkuranSlot Motor::ukuranSlotMinimum() const {
    return UkuranSlot::KECIL;  // Motor butuh slot KECIL
}
```

### Contoh Berbagai Implementasi (Polymorphism)
```cpp
// Motor: Jam pertama Rp2.000, berikutnya Rp1.000/jam
int Motor::hitungTarif(int durasiJam) const {
    if (durasiJam <= 0) return 0;
    return TARIF_JAM_PERTAMA + 
           (durasiJam > 1 ? (durasiJam - 1) * TARIF_JAM_BERIKUTNYA : 0);
}

// Mobil: Jam pertama Rp5.000, berikutnya Rp3.000/jam
int Mobil::hitungTarif(int durasiJam) const {
    if (durasiJam <= 0) return 0;
    return TARIF_JAM_PERTAMA + 
           (durasiJam > 1 ? (durasiJam - 1) * TARIF_JAM_BERIKUTNYA : 0);
}

// Truk: Jam pertama Rp10.000, berikutnya Rp6.000/jam
int Truk::hitungTarif(int durasiJam) const {
    if (durasiJam <= 0) return 0;
    return TARIF_JAM_PERTAMA + 
           (durasiJam > 1 ? (durasiJam - 1) * TARIF_JAM_BERIKUTNYA : 0);
}
```

---

## 8. COLLECTION (Vector/Map)

### Vector (Dynamic Array)
```cpp
// File: test_advanced_features.cpp

#include <vector>
#include <memory>

// Collection menggunakan vector
vector<unique_ptr<Kendaraan>> parkiran;

// Menambah element ke collection
parkiran.push_back(make_unique<Motor>("B 1111 AAA"));
parkiran.push_back(make_unique<Mobil>("B 2222 BBB"));
parkiran.push_back(make_unique<Truk>("B 3333 CCC"));

// Iterasi collection
for (size_t i = 0; i < parkiran.size(); i++) {
    cout << parkiran[i]->getPlatNomor() << endl;
}

// Range-based for loop
for (const auto& kendaraan : parkiran) {
    cout << kendaraan->getJenisKendaraan() << endl;
}
```

### Map (Dictionary/Associative Array)
```cpp
// File: include/Kendaraan.h

class Kendaraan {
protected:
    // Map sebagai collection key-value pair
    std::map<std::string, std::string> propertiTambahan;
    
public:
    // Method untuk manipulasi map
    void setProperti(const std::string& key, const std::string& value);
    std::string getProperti(const std::string& key) const;
};

// Penggunaan:
mobil->setProperti("warna", "Merah");
mobil->setProperti("tahun", "2023");
mobil->setProperti("pemilik", "Budi");

// Iterasi map
auto semua = mobil->getAllProperti();
for (const auto& prop : semua) {
    cout << prop.first << ": " << prop.second << endl;
}
```

---

## 9. DICTIONARY (std::map)

### Deklarasi Dictionary
```cpp
// File: include/Kendaraan.h

#include <map>
#include <string>

class Kendaraan {
protected:
    /**
     * DICTIONARY - std::map<key, value>
     * 
     * Struktur data key-value pair untuk menyimpan
     * properti tambahan kendaraan secara dinamis
     * 
     * Contoh penggunaan:
     * - Key: "warna",    Value: "Merah"
     * - Key: "tahun",    Value: "2023"
     * - Key: "pemilik",  Value: "Budi Santoso"
     */
    std::map<std::string, std::string> propertiTambahan;
};
```

### Method untuk Kelola Dictionary
```cpp
// File: include/Kendaraan.h
class Kendaraan {
public:
    // 1. SET - Menambah/update entry dalam dictionary
    void setProperti(const std::string& key, const std::string& value);
    
    // 2. GET - Mengambil value berdasarkan key
    std::string getProperti(const std::string& key) const;
    
    // 3. HAS - Mengecek apakah key ada dalam dictionary
    bool hasProperti(const std::string& key) const;
    
    // 4. GET ALL - Mengambil seluruh dictionary
    std::map<std::string, std::string> getAllProperti() const;
    
    // 5. DELETE - Menghapus entry dari dictionary
    void hapusProperti(const std::string& key);
};
```

### Implementasi Dictionary Methods
```cpp
// File: src/Kendaraan.cpp

// SET - Insert or Update
void Kendaraan::setProperti(const std::string& key, const std::string& value) {
    propertiTambahan[key] = value;  // Jika key ada -> update, jika tidak -> insert
}

// GET - Retrieve value
std::string Kendaraan::getProperti(const std::string& key) const {
    auto it = propertiTambahan.find(key);  // Cari key
    if (it != propertiTambahan.end()) {
        return it->second;  // Return value jika ketemu
    }
    return "";  // Return empty string jika tidak ketemu
}

// HAS - Check existence
bool Kendaraan::hasProperti(const std::string& key) const {
    return propertiTambahan.find(key) != propertiTambahan.end();
}

// GET ALL - Return entire map
std::map<std::string, std::string> Kendaraan::getAllProperti() const {
    return propertiTambahan;
}

// DELETE - Remove entry
void Kendaraan::hapusProperti(const std::string& key) {
    propertiTambahan.erase(key);
}
```

### Contoh Penggunaan Dictionary
```cpp
// File: test_advanced_features.cpp

unique_ptr<Kendaraan> mobil = make_unique<Mobil>("B 5678 ABC");

// Menambah properti (SET)
mobil->setProperti("warna", "Merah");
mobil->setProperti("tahun", "2023");
mobil->setProperti("pemilik", "Budi Santoso");
mobil->setProperti("merk", "Toyota Avanza");
mobil->setProperti("catatan", "Pelanggan VIP");

// Mengambil properti (GET)
cout << "Warna: " << mobil->getProperti("warna") << endl;      // Output: Merah
cout << "Pemilik: " << mobil->getProperti("pemilik") << endl;  // Output: Budi Santoso

// Mengecek keberadaan (HAS)
if (mobil->hasProperti("warna")) {
    cout << "Mobil punya info warna!" << endl;
}

// Mengambil semua (GET ALL)
auto semua = mobil->getAllProperti();
for (const auto& prop : semua) {
    cout << prop.first << " = " << prop.second << endl;
}
// Output:
// catatan = Pelanggan VIP
// merk = Toyota Avanza
// pemilik = Budi Santoso
// tahun = 2023
// warna = Merah

// Menghapus properti (DELETE)
mobil->hapusProperti("catatan");
cout << "Punya catatan? " << (mobil->hasProperti("catatan") ? "Ya" : "Tidak");
// Output: Tidak
```

---

## 10. GENERIC/TEMPLATE

### Template Function - Type Parameter
```cpp
// File: include/Kendaraan.h

/**
 * GENERIC FUNCTION menggunakan TEMPLATE
 * 
 * Template memungkinkan fungsi bekerja dengan berbagai tipe data
 * tanpa harus menulis ulang kode untuk setiap tipe
 * 
 * Container bisa: vector, list, deque, dll
 */
template<typename Container>
int hitungTotalTarif(const Container& container, int durasiJam) {
    int total = 0;
    
    // Iterasi semua kendaraan dalam container
    for (const auto& kendaraan : container) {
        if (kendaraan) {  // Null check
            total += kendaraan->hitungTarif(durasiJam);
        }
    }
    
    return total;
}
```

### Template Function - Multiple Type Parameters
```cpp
// File: include/Kendaraan.h

/**
 * GENERIC FILTER menggunakan 2 Template Parameters
 * 
 * @param T - Tipe element dalam container
 * @param Predicate - Tipe fungsi untuk filter (lambda, function pointer, dll)
 */
template<typename T, typename Predicate>
std::vector<T> filterKendaraan(const std::vector<T>& container, Predicate predicate) {
    std::vector<T> hasil;
    
    for (const auto& item : container) {
        if (predicate(item)) {  // Panggil fungsi predicate
            hasil.push_back(item);
        }
    }
    
    return hasil;
}
```

### Template Function - Computed Result
```cpp
// File: include/Kendaraan.h

/**
 * GENERIC FUNCTION untuk hitung rata-rata
 * Menggunakan function lain yang juga generic (hitungTotalTarif)
 */
template<typename Container>
double hitungRataRataTarif(const Container& container, int durasiJam) {
    if (container.empty()) {
        return 0.0;
    }
    
    // Gunakan generic function lain
    int total = hitungTotalTarif(container, durasiJam);
    
    // Cast ke double untuk hasil akurat
    return static_cast<double>(total) / container.size();
}
```

### Contoh Penggunaan Generic/Template
```cpp
// File: test_advanced_features.cpp

#include <vector>
#include <memory>

// Buat collection kendaraan
vector<unique_ptr<Kendaraan>> parkiran;
parkiran.push_back(make_unique<Motor>("B 1111 AAA"));
parkiran.push_back(make_unique<Mobil>("B 2222 BBB"));
parkiran.push_back(make_unique<Truk>("B 3333 CCC"));

int durasi = 3;  // 3 jam parkir

// 1. GENERIC: Hitung total tarif
//    Container = vector<unique_ptr<Kendaraan>>
int total = hitungTotalTarif(parkiran, durasi);
cout << "Total tarif: Rp" << total << endl;
// Output: Total tarif: Rp33000

// 2. GENERIC: Hitung rata-rata tarif
double rataRata = hitungRataRataTarif(parkiran, durasi);
cout << "Rata-rata: Rp" << rataRata << endl;
// Output: Rata-rata: Rp11000.00

// 3. GENERIC: Filter dengan lambda
//    T = Kendaraan*, Predicate = lambda function
vector<Kendaraan*> rawParkiran;
for (auto& k : parkiran) {
    rawParkiran.push_back(k.get());
}

// Filter hanya Motor
auto motorSaja = filterKendaraan(rawParkiran, 
    [](Kendaraan* k) { 
        return k->getJenisKendaraan() == "Motor"; 
    });

cout << "Jumlah Motor: " << motorSaja.size() << endl;
// Output: Jumlah Motor: 1

// Filter tarif lebih dari Rp10000
auto tarifMahal = filterKendaraan(rawParkiran,
    [durasi](Kendaraan* k) { 
        return k->hitungTarif(durasi) > 10000; 
    });

cout << "Kendaraan dengan tarif > Rp10000: " << tarifMahal.size() << endl;
// Output: Kendaraan dengan tarif > Rp10000: 1 (Truk)
```

### Keuntungan Generic/Template
```cpp
/**
 * TANPA GENERIC - Harus buat fungsi untuk tiap tipe:
 */
int hitungTotalTarifVector(const vector<unique_ptr<Kendaraan>>& v, int durasi);
int hitungTotalTarifList(const list<unique_ptr<Kendaraan>>& l, int durasi);
int hitungTotalTarifArray(Kendaraan* arr[], int size, int durasi);

/**
 * DENGAN GENERIC - Satu fungsi untuk semua tipe:
 */
template<typename Container>
int hitungTotalTarif(const Container& container, int durasiJam);

// Bisa dipakai untuk:
// - vector<unique_ptr<Kendaraan>>
// - list<unique_ptr<Kendaraan>>
// - deque<unique_ptr<Kendaraan>>
// - array<unique_ptr<Kendaraan>, N>
// Dan container lainnya!
```

---

## 📊 RINGKASAN

### Checklist Konsep
- [x] **Variable** - Member, static, local variables
- [x] **Getter** - Method untuk mengambil nilai atribut
- [x] **Setter** - Method untuk mengubah nilai atribut
- [x] **Method** - Regular, virtual, constructor methods
- [x] **Inheritance** - Single inheritance (Motor, Mobil, Truk extends Kendaraan)
- [x] **Interface** - Abstract class Kendaraan
- [x] **Abstract** - Pure virtual methods (= 0)
- [x] **Collection** - Vector untuk array, Map untuk dictionary
- [x] **Dictionary** - std::map<string, string> propertiTambahan
- [x] **Generic** - Template functions untuk berbagai tipe

### File Utama
```
include/
  ├── Kendaraan.h    - Interface, dictionary, generic templates
  ├── Motor.h        - Inheritance, override abstract methods
  ├── Mobil.h        - Inheritance, override abstract methods
  └── Truk.h         - Inheritance, override abstract methods

src/
  ├── Kendaraan.cpp  - Getter, setter, dictionary implementation
  ├── Motor.cpp      - Abstract method implementation
  ├── Mobil.cpp      - Abstract method implementation
  └── Truk.cpp       - Abstract method implementation

test_advanced_features.cpp - Demo semua konsep
```

---

## 🎓 Untuk Presentasi

### Demonstrasi Urutan:
1. **Variable** - Tunjukkan deklarasi member variables
2. **Getter/Setter** - Demo get dan set platNomor
3. **Dictionary** - Demo setProperti dan getProperti
4. **Interface/Abstract** - Tunjukkan pure virtual (= 0)
5. **Inheritance** - Tunjukkan Motor extends Kendaraan
6. **Collection** - Demo vector parkiran
7. **Generic** - Demo hitungTotalTarif untuk berbagai tipe

---

**Semua konsep OOP telah diimplementasi! ✅**
