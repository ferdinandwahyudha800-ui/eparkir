# 📑 INDEX FILE - BAGIAN ANDA (Bagian 1)

## 🎯 FILE INTI YANG ANDA KERJAKAN

### Header Files (.h)
1. ✅ **Kendaraan.h** - Kelas abstrak, fondasi hierarki
2. ✅ **Motor.h** - Kelas Motor (tarif Rp 2.000)
3. ✅ **Mobil.h** - Kelas Mobil (tarif Rp 5.000)
4. ✅ **Truk.h** - Kelas Truk (tarif Rp 10.000)
5. ✅ **Exception.h** - Custom exceptions

### Implementation Files (.cpp)
6. ✅ **Kendaraan.cpp** - Implementasi kelas dasar
7. ✅ **Motor.cpp** - Implementasi Motor
8. ✅ **Mobil.cpp** - Implementasi Mobil
9. ✅ **Truk.cpp** - Implementasi Truk
10. ✅ **Exception.cpp** - Implementasi exceptions

### Test & Build
11. ✅ **test_bagian1.cpp** - Program test lengkap
12. ✅ **Makefile** - Build automation

---

## 📖 DOKUMENTASI

### Dokumentasi Utama
- ✅ **README_BAGIAN1.md** ⭐ - Dokumentasi lengkap bagian Anda
- ✅ **RINGKASAN_BAGIAN_ANDA.md** ⭐ - Ringkasan dan checklist

### Panduan Instalasi
- ✅ **CARA_INSTALL_COMPILER.md** - Install g++ di Windows

### Pembagian Tugas
- ✅ **PEMBAGIAN_TUGAS.md** ⭐ - Tugas untuk 4 orang (PENTING!)

### Referensi & Bantuan
- ✅ **DIAGRAM_KELAS_BAGIAN1.txt** - Visual diagram hierarki kelas
- ✅ **FAQ_DAN_TROUBLESHOOTING.md** - FAQ dan solusi error

---

## 🗂️ STRUKTUR KODE

```
HIERARKI KELAS:
┌─────────────────┐
│   Kendaraan     │ (abstract) ← Kendaraan.h/cpp
└────────┬────────┘
         │
    ┌────┴────┬────────┐
    │         │        │
┌───▼───┐ ┌──▼───┐ ┌──▼───┐
│ Motor │ │ Mobil│ │ Truk │ ← Motor.h/cpp, Mobil.h/cpp, Truk.h/cpp
└───────┘ └──────┘ └──────┘

EXCEPTION:
┌──────────────────┐
│ std::exception   │
└────────┬─────────┘
         │
    ┌────┴────┬─────────────────┐
    │         │                 │
┌───▼───────────┐ ┌───────────────────┐ ┌─────────────────────┐
│ParkirPenuhError│ │TiketTidakDitemukan│ │KendaraanSudahParkir│
└────────────────┘ └───────────────────┘ └─────────────────────┘
                    ↑ Exception.h/cpp
```

---

## 🚀 QUICK START

### 1. Install Compiler
Baca: `CARA_INSTALL_COMPILER.md`

### 2. Kompilasi
```bash
g++ -std=c++17 -Wall -Wextra Kendaraan.cpp Motor.cpp Mobil.cpp Truk.cpp Exception.cpp test_bagian1.cpp -o test_bagian1
```

### 3. Jalankan
```bash
./test_bagian1        # Linux/Mac
test_bagian1.exe      # Windows
```

---

## 📋 UNTUK PRESENTASI

### File yang Harus Dibuka:
1. **Kendaraan.h** - Tunjukkan abstraksi dan virtual
2. **Motor.h** - Tunjukkan pewarisan (`: public Kendaraan`)
3. **test_bagian1.cpp** - Tunjukkan polimorfisme
4. **DIAGRAM_KELAS_BAGIAN1.txt** - Visual untuk penjelasan

### Konsep OOP yang Ditunjukkan:
1. ✅ **Abstraksi** - `Kendaraan` kelas abstrak
2. ✅ **Pewarisan** - Motor/Mobil/Truk extends Kendaraan
3. ✅ **Polimorfisme** - Method virtual di-override
4. ✅ **Enkapsulasi** - Atribut protected/private
5. ✅ **Exception Handling** - Custom exceptions

---

## 🤝 UNTUK TIM

### File yang Perlu Dishare:
Semua file di bagian "FILE INTI" + dokumentasi

### Dependencies:
- **Teman 1 (Bagian 2)** butuh: Kendaraan.h
- **Teman 2 (Bagian 3)** butuh: Kendaraan.h, Motor.h, Mobil.h, Truk.h
- **Teman 3 (Bagian 4)** butuh: SEMUA file Anda

### Koordinasi:
Baca `PEMBAGIAN_TUGAS.md` untuk detail tugas masing-masing

---

## ❓ JIKA ADA MASALAH

### Kompilasi Error?
→ Baca: `FAQ_DAN_TROUBLESHOOTING.md`

### Tidak Tahu Cara Compile?
→ Baca: `CARA_INSTALL_COMPILER.md`

### Mau Tahu Detail Teknis?
→ Baca: `README_BAGIAN1.md`

### Mau Lihat Diagram?
→ Buka: `DIAGRAM_KELAS_BAGIAN1.txt`

---

## ✅ STATUS BAGIAN ANDA

```
PROGRESS: █████████████████████████████ 100% COMPLETE!

[✅] Kelas Kendaraan (abstrak)
[✅] Kelas Motor
[✅] Kelas Mobil
[✅] Kelas Truk
[✅] Custom Exceptions
[✅] Program Test
[✅] Dokumentasi Lengkap
[✅] Build Tools (Makefile)
[✅] Diagram UML
[✅] FAQ & Troubleshooting
```

---

## 📊 STATISTIK KODE

| Jenis | Jumlah | File |
|-------|--------|------|
| Header Files | 5 | *.h |
| Implementation | 5 | *.cpp |
| Test Program | 1 | test_bagian1.cpp |
| Build Script | 1 | Makefile |
| Dokumentasi | 5 | *.md |
| **TOTAL** | **17 files** | |

---

## 🎓 KONSEP OOP TERIMPLEMENTASI

```cpp
// 1. ABSTRAKSI
class Kendaraan {  // Kelas abstrak
    virtual int hitungTarif() = 0;  // Pure virtual
};

// 2. PEWARISAN
class Motor : public Kendaraan {  // Inheritance
    // Mewarisi semua member
};

// 3. POLIMORFISME
unique_ptr<Kendaraan> k = make_unique<Motor>(...);
k->hitungTarif();  // Panggil Motor::hitungTarif()

// 4. ENKAPSULASI
private:
    static const int TARIF_JAM_PERTAMA = 2000;  // Hidden

// 5. EXCEPTION
throw ParkirPenuhError("Tidak ada slot");
```

---

## 🎯 NEXT STEPS

### Untuk Anda:
1. ✅ Compile dan test kode
2. ✅ Share file ke teman kelompok
3. ✅ Jelaskan pembagian tugas
4. ✅ Siapkan demo presentasi

### Untuk Tim:
1. ⏳ Teman 1: Kerjakan Bagian 2 (SlotParkir, Tiket, Struk)
2. ⏳ Teman 2: Kerjakan Bagian 3 (Diskon Strategy)
3. ⏳ Teman 3: Kerjakan Bagian 4 (GedungParkir & main)
4. ⏳ Semua: Meeting integrasi

---

## 📞 KOORDINASI

### Share via:
- Google Drive / GitHub
- WhatsApp / Discord group
- Email kelompok

### Meeting Schedule:
- **Hari 1-2:** Individual work
- **Hari 3:** Progress check
- **Hari 4:** Integration meeting
- **Hari 5:** Final testing & presentation prep

---

## 🏆 KUALITAS KODE

✅ **Kompilasi:** g++ -std=c++17 -Wall -Wextra (tanpa warning)  
✅ **Memory Safety:** Smart pointer, no manual new/delete  
✅ **Readability:** Clear naming, proper comments  
✅ **Extensibility:** Easy to add new vehicle types  
✅ **Error Handling:** Custom exceptions  
✅ **Documentation:** Complete README  
✅ **Testing:** Comprehensive test program  

---

## 📁 FILE PENTING (PRIORITY)

### ⭐⭐⭐ MUST READ:
1. `RINGKASAN_BAGIAN_ANDA.md` - Overview lengkap
2. `PEMBAGIAN_TUGAS.md` - Tugas 4 orang
3. `README_BAGIAN1.md` - Dokumentasi teknis

### ⭐⭐ SHOULD READ:
4. `DIAGRAM_KELAS_BAGIAN1.txt` - Visual diagram
5. `FAQ_DAN_TROUBLESHOOTING.md` - Solusi masalah

### ⭐ NICE TO HAVE:
6. `CARA_INSTALL_COMPILER.md` - Jika belum install compiler

---

**🎉 CONGRATULATIONS! Bagian Anda 100% Selesai dan Siap Digunakan! 🎉**

Semua file sudah dibuat dengan kualitas production-ready:
- ✅ Kode bersih dan terstruktur
- ✅ Dokumentasi lengkap
- ✅ Siap diintegrasikan dengan bagian lain
- ✅ Siap dipresentasikan

**Next:** Share ke teman-teman dan mulai koordinasi! 💪
