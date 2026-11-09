# FAQ & Troubleshooting - Bagian 1

## ❓ Pertanyaan yang Sering Diajukan

### Q1: Kenapa pakai `unique_ptr` dan bukan pointer biasa?
**A:** `unique_ptr` adalah smart pointer yang otomatis menghapus memori saat tidak diperlukan. Ini mencegah memory leak dan lebih aman. PRD mensyaratkan "tanpa new/delete manual".

```cpp
// ❌ Cara lama (manual memory management)
Kendaraan* motor = new Motor("B 1234", "Ahmad");
delete motor;  // Harus ingat delete!

// ✅ Cara modern (automatic memory management)
unique_ptr<Kendaraan> motor = make_unique<Motor>("B 1234", "Ahmad");
// Otomatis dihapus saat keluar scope
```

---

### Q2: Apa itu `virtual` dan `= 0`?
**A:** 
- `virtual` = method bisa di-override oleh kelas turunan
- `= 0` = method harus diimplementasi oleh turunan (pure virtual)

```cpp
class Kendaraan {
    virtual int hitungTarif() = 0;  // HARUS diimplementasi
};

class Motor : public Kendaraan {
    int hitungTarif() override {    // Implementasi wajib
        return 2000;
    }
};
```

---

### Q3: Kenapa destruktor perlu `virtual`?
**A:** Untuk menghindari memory leak saat delete pointer kelas dasar.

```cpp
Kendaraan* k = new Motor(...);
delete k;  // Tanpa virtual destruktor, 
           // hanya ~Kendaraan() dipanggil
           // ~Motor() tidak dipanggil = MEMORY LEAK!
```

Dengan `virtual ~Kendaraan() = default;`, kedua destruktor dipanggil dengan benar.

---

### Q4: Apa beda `protected` dan `private`?
**A:**
- `private` = hanya bisa diakses di kelas itu sendiri
- `protected` = bisa diakses di kelas itu dan kelas turunannya

```cpp
class Kendaraan {
protected:
    string platNomor;  // Motor, Mobil, Truk bisa akses
private:
    string internal;   // Hanya Kendaraan yang bisa akses
};
```

---

### Q5: Bagaimana cara menambah jenis kendaraan baru?
**A:** Tinggal buat kelas baru yang inherit dari `Kendaraan`:

```cpp
// File: Bus.h
class Bus : public Kendaraan {
private:
    static const int TARIF_JAM_PERTAMA = 8000;
    static const int TARIF_JAM_BERIKUTNYA = 4000;
    
public:
    Bus(const string& plat, const string& nama)
        : Kendaraan(plat, nama) {}
    
    int hitungTarif(int durasiJam) const override {
        if (durasiJam == 1) return TARIF_JAM_PERTAMA;
        return TARIF_JAM_PERTAMA + (durasiJam - 1) * TARIF_JAM_BERIKUTNYA;
    }
    
    UkuranSlot ukuranSlotMinimum() const override {
        return UkuranSlot::BESAR;
    }
    
    string jenisKendaraan() const override {
        return "Bus";
    }
};
```

Tidak perlu mengubah kelas lain! Ini contoh **Open/Closed Principle**.

---

### Q6: Kenapa pakai `const` di banyak method?
**A:** `const` setelah method berarti method tidak mengubah state objek.

```cpp
string getPlatNomor() const {  // Tidak ubah objek
    return platNomor;
}

void setPlatNomor(string plat) {  // Mengubah objek, tidak const
    platNomor = plat;
}
```

Ini bagian dari **enkapsulasi** dan **immutability**.

---

## 🐛 Troubleshooting Kompilasi

### Error: "undefined reference to vtable"
**Penyebab:** Lupa implementasi method virtual di file .cpp

**Solusi:**
```cpp
// ❌ Motor.cpp kosong atau tidak ada implementasi hitungTarif()

// ✅ Motor.cpp harus ada:
int Motor::hitungTarif(int durasiJam) const {
    // implementasi
}
```

---

### Error: "cannot declare variable 'motor' to be of abstract type"
**Penyebab:** Mencoba membuat objek dari kelas abstrak

```cpp
// ❌ Salah
Kendaraan kendaraan("B 1234", "Ahmad");  // Error!

// ✅ Benar
Motor motor("B 1234", "Ahmad");  // OK
// atau
unique_ptr<Kendaraan> k = make_unique<Motor>("B 1234", "Ahmad");  // OK
```

---

### Error: "no matching function for call to Motor::Motor()"
**Penyebab:** Constructor parent tidak dipanggil dengan benar

```cpp
// ❌ Salah
Motor::Motor(const string& plat, const string& nama) {
    // Constructor Kendaraan tidak dipanggil!
}

// ✅ Benar
Motor::Motor(const string& plat, const string& nama)
    : Kendaraan(plat, nama) {  // Panggil constructor parent
}
```

---

### Error: "use of deleted function unique_ptr::unique_ptr(const unique_ptr&)"
**Penyebab:** Mencoba copy `unique_ptr`

```cpp
// ❌ Salah
unique_ptr<Motor> motor1 = make_unique<Motor>(...);
unique_ptr<Motor> motor2 = motor1;  // Error! Tidak bisa di-copy

// ✅ Benar - gunakan move
unique_ptr<Motor> motor2 = std::move(motor1);  // motor1 jadi nullptr

// ✅ Atau pakai reference
unique_ptr<Motor> motor1 = make_unique<Motor>(...);
processMotor(*motor1);  // Pass by reference
```

---

### Warning: "unused parameter 'durasiJam'"
**Penyebab:** Parameter tidak dipakai dalam implementasi

```cpp
// ❌ Warning
int Motor::hitungTarif(int durasiJam) const {
    return 2000;  // durasiJam tidak dipakai
}

// ✅ Pakai parameter atau hapus nama
int Motor::hitungTarif(int) const {
    return 2000;
}
```

---

### Error saat compile: "No such file or directory"
**Penyebab:** File tidak ada atau path salah

**Solusi:**
1. Pastikan semua file di folder yang sama:
   ```
   ls *.h *.cpp
   ```

2. Kompilasi dengan path lengkap:
   ```bash
   g++ -std=c++17 -Wall -Wextra ./Kendaraan.cpp ./Motor.cpp ...
   ```

---

## 🎯 Best Practices

### 1. Selalu gunakan `override` keyword
```cpp
// ✅ Lebih baik
int hitungTarif(int durasiJam) const override;

// ❌ Kurang eksplisit
int hitungTarif(int durasiJam) const;
```

Benefit: Compiler akan error jika signature tidak match parent.

---

### 2. Gunakan `= default` untuk special members
```cpp
virtual ~Kendaraan() = default;  // Compiler-generated destructor
```

---

### 3. Initialization list lebih efisien dari assignment
```cpp
// ✅ Lebih efisien
Motor::Motor(const string& plat, const string& nama)
    : Kendaraan(plat, nama) {
}

// ❌ Kurang efisien
Motor::Motor(const string& plat, const string& nama) {
    this->plat = plat;  // Assignment, bukan initialization
    this->nama = nama;
}
```

---

### 4. Pakai `const` reference untuk parameter string
```cpp
// ✅ Lebih efisien (tidak copy)
Motor(const string& plat, const string& nama);

// ❌ Kurang efisien (copy string)
Motor(string plat, string nama);
```

---

## 📚 Konsep yang Perlu Dipahami untuk Presentasi

### 1. Polimorfisme Runtime vs Compile-time
```cpp
// Runtime polymorphism (yang kita pakai)
unique_ptr<Kendaraan> k = make_unique<Motor>(...);
k->hitungTarif(3);  // Decided at runtime via vtable

// Compile-time polymorphism (templates)
template<typename T>
void process(T kendaraan) {
    kendaraan.hitungTarif(3);  // Decided at compile time
}
```

---

### 2. SOLID Principles yang Diterapkan

**S - Single Responsibility:**
- Setiap kelas punya satu tanggung jawab
- `Motor` hanya tangani logika motor

**O - Open/Closed:**
- Open for extension (bisa tambah Bus, Becak)
- Closed for modification (tidak perlu ubah Kendaraan)

**L - Liskov Substitution:**
- `Motor` bisa menggantikan `Kendaraan` di mana saja
- `unique_ptr<Kendaraan>` bisa point ke objek turunan mana saja

**D - Dependency Inversion:**
- Depend on abstraction (`Kendaraan`), bukan konkret (`Motor`)

---

### 3. Memory Management
```cpp
// Stack allocation (automatic)
Motor motor("B 1234", "Ahmad");  // Dihapus otomatis

// Heap allocation (smart pointer)
unique_ptr<Motor> motor = make_unique<Motor>(...);  // Dihapus otomatis

// Heap allocation (raw pointer) - AVOID!
Motor* motor = new Motor(...);
delete motor;  // Manual, rawan lupa
```

---

## 💡 Tips Presentasi

### Demo 1: Tunjukkan Polimorfisme
```cpp
vector<unique_ptr<Kendaraan>> parkir;
parkir.push_back(make_unique<Motor>("B 1111", "Ali"));
parkir.push_back(make_unique<Mobil>("B 2222", "Budi"));

for (const auto& k : parkir) {
    cout << k->jenisKendaraan() << ": "
         << k->hitungTarif(2) << endl;
}
// Output berbeda untuk setiap jenis!
```

---

### Demo 2: Tunjukkan Exception Handling
```cpp
try {
    throw ParkirPenuhError("Tidak ada slot Motor");
} catch (const ParkirPenuhError& e) {
    cout << "Error: " << e.what() << endl;
}
```

---

### Demo 3: Tunjukkan Extensibility
"Jika nanti ingin tambah Bus, tinggal buat kelas `Bus` baru. Tidak perlu ubah `Kendaraan`, `Motor`, atau yang lain."

---

## 🔗 Resource Tambahan

- C++ Reference: https://en.cppreference.com/
- Smart Pointers: https://en.cppreference.com/w/cpp/memory/unique_ptr
- Virtual Functions: https://en.cppreference.com/w/cpp/language/virtual
- SOLID Principles: https://en.wikipedia.org/wiki/SOLID

---

## ✅ Checklist Sebelum Demo

- [ ] Kompilasi tanpa error dan warning
- [ ] Semua test case jalan dengan benar
- [ ] Bisa jelaskan setiap konsep OOP di kode
- [ ] Bisa tunjukkan polimorfisme dengan contoh
- [ ] Bisa jelaskan kenapa pakai virtual destructor
- [ ] Bisa jelaskan benefit smart pointer
- [ ] Siap jawab pertanyaan dosen tentang OOP

---

**Good luck! 🚀**
