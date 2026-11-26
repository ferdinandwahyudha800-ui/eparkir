#ifndef MOTOR_H
#define MOTOR_H

#include "Kendaraan.h"

/**
 * Kelas Motor - mendemonstrasikan PEWARISAN dan POLIMORFISME
 * Mewarisi dari kelas abstrak Kendaraan
 */
class Motor : public Kendaraan {
private:
    // Tarif untuk Motor
    static const int TARIF_JAM_PERTAMA = 2000;
    static const int TARIF_JAM_BERIKUTNYA = 1000;

public:
    /**
     * Constructor Motor
     * @param plat Nomor plat motor
     */
    explicit Motor(const std::string& plat);

    /**
     * Override method hitungTarif - POLIMORFISME
     * Motor: Jam pertama Rp2.000, jam berikutnya Rp1.000/jam
     * @param durasiJam Durasi parkir dalam jam
     * @return Total tarif parkir
     */
    int hitungTarif(int durasiJam) const override;

    /**
     * Override method ukuranSlotMinimum - POLIMORFISME
     * Motor membutuhkan slot KECIL
     */
    UkuranSlot ukuranSlotMinimum() const override;
};

#endif // MOTOR_H
