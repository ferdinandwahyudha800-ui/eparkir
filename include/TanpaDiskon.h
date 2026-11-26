#ifndef TANPA_DISKON_H
#define TANPA_DISKON_H

#include "Diskon.h"
#include <string>

/**
 * Kelas TanpaDiskon - implementasi Diskon tanpa potongan harga
 * Mendemonstrasikan STRATEGY PATTERN - strategi "tidak ada diskon".
 * Mengembalikan tarif apa adanya tanpa pengurangan.
 */
class TanpaDiskon : public Diskon {
public:
    /**
     * Tidak ada diskon, kembalikan tarif apa adanya
     * @param tarifAsli Tarif sebelum diskon
     * @return Tarif setelah diskon (sama dengan tarif asli)
     */
    int terapkanDiskon(int tarifAsli) const override;

    /**
     * Nama diskon untuk ditampilkan
     * @return "Tanpa Diskon"
     */
    std::string getNama() const override;
};

#endif // TANPA_DISKON_H
