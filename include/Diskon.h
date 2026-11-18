#ifndef DISKON_H
#define DISKON_H

#include <string>

/**
 * Interface Diskon - mendemonstrasikan STRATEGY PATTERN (ABSTRAKSI)
 * Menyediakan kontrak umum untuk berbagai strategi diskon parkir.
 * Setiap implementasi (TanpaDiskon, DiskonMember) menentukan cara
 * potongan harga diterapkan ke tarif parkir.
 */
class Diskon {
public:
    /**
     * Virtual destructor - PENTING untuk polimorfisme
     * Memastikan destructor kelas turunan dipanggil dengan benar
     */
    virtual ~Diskon() = default;

    /**
     * Terapkan diskon ke tarif asli
     * @param tarifAsli Tarif sebelum diskon
     * @return Tarif setelah diskon
     */
    virtual int terapkanDiskon(int tarifAsli) const = 0;

    /**
     * Nama diskon untuk ditampilkan
     * @return Nama strategi diskon
     */
    virtual std::string getNama() const = 0;
};

#endif // DISKON_H
