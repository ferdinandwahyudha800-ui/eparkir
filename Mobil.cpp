#include "Mobil.h"

// Constructor - memanggil constructor kelas dasar
Mobil::Mobil(const std::string& plat, const std::string& nama)
    : Kendaraan(plat, nama) {
}

// Implementasi perhitungan tarif untuk Mobil
// Jam pertama: Rp5.000, jam berikutnya: Rp3.000/jam
int Mobil::hitungTarif(int durasiJam) const {
    if (durasiJam <= 0) {
        return 0;
    }
    
    if (durasiJam == 1) {
        return TARIF_JAM_PERTAMA;
    }
    
    // Jam pertama + (jam berikutnya * tarif per jam)
    return TARIF_JAM_PERTAMA + (durasiJam - 1) * TARIF_JAM_BERIKUTNYA;
}

// Mobil membutuhkan slot SEDANG
UkuranSlot Mobil::ukuranSlotMinimum() const {
    return UkuranSlot::SEDANG;
}

// Mengembalikan jenis kendaraan
std::string Mobil::jenisKendaraan() const {
    return "Mobil";
}
