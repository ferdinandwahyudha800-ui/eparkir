#include "Truk.h"

// Constructor - memanggil constructor kelas dasar
Truk::Truk(const std::string& plat, const std::string& nama)
    : Kendaraan(plat, nama) {
}

// Implementasi perhitungan tarif untuk Truk
// Jam pertama: Rp10.000, jam berikutnya: Rp6.000/jam
int Truk::hitungTarif(int durasiJam) const {
    if (durasiJam <= 0) {
        return 0;
    }
    
    if (durasiJam == 1) {
        return TARIF_JAM_PERTAMA;
    }
    
    // Jam pertama + (jam berikutnya * tarif per jam)
    return TARIF_JAM_PERTAMA + (durasiJam - 1) * TARIF_JAM_BERIKUTNYA;
}

// Truk membutuhkan slot BESAR
UkuranSlot Truk::ukuranSlotMinimum() const {
    return UkuranSlot::BESAR;
}

// Mengembalikan jenis kendaraan
std::string Truk::jenisKendaraan() const {
    return "Truk";
}
