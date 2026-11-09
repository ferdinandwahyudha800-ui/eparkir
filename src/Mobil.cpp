#include "Mobil.h"

/**
 * Constructor Mobil
 * Memanggil constructor parent class Kendaraan
 */
Mobil::Mobil(const std::string& plat) 
    : Kendaraan(plat, "Mobil") {
    // Inisialisasi Mobil sebagai jenis "Mobil"
}

/**
 * Implementasi perhitungan tarif untuk Mobil
 * Aturan: Jam pertama Rp5.000, jam berikutnya Rp3.000/jam
 * Contoh: 4 jam = 5000 + (3 × 3000) = Rp14.000
 */
int Mobil::hitungTarif(int durasiJam) const {
    if (durasiJam <= 0) {
        return 0;
    }
    
    if (durasiJam == 1) {
        return TARIF_JAM_PERTAMA;
    }
    
    // Jam pertama + (jam berikutnya × tarif per jam)
    return TARIF_JAM_PERTAMA + ((durasiJam - 1) * TARIF_JAM_BERIKUTNYA);
}

/**
 * Mobil membutuhkan slot SEDANG
 */
UkuranSlot Mobil::ukuranSlotMinimum() const {
    return UkuranSlot::SEDANG;
}
