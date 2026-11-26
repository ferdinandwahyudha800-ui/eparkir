# Diagram Konsep OOP
## Simulasi Parkir Pintar

## 🎯 1. ABSTRAKSI & PEWARISAN

```
         ┌─────────────────────┐
         │    Kendaraan        │ ◄── Kelas ABSTRAK
         │   (abstract)        │
         ├─────────────────────┤
         │ - platNomor         │
         │ - jenisKendaraan    │
         ├─────────────────────┤
         │ + hitungTarif() = 0 │ ◄── Virtual murni
         │ + ukuranSlot() = 0  │
         └──────────┬──────────┘
                    │
        ┌───────────┼───────────┐
        │           │           │
  ┌─────▼────┐ ┌───▼────┐ ┌───▼────┐
  │  Motor   │ │ Mobil  │ │  Truk  │ ◄── PEWARISAN
  ├──────────┤ ├────────┤ ├────────┤
  │ Rp2000   │ │ Rp5000 │ │Rp10000 │
  │ +Rp1000  │ │ +Rp3000│ │ +Rp6000│
  └──────────┘ └────────┘ └────────┘
```

---

## 🔄 2. POLIMORFISME

```cpp
// Satu pointer, banyak bentuk!
Kendaraan* k1 = new Motor("B 1234 XYZ");
Kendaraan* k2 = new Mobil("B 5678 ABC");
Kendaraan* k3 = new Truk("B 9999 TRK");

k1->hitungTarif(3); // Memanggil Motor::hitungTarif()
k2->hitungTarif(3); // Memanggil Mobil::hitungTarif()
k3->hitungTarif(3); // Memanggil Truk::hitungTarif()
```

**Runtime menentukan method mana yang dipanggil!**

---

## 🔒 3. ENKAPSULASI

```
┌──────────────────────┐
│   SlotParkir         │
├──────────────────────┤
│ - kosong ◄── PRIVATE │ ◄── Data tersembunyi
│ - kendaraan          │
├──────────────────────┤
│ + isKosong()         │ ◄── Akses lewat method
│ + isi()              │
│ + kosongkan()        │
└──────────────────────┘
```

**Data private, akses lewat public method!**

---

## 🎨 4. STRATEGY PATTERN

```
         ┌─────────────────────┐
         │      Diskon         │ ◄── Interface
         │    (abstract)       │
         ├─────────────────────┤
         │ + terapkan() = 0    │
         └──────────┬──────────┘
                    │
         ┌──────────┴───────────┐
         │                      │
  ┌──────▼────────┐  ┌─────────▼────────┐
  │ TanpaDiskon   │  │  DiskonMember    │
  ├───────────────┤  ├──────────────────┤
  │ return sama   │  │ return -20%      │
  └───────────────┘  └──────────────────┘
```

**Ganti algoritma tanpa ubah kode!**

```cpp
// Bisa ganti diskon kapan saja
Diskon* d1 = new TanpaDiskon();
Diskon* d2 = new DiskonMember();

int bayar1 = d1->terapkanDiskon(10000); // Rp10000
int bayar2 = d2->terapkanDiskon(10000); // Rp8000
```

---

## 🏢 5. KOMPOSISI

```
┌──────────────────────────────┐
│      GedungParkir            │
├──────────────────────────────┤
│ - slots[]  ◄─────────┐       │
│ - tiketAktif[]       │       │
│ - pendapatan         │       │
└──────────────────────┼───────┘
                       │ memiliki
              ┌────────▼────────┐
              │   SlotParkir    │
              ├─────────────────┤
              │ - ukuran        │
              │ - kosong        │
              └─────────────────┘
```

**GedungParkir "memiliki" banyak SlotParkir**  
**Jika gedung hancur, slot juga hancur**

---

## 🔗 6. ASOSIASI

```
┌──────────────┐        ┌──────────────┐
│   Tiket      │─────►  │  Kendaraan   │
│              │ tahu   │              │
├──────────────┤        └──────────────┘
│ - id         │
│ - waktuMasuk │        ┌──────────────┐
│              │─────►  │  SlotParkir  │
└──────────────┘ tahu   └──────────────┘
```

**Tiket "menghubungkan" Kendaraan dan Slot**  
**Jika tiket hilang, kendaraan & slot tetap ada**

---

## 📊 7. RELASI ANTAR KELAS (LENGKAP)

```
┌───────────────┐
│  Kendaraan    │◄──────────────┐
│  (abstract)   │               │ extends
└───────┬───────┘               │
        │                  ┌────┴────┐
        │ extends          │  Motor  │
        │              ┌───┤  Mobil  │
        │              │   │  Truk   │
        │              │   └─────────┘
        │              │
        │         ┌────▼──────────┐
        │         │  SlotParkir   │◄──┐
        │         └───────────────┘   │ has-a
        │                 ▲           │
        │                 │           │
    ┌───▼────┐       ┌────┴────┐  ┌──┴───────────┐
    │ Tiket  │◄──────┤ Gedung  │  │   Exception  │
    └────────┘  has-a│ Parkir  │  └──────────────┘
                     └─────────┘
                         │
                         │ uses
                    ┌────▼────┐
                    │ Diskon  │
                    │(Strategy)│
                    └─────────┘
```

---

## 🎯 8. ALUR KENDARAAN MASUK

```
1. Operator input:          Motor("B 1234 XYZ")
                                    │
                                    ▼
2. GedungParkir.masuk()      Cek plat duplikat?
                                    │
                              ┌─────┴──────┐
                              NO           YES
                              │             │
                              ▼             ▼
3. Cari slot kosong      Ada slot?    throw Error!
                              │
                        ┌─────┴──────┐
                        ADA      TIDAK
                        │           │
                        ▼           ▼
4. Alokasi           Slot.isi()  throw Error!
                        │
                        ▼
5. Buat tiket     Tiket("TKT-001", ...)
                        │
                        ▼
6. Return         Return tiket
```

---

## 🎯 9. ALUR KENDARAAN KELUAR

```
1. Operator input:         "TKT-001", waktuKeluar
                                    │
                                    ▼
2. GedungParkir.keluar()     Tiket ada?
                                    │
                              ┌─────┴──────┐
                              ADA       TIDAK
                              │           │
                              ▼           ▼
3. Hitung durasi      45 menit → 1 jam  throw Error!
                              │
                              ▼
4. Hitung tarif      Motor.hitungTarif(1) → Rp2000
                              │
                              ▼
5. Terapkan diskon   DiskonMember(2000) → Rp1600
                              │
                              ▼
6. Bersihkan        Slot.kosongkan()
                    Hapus tiket
                              │
                              ▼
7. Tambah uang      pendapatan += 1600
                              │
                              ▼
8. Return struk     Struk{...}
```

---

## ✅ RINGKASAN KONSEP OOP

| Konsep        | Kelas                  | Keterangan                          |
|---------------|------------------------|-------------------------------------|
| Abstraksi     | Kendaraan, Diskon      | Interface tanpa implementasi        |
| Pewarisan     | Motor extends Kendaraan| Turunan mewarisi parent             |
| Polimorfisme  | hitungTarif() override | Satu interface, banyak implementasi |
| Enkapsulasi   | SlotParkir (private)   | Data disembunyikan                  |
| Komposisi     | GedungParkir has Slot  | Kepemilikan penuh                   |
| Asosiasi      | Tiket knows Kendaraan  | Hubungan tanpa kepemilikan          |
| Strategy      | Diskon (TanpaDiskon, DiskonMember) | Ganti algoritma dinamis |

---

**Gunakan diagram ini untuk presentasi!** 📊
