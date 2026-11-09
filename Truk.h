#ifndef TRUK_H
#define TRUK_H

#include "Kendaraan.h"

// Kelas Truk - mendemonstrasikan PEWARISAN dan POLIMORFISME
class Truk : public Kendaraan {
private:
    // Tarif sesuai aturan bisnis
    static const int TARIF_JAM_PERTAMA = 10000;
    static const int TARIF_JAM_BERIKUTNYA = 6000;

public:
    // Constructor
    Truk(const std::string& plat, const std::string& nama);
    
    // Override method virtual dari kelas dasar
    int hitungTarif(int durasiJam) const override;
    UkuranSlot ukuranSlotMinimum() const override;
    std::string jenisKendaraan() const override;
};

#endif // TRUK_H
