#ifndef MOTOR_H
#define MOTOR_H

#include "Kendaraan.h"

// Kelas Motor - mendemonstrasikan PEWARISAN dan POLIMORFISME
class Motor : public Kendaraan {
private:
    // Tarif sesuai aturan bisnis
    static const int TARIF_JAM_PERTAMA = 2000;
    static const int TARIF_JAM_BERIKUTNYA = 1000;

public:
    // Constructor
    Motor(const std::string& plat, const std::string& nama);
    
    // Override method virtual dari kelas dasar
    int hitungTarif(int durasiJam) const override;
    UkuranSlot ukuranSlotMinimum() const override;
    std::string jenisKendaraan() const override;
};

#endif // MOTOR_H
