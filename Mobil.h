#ifndef MOBIL_H
#define MOBIL_H

#include "Kendaraan.h"

// Kelas Mobil - mendemonstrasikan PEWARISAN dan POLIMORFISME
class Mobil : public Kendaraan {
private:
    // Tarif sesuai aturan bisnis
    static const int TARIF_JAM_PERTAMA = 5000;
    static const int TARIF_JAM_BERIKUTNYA = 3000;

public:
    // Constructor
    Mobil(const std::string& plat, const std::string& nama);
    
    // Override method virtual dari kelas dasar
    int hitungTarif(int durasiJam) const override;
    UkuranSlot ukuranSlotMinimum() const override;
    std::string jenisKendaraan() const override;
};

#endif // MOBIL_H
