#include "Motor.h"

/**
 * Constructor Motor
 * Memanggil constructor parent class Kendaraan
 */
Motor::Motor(const std::string& plat) 
    : Kendaraan(plat, "Motor") {
    // Inisialisasi Motor sebagai jenis "Motor"
}

/**
 * Implementasi perhitungan tarif untuk Motor
 * Aturan: Jam pertama Rp2.000, jam berikutnya Rp1.000/jam
 * Contoh: 3 jam = 2000 + (2 × 1000) = Rp4.000
 */
int Motor::hitungTarif(int durasiJam) const {
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
 * Motor membutuhkan slot KECIL
 */
UkuranSlot Motor::ukuranSlotMinimum() const {
    return UkuranSlot::KECIL;
}
