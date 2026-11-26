#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include "include/Kendaraan.h"
#include "include/Motor.h"
#include "include/Mobil.h"
#include "include/Truk.h"

using namespace std;

void printSeparator() {
    cout << "================================================" << endl;
}

void printHeader(const string& title) {
    printSeparator();
    cout << "  " << title << endl;
    printSeparator();
}

int main() {
    cout << "\n";
    printHeader("TEST FITUR ADVANCED: SETTER, DICTIONARY & GENERIC");
    cout << "\nDemonstrasi 3 konsep tambahan:\n";
    cout << "1. SETTER - Mengubah data setelah objek dibuat\n";
    cout << "2. DICTIONARY - Menyimpan properti tambahan dengan map\n";
    cout << "3. GENERIC/TEMPLATE - Fungsi yang fleksibel untuk berbagai tipe\n";
    cout << endl;

    // ========================================
    // TEST 1: SETTER
    // ========================================
    printHeader("TEST 1: SETTER");
    
    unique_ptr<Kendaraan> motor = make_unique<Motor>("B 1234 XYZ");
    
    cout << "Data awal Motor:" << endl;
    cout << "  Plat: " << motor->getPlatNomor() << endl;
    cout << "  Jenis: " << motor->getJenisKendaraan() << endl;
    cout << endl;
    
    // Menggunakan SETTER untuk mengubah data
    cout << "Mengubah plat menggunakan SETTER..." << endl;
    motor->setPlatNomor("B 9999 NEW");
    
    cout << "\nData setelah update:" << endl;
    cout << "  Plat: " << motor->getPlatNomor() << endl;
    cout << "  Jenis: " << motor->getJenisKendaraan() << endl;
    
    cout << "\n✅ SETTER berhasil mengubah data!\n";
    cout << endl;

    // ========================================
    // TEST 2: DICTIONARY (std::map)
    // ========================================
    printHeader("TEST 2: DICTIONARY (std::map)");
    
    unique_ptr<Kendaraan> mobil = make_unique<Mobil>("B 5678 ABC");
    
    cout << "Menambahkan properti tambahan menggunakan DICTIONARY..." << endl;
    
    // Menambah berbagai properti
    mobil->setProperti("warna", "Merah");
    mobil->setProperti("tahun", "2023");
    mobil->setProperti("pemilik", "Budi Santoso");
    mobil->setProperti("merk", "Toyota Avanza");
    mobil->setProperti("catatan", "Pelanggan VIP");
    
    cout << "\nProperti tambahan Mobil (B 5678 ABC):" << endl;
    
    // Mengambil properti satu per satu
    cout << "  Warna   : " << mobil->getProperti("warna") << endl;
    cout << "  Tahun   : " << mobil->getProperti("tahun") << endl;
    cout << "  Pemilik : " << mobil->getProperti("pemilik") << endl;
    cout << "  Merk    : " << mobil->getProperti("merk") << endl;
    cout << "  Catatan : " << mobil->getProperti("catatan") << endl;
    
    // Cek apakah properti ada
    cout << "\nMengecek properti:" << endl;
    cout << "  Punya properti 'warna'? " << (mobil->hasProperti("warna") ? "Ya" : "Tidak") << endl;
    cout << "  Punya properti 'nomor_hp'? " << (mobil->hasProperti("nomor_hp") ? "Ya" : "Tidak") << endl;
    
    // Menampilkan semua properti
    cout << "\nSemua properti menggunakan getAllProperti():" << endl;
    auto semua = mobil->getAllProperti();
    for (const auto& prop : semua) {
        cout << "  " << prop.first << " = " << prop.second << endl;
    }
    
    // Hapus properti
    cout << "\nMenghapus properti 'catatan'..." << endl;
    mobil->hapusProperti("catatan");
    cout << "Punya properti 'catatan'? " << (mobil->hasProperti("catatan") ? "Ya" : "Tidak") << endl;
    
    cout << "\n✅ DICTIONARY berhasil menyimpan metadata kendaraan!\n";
    cout << endl;

    // ========================================
    // TEST 3: GENERIC/TEMPLATE
    // ========================================
    printHeader("TEST 3: GENERIC/TEMPLATE");
    
    // Buat koleksi kendaraan
    vector<unique_ptr<Kendaraan>> parkiran;
    parkiran.push_back(make_unique<Motor>("B 1111 AAA"));
    parkiran.push_back(make_unique<Mobil>("B 2222 BBB"));
    parkiran.push_back(make_unique<Truk>("B 3333 CCC"));
    parkiran.push_back(make_unique<Motor>("B 4444 DDD"));
    parkiran.push_back(make_unique<Mobil>("B 5555 EEE"));
    
    cout << "Koleksi kendaraan di parkiran:" << endl;
    for (size_t i = 0; i < parkiran.size(); i++) {
        cout << "  " << (i+1) << ". " << parkiran[i]->getJenisKendaraan() 
             << " (" << parkiran[i]->getPlatNomor() << ")" << endl;
    }
    
    int durasi = 3; // 3 jam parkir
    
    // Menggunakan template function untuk hitung total tarif
    cout << "\nMenghitung total tarif untuk " << durasi << " jam..." << endl;
    cout << "Menggunakan GENERIC FUNCTION: hitungTotalTarif()" << endl;
    
    int total = hitungTotalTarif(parkiran, durasi);
    cout << "\n  Total tarif semua kendaraan: Rp" << total << endl;
    
    // Menghitung rata-rata
    cout << "\nMenghitung rata-rata tarif..." << endl;
    cout << "Menggunakan GENERIC FUNCTION: hitungRataRataTarif()" << endl;
    
    double rataRata = hitungRataRataTarif(parkiran, durasi);
    cout << fixed << setprecision(2);
    cout << "\n  Rata-rata tarif: Rp" << rataRata << endl;
    
    // Filter kendaraan menggunakan lambda (generic)
    cout << "\nFilter kendaraan jenis 'Motor' saja..." << endl;
    cout << "Menggunakan GENERIC FUNCTION: filterKendaraan()" << endl;
    
    // Konversi ke vector of raw pointers untuk filter
    vector<Kendaraan*> rawParkiran;
    for (auto& k : parkiran) {
        rawParkiran.push_back(k.get());
    }
    
    auto motorSaja = filterKendaraan(rawParkiran, 
        [](Kendaraan* k) { return k->getJenisKendaraan() == "Motor"; });
    
    cout << "\nHasil filter (Motor saja):" << endl;
    for (size_t i = 0; i < motorSaja.size(); i++) {
        cout << "  " << (i+1) << ". " << motorSaja[i]->getJenisKendaraan() 
             << " (" << motorSaja[i]->getPlatNomor() << ")" << endl;
    }
    
    cout << "\n✅ GENERIC TEMPLATE functions bekerja dengan sempurna!\n";
    cout << "   - Fleksibel untuk berbagai tipe container\n";
    cout << "   - Bisa digunakan dengan lambda/predicate\n";
    cout << "   - Type-safe dan reusable\n";
    cout << endl;

    // ========================================
    // RINGKASAN
    // ========================================
    printHeader("RINGKASAN FITUR ADVANCED");
    
    cout << "\n✅ SETTER:" << endl;
    cout << "   - setPlatNomor()" << endl;
    cout << "   - setJenisKendaraan()" << endl;
    cout << "   Memungkinkan perubahan data setelah objek dibuat\n";
    
    cout << "\n✅ DICTIONARY (std::map):" << endl;
    cout << "   - setProperti(key, value)" << endl;
    cout << "   - getProperti(key)" << endl;
    cout << "   - hasProperti(key)" << endl;
    cout << "   - getAllProperti()" << endl;
    cout << "   - hapusProperti(key)" << endl;
    cout << "   Menyimpan metadata/properti tambahan secara dinamis\n";
    
    cout << "\n✅ GENERIC/TEMPLATE:" << endl;
    cout << "   - hitungTotalTarif<Container>()" << endl;
    cout << "   - hitungRataRataTarif<Container>()" << endl;
    cout << "   - filterKendaraan<T, Predicate>()" << endl;
    cout << "   Fungsi yang fleksibel dan reusable untuk berbagai tipe\n";
    
    cout << endl;
    printHeader("SEMUA TEST ADVANCED FEATURES SELESAI!");
    cout << "\n🎉 Kode Anda sekarang memiliki SEMUA konsep:\n";
    cout << "   ✅ Variable\n";
    cout << "   ✅ Getter\n";
    cout << "   ✅ Setter (BARU!)\n";
    cout << "   ✅ Dictionary/Map (BARU!)\n";
    cout << "   ✅ Generic/Template (BARU!)\n";
    cout << "\nPlus 4 Pilar OOP + Exception Handling!\n";
    cout << endl;

    return 0;
}
