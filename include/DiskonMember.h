#ifndef DISKON_MEMBER_H
#define DISKON_MEMBER_H

#include "Diskon.h"
#include <string>

/**
 * Kelas DiskonMember - implementasi diskon untuk member
 * Mendemonstrasikan STRATEGY PATTERN - strategi diskon 20% untuk member.
 * Member mendapatkan potongan 20% dari tarif parkir.
 */
class DiskonMember : public Diskon {
private:
    // Persentase diskon untuk member
    static const int PERSENTASE_DISKON = 20; // 20%

public:
    /**
     * Terapkan diskon member 20% ke tarif asli
     * Formula: tarifAsli - (tarifAsli * 20 / 100)
     * @param tarifAsli Tarif sebelum diskon
     * @return Tarif setelah diskon 20%
     */
    int terapkanDiskon(int tarifAsli) const override;

    /**
     * Nama diskon untuk ditampilkan
     * @return "Diskon Member 20%"
     */
    std::string getNama() const override;
};

#endif // DISKON_MEMBER_H
