#include "Motor.h"

// Constructor - memanggil constructor kelas dasar
Motor::Motor(const std::string& plat, const std::string& nama)
    : Kendaraan(plat, nama) {
}

// Implementasi perhitungan tarif untuk Motor
// Jam pertama: Rp2.000, jam berikutnya: Rp1.000/jam
int Motor::hitungTarif(int durasiJam) const {
    if (durasiJam <= 0) {
        return 0;
    }
    
    if (durasiJam == 1) {
        return TARIF_JAM_PERTAMA;
    }
    
    // Jam pertama + (jam berikutnya * tarif per jam)
    return TARIF_JAM_PERTAMA + (durasiJam - 1) * TARIF_JAM_BERIKUTNYA;
}

// Motor membutuhkan slot KECIL
UkuranSlot Motor::ukuranSlotMinimum() const {
    return UkuranSlot::KECIL;
}

// Mengembalikan jenis kendaraan
std::string Motor::jenisKendaraan() const {
    return "Motor";
}
