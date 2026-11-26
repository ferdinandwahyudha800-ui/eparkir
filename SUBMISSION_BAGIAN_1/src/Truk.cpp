#include "Truk.h"

/**
 * Constructor Truk
 * Memanggil constructor parent class Kendaraan
 */
Truk::Truk(const std::string& plat) 
    : Kendaraan(plat, "Truk") {
    // Inisialisasi Truk sebagai jenis "Truk"
}

/**
 * Implementasi perhitungan tarif untuk Truk
 * Aturan: Jam pertama Rp10.000, jam berikutnya Rp6.000/jam
 * Contoh: 5 jam = 10000 + (4 × 6000) = Rp34.000
 */
int Truk::hitungTarif(int durasiJam) const {
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
 * Truk membutuhkan slot BESAR
 */
UkuranSlot Truk::ukuranSlotMinimum() const {
    return UkuranSlot::BESAR;
}
