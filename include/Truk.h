#ifndef TRUK_H
#define TRUK_H

#include "Kendaraan.h"

/**
 * Kelas Truk - mendemonstrasikan PEWARISAN dan POLIMORFISME
 * Mewarisi dari kelas abstrak Kendaraan
 */
class Truk : public Kendaraan {
private:
    // Tarif untuk Truk
    static const int TARIF_JAM_PERTAMA = 10000;
    static const int TARIF_JAM_BERIKUTNYA = 6000;

public:
    /**
     * Constructor Truk
     * @param plat Nomor plat truk
     */
    explicit Truk(const std::string& plat);

    /**
     * Override method hitungTarif - POLIMORFISME
     * Truk: Jam pertama Rp10.000, jam berikutnya Rp6.000/jam
     * @param durasiJam Durasi parkir dalam jam
     * @return Total tarif parkir
     */
    int hitungTarif(int durasiJam) const override;

    /**
     * Override method ukuranSlotMinimum - POLIMORFISME
     * Truk membutuhkan slot BESAR
     */
    UkuranSlot ukuranSlotMinimum() const override;
};

#endif // TRUK_H
