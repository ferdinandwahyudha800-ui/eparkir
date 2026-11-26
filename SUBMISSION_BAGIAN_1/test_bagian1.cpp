#include <iostream>
#include <memory>
#include "Motor.h"
#include "Mobil.h"
#include "Truk.h"
#include "Exception.h"

using namespace std;

// Program test untuk menguji Bagian 1
int main() {
    cout << "=== TEST BAGIAN 1: KELAS KENDARAAN & EXCEPTION ===" << endl;
    cout << endl;

    // Test 1: Polimorfisme dengan pointer ke kelas dasar
    cout << "Test 1: Polimorfisme" << endl;
    cout << "-------------------" << endl;
    
    unique_ptr<Kendaraan> motor = make_unique<Motor>("B 1234 XYZ", "Ahmad");
    unique_ptr<Kendaraan> mobil = make_unique<Mobil>("B 5678 ABC", "Budi");
    unique_ptr<Kendaraan> truk = make_unique<Truk>("B 9012 DEF", "Citra");
    
    cout << "Motor - Plat: " << motor->getPlatNomor() 
         << ", Pemilik: " << motor->getPemilik()
         << ", Jenis: " << motor->jenisKendaraan() << endl;
    
    cout << "Mobil - Plat: " << mobil->getPlatNomor() 
         << ", Pemilik: " << mobil->getPemilik()
         << ", Jenis: " << mobil->jenisKendaraan() << endl;
    
    cout << "Truk - Plat: " << truk->getPlatNomor() 
         << ", Pemilik: " << truk->getPemilik()
         << ", Jenis: " << truk->jenisKendaraan() << endl;
    
    cout << endl;

    // Test 2: Perhitungan tarif
    cout << "Test 2: Perhitungan Tarif" << endl;
    cout << "-------------------------" << endl;
    
    // Motor parkir 45 menit (dibulatkan 1 jam)
    cout << "Motor parkir 1 jam: Rp" << motor->hitungTarif(1) << endl;
    cout << "Motor parkir 2 jam: Rp" << motor->hitungTarif(2) << endl;
    cout << "Motor parkir 3 jam: Rp" << motor->hitungTarif(3) << endl;
    
    cout << endl;
    
    // Mobil parkir 3 jam 10 menit (dibulatkan 4 jam)
    cout << "Mobil parkir 1 jam: Rp" << mobil->hitungTarif(1) << endl;
    cout << "Mobil parkir 4 jam: Rp" << mobil->hitungTarif(4) << endl;
    cout << "  (Rp5.000 + 3 x Rp3.000 = Rp14.000)" << endl;
    
    cout << endl;
    
    // Truk parkir 5 jam
    cout << "Truk parkir 1 jam: Rp" << truk->hitungTarif(1) << endl;
    cout << "Truk parkir 5 jam: Rp" << truk->hitungTarif(5) << endl;
    cout << "  (Rp10.000 + 4 x Rp6.000 = Rp34.000)" << endl;
    
    cout << endl;

    // Test 3: Ukuran slot minimum
    cout << "Test 3: Ukuran Slot Minimum" << endl;
    cout << "---------------------------" << endl;
    
    auto getUkuranSlotString = [](UkuranSlot ukuran) -> string {
        switch (ukuran) {
            case UkuranSlot::KECIL: return "KECIL";
            case UkuranSlot::SEDANG: return "SEDANG";
            case UkuranSlot::BESAR: return "BESAR";
            default: return "UNKNOWN";
        }
    };
    
    cout << "Motor membutuhkan slot: " << getUkuranSlotString(motor->ukuranSlotMinimum()) << endl;
    cout << "Mobil membutuhkan slot: " << getUkuranSlotString(mobil->ukuranSlotMinimum()) << endl;
    cout << "Truk membutuhkan slot: " << getUkuranSlotString(truk->ukuranSlotMinimum()) << endl;
    
    cout << endl;

    // Test 4: Exception handling
    cout << "Test 4: Exception Handling" << endl;
    cout << "--------------------------" << endl;
    
    try {
        throw ParkirPenuhError("Tidak ada slot yang tersedia untuk kendaraan jenis Motor");
    } catch (const ParkirPenuhError& e) {
        cout << "ParkirPenuhError tertangkap: " << e.what() << endl;
    }
    
    try {
        throw TiketTidakDitemukanError("TK-001");
    } catch (const TiketTidakDitemukanError& e) {
        cout << "TiketTidakDitemukanError tertangkap: " << e.what() << endl;
    }
    
    try {
        throw KendaraanSudahParkirError("B 1234 XYZ");
    } catch (const KendaraanSudahParkirError& e) {
        cout << "KendaraanSudahParkirError tertangkap: " << e.what() << endl;
    }
    
    cout << endl;

    // Test 5: Array polimorfik
    cout << "Test 5: Array Polimorfik" << endl;
    cout << "-----------------------" << endl;
    
    vector<unique_ptr<Kendaraan>> kendaraanList;
    kendaraanList.push_back(make_unique<Motor>("B 1111 AAA", "Ali"));
    kendaraanList.push_back(make_unique<Mobil>("B 2222 BBB", "Beni"));
    kendaraanList.push_back(make_unique<Truk>("B 3333 CCC", "Caca"));
    
    for (size_t i = 0; i < kendaraanList.size(); i++) {
        const auto& k = kendaraanList[i];
        cout << (i + 1) << ". " << k->jenisKendaraan() 
             << " (" << k->getPlatNomor() << ") - "
             << "Tarif 2 jam: Rp" << k->hitungTarif(2) << endl;
    }
    
    cout << endl;
    cout << "=== SEMUA TEST BAGIAN 1 SELESAI ===" << endl;
    
    return 0;
}
