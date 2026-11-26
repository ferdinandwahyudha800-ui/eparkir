# 🚀 FITUR ADVANCED: Setter, Dictionary & Generic

## 📋 Deskripsi

File ini mendokumentasikan 3 konsep tambahan yang telah ditambahkan ke proyek:
1. **SETTER** - Method untuk mengubah data setelah objek dibuat
2. **DICTIONARY** - Menggunakan `std::map` untuk menyimpan metadata dinamis
3. **GENERIC/TEMPLATE** - Fungsi template yang fleksibel untuk berbagai tipe

---

## ✅ Checklist Konsep yang Sudah Ada

| No | Konsep | Status | Lokasi |
|----|--------|--------|--------|
| 1 | Variable | ✅ | `platNomor`, `jenisKendaraan`, `propertiTambahan` |
| 2 | Getter | ✅ | `getPlatNomor()`, `getJenisKendaraan()`, `getProperti()` |
| 3 | Setter | ✅ | `setPlatNomor()`, `setJenisKendaraan()`, `setProperti()` |
| 4 | Dictionary | ✅ | `std::map<string, string> propertiTambahan` |
| 5 | Generic | ✅ | Template functions di `Kendaraan.h` |

---

## 1️⃣ SETTER

### Definisi
Method yang digunakan untuk **mengubah nilai atribut** setelah objek dibuat.

### Implementasi

#### File: `include/Kendaraan.h`
```cpp
// SETTER - Menambahkan kemampuan mengubah data
void setPlatNomor(const std::string& plat);
void setJenisKendaraan(const std::string& jenis);
```

#### File: `src/Kendaraan.cpp`
```cpp
void Kendaraan::setPlatNomor(const std::string& plat) {
    platNomor = plat;
}

void Kendaraan::setJenisKendaraan(const std::string& jenis) {
    jenisKendaraan = jenis;
}
```

### Contoh Penggunaan
```cpp
unique_ptr<Kendaraan> motor = make_unique<Motor>("B 1234 XYZ");
cout << motor->getPlatNomor(); // Output: B 1234 XYZ

// Mengubah plat menggunakan SETTER
motor->setPlatNomor("B 9999 NEW");
cout << motor->getPlatNomor(); // Output: B 9999 NEW
```

### Use Case di Dunia Nyata
- Kendaraan ganti plat nomor
- Update jenis kendaraan (misal Motor → Motor Besar)
- Koreksi data yang salah input

---

## 2️⃣ DICTIONARY (std::map)

### Definisi
Struktur data **key-value pair** untuk menyimpan properti tambahan secara dinamis tanpa harus menambah atribut baru di class.

### Implementasi

#### File: `include/Kendaraan.h`
```cpp
protected:
    // DICTIONARY - menyimpan properti tambahan kendaraan (metadata)
    std::map<std::string, std::string> propertiTambahan;

public:
    // Method untuk kelola dictionary
    void setProperti(const std::string& key, const std::string& value);
    std::string getProperti(const std::string& key) const;
    bool hasProperti(const std::string& key) const;
    std::map<std::string, std::string> getAllProperti() const;
    void hapusProperti(const std::string& key);
```

#### File: `src/Kendaraan.cpp`
```cpp
void Kendaraan::setProperti(const std::string& key, const std::string& value) {
    propertiTambahan[key] = value;
}

std::string Kendaraan::getProperti(const std::string& key) const {
    auto it = propertiTambahan.find(key);
    if (it != propertiTambahan.end()) {
        return it->second;
    }
    return "";  // Return string kosong jika tidak ditemukan
}

bool Kendaraan::hasProperti(const std::string& key) const {
    return propertiTambahan.find(key) != propertiTambahan.end();
}

std::map<std::string, std::string> Kendaraan::getAllProperti() const {
    return propertiTambahan;
}

void Kendaraan::hapusProperti(const std::string& key) {
    propertiTambahan.erase(key);
}
```

### Contoh Penggunaan
```cpp
unique_ptr<Kendaraan> mobil = make_unique<Mobil>("B 5678 ABC");

// Menambah properti
mobil->setProperti("warna", "Merah");
mobil->setProperti("tahun", "2023");
mobil->setProperti("pemilik", "Budi Santoso");
mobil->setProperti("merk", "Toyota Avanza");

// Mengambil properti
cout << mobil->getProperti("warna");   // Output: Merah
cout << mobil->getProperti("pemilik"); // Output: Budi Santoso

// Cek apakah properti ada
if (mobil->hasProperti("warna")) {
    cout << "Punya properti warna!";
}

// Ambil semua properti
auto semua = mobil->getAllProperti();
for (const auto& prop : semua) {
    cout << prop.first << " = " << prop.second << endl;
}

// Hapus properti
mobil->hapusProperti("tahun");
```

### Use Case di Dunia Nyata
- Menyimpan info tambahan: warna, tahun, pemilik, merk
- Catatan khusus untuk pelanggan VIP
- Metadata yang bervariasi per kendaraan
- Fleksibel tanpa harus ubah struktur class

---

## 3️⃣ GENERIC/TEMPLATE

### Definisi
Fungsi atau class yang dapat bekerja dengan **berbagai tipe data** tanpa harus menulis ulang kode untuk setiap tipe.

### Implementasi

#### File: `include/Kendaraan.h`
```cpp
// Template function untuk menghitung total tarif
template<typename Container>
int hitungTotalTarif(const Container& container, int durasiJam) {
    int total = 0;
    for (const auto& kendaraan : container) {
        if (kendaraan) {
            total += kendaraan->hitungTarif(durasiJam);
        }
    }
    return total;
}

// Template function untuk filter kendaraan
template<typename T, typename Predicate>
std::vector<T> filterKendaraan(const std::vector<T>& container, Predicate predicate) {
    std::vector<T> hasil;
    for (const auto& item : container) {
        if (predicate(item)) {
            hasil.push_back(item);
        }
    }
    return hasil;
}

// Template function untuk menghitung rata-rata tarif
template<typename Container>
double hitungRataRataTarif(const Container& container, int durasiJam) {
    if (container.empty()) return 0.0;
    int total = hitungTotalTarif(container, durasiJam);
    return static_cast<double>(total) / container.size();
}
```

### Contoh Penggunaan

#### 1. Hitung Total Tarif (Generic untuk berbagai container)
```cpp
vector<unique_ptr<Kendaraan>> parkiran;
parkiran.push_back(make_unique<Motor>("B 1111 AAA"));
parkiran.push_back(make_unique<Mobil>("B 2222 BBB"));
parkiran.push_back(make_unique<Truk>("B 3333 CCC"));

int durasi = 3;
int total = hitungTotalTarif(parkiran, durasi);
cout << "Total: Rp" << total; // Total semua kendaraan
```

#### 2. Hitung Rata-rata Tarif
```cpp
double rataRata = hitungRataRataTarif(parkiran, durasi);
cout << "Rata-rata: Rp" << rataRata;
```

#### 3. Filter Kendaraan (dengan Lambda)
```cpp
// Filter hanya Motor
auto motorSaja = filterKendaraan(rawParkiran, 
    [](Kendaraan* k) { return k->getJenisKendaraan() == "Motor"; });

// Filter tarif > 10000
auto tarifMahal = filterKendaraan(rawParkiran,
    [](Kendaraan* k) { return k->hitungTarif(3) > 10000; });
```

### Keuntungan Generic/Template
✅ **Type-safe** - Compiler check tipe data  
✅ **Reusable** - Satu function untuk banyak tipe  
✅ **Flexible** - Bisa pakai vector, list, array, dll  
✅ **Performance** - Tidak ada overhead runtime  

---

## 🧪 Cara Test Fitur Advanced

### Compile & Run
```cmd
compile_test_advanced.bat
```

Atau manual:
```cmd
g++ -std=c++17 -Wall -Wextra -Iinclude src\Kendaraan.cpp src\Motor.cpp src\Mobil.cpp src\Truk.cpp test_advanced_features.cpp -o test_advanced_features.exe

test_advanced_features.exe
```

### Output yang Diharapkan
```
================================================
  TEST FITUR ADVANCED: SETTER, DICTIONARY & GENERIC
================================================

Demonstrasi 3 konsep tambahan:
1. SETTER - Mengubah data setelah objek dibuat
2. DICTIONARY - Menyimpan properti tambahan dengan map
3. GENERIC/TEMPLATE - Fungsi yang fleksibel untuk berbagai tipe

================================================
  TEST 1: SETTER
================================================
Data awal Motor:
  Plat: B 1234 XYZ
  Jenis: Motor

Mengubah plat menggunakan SETTER...

Data setelah update:
  Plat: B 9999 NEW
  Jenis: Motor

✅ SETTER berhasil mengubah data!

... (dan seterusnya)
```

---

## 📊 Ringkasan untuk Presentasi

### Slide 1: SETTER
**"Method untuk Mengubah Data"**
- `setPlatNomor()` - ubah plat
- `setJenisKendaraan()` - ubah jenis
- Use case: ganti plat, koreksi data

### Slide 2: DICTIONARY
**"Menyimpan Metadata Dinamis"**
- `std::map<string, string>` untuk key-value
- 5 method: set, get, has, getAll, hapus
- Use case: warna, tahun, pemilik, catatan

### Slide 3: GENERIC/TEMPLATE
**"Fungsi Fleksibel untuk Semua Tipe"**
- `hitungTotalTarif<Container>()`
- `filterKendaraan<T, Predicate>()`
- `hitungRataRataTarif<Container>()`
- Bisa pakai vector, list, atau container apapun

---

## ✅ Checklist Final

Sekarang kode Anda memiliki:

**Konsep Dasar:**
- [x] Variable (member variables)
- [x] Getter (2 methods)
- [x] Setter (2 methods) ⭐ BARU
- [x] Dictionary (`std::map`) ⭐ BARU
- [x] Generic/Template (3 functions) ⭐ BARU

**4 Pilar OOP:**
- [x] Abstraksi (class `Kendaraan`)
- [x] Pewarisan (Motor, Mobil, Truk)
- [x] Polimorfisme (virtual methods)
- [x] Enkapsulasi (private/protected + getter/setter)

**Tambahan:**
- [x] Exception Handling (3 custom exceptions)
- [x] Smart Pointers (`unique_ptr`)
- [x] Modern C++17 features

---

## 📁 File yang Dimodifikasi

```
include/Kendaraan.h       ← Tambah setter, dictionary, template
src/Kendaraan.cpp         ← Implementasi setter & dictionary
test_advanced_features.cpp ← Test ketiga konsep
compile_test_advanced.bat  ← Script compile
FITUR_ADVANCED.md         ← Dokumentasi (file ini)
```

---

## 🎓 Tips Presentasi

1. **Tunjukkan Setter**: Jalankan test, tunjukkan plat berubah
2. **Tunjukkan Dictionary**: Tunjukkan properti dinamis (warna, tahun, dll)
3. **Tunjukkan Generic**: Tunjukkan satu function bisa untuk vector/list/array

Bandingkan:
- **Tanpa Generic**: Harus buat 3 function berbeda
- **Dengan Generic**: 1 function untuk semua tipe ✅

---

## 🚀 Kesimpulan

Proyek Anda sekarang **100% LENGKAP** dengan:
- ✅ Semua konsep OOP
- ✅ Variable, Getter, Setter
- ✅ Dictionary (std::map)
- ✅ Generic/Template
- ✅ Exception Handling
- ✅ Modern C++ best practices

**Siap dikumpulkan dan presentasi!** 🎉
