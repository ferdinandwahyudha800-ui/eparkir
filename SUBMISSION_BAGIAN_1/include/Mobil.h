#ifndef MOBIL_H
#define MOBIL_H

#include "Kendaraan.h"

/**
 * Kelas Mobil - mendemonstrasikan PEWARISAN dan POLIMORFISME
 * Mewarisi dari kelas abstrak Kendaraan
 */
class Mobil : public Kendaraan {
private:
    // Tarif untuk Mobil
    static const int TARIF_JAM_PERTAMA = 5000;
    static const int TARIF_JAM_BERIKUTNYA = 3000;

public:
    /**
     * Constructor Mobil
     * @param plat Nomor plat mobil
     */
    explicit Mobil(const std::string& plat);

    /**
     * Override method hitungTarif - POLIMORFISME
     * Mobil: Jam pertama Rp5.000, jam berikutnya Rp3.000/jam
     * @param durasiJam Durasi parkir dalam jam
     * @return Total tarif parkir
     */
    int hitungTarif(int durasiJam) const override;

    /**
     * Override method ukuranSlotMinimum - POLIMORFISME
     * Mobil membutuhkan slot SEDANG
     */
    UkuranSlot ukuranSlotMinimum() const override;
};

#endif // MOBIL_H
