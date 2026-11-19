#ifndef SLOTPARKIR_H
#define SLOTPARKIR_H

#include <string>
#include "Kendaraan.h"

/**
 * Kelas SlotParkir - mendemonstrasikan ENKAPSULASI
 * Status slot (kosong/terisi) dan kendaraan yang parkir adalah data private
 * Hanya bisa diakses dan diubah melalui method publik
 */
class SlotParkir {
private:
    UkuranSlot ukuran;              // Ukuran slot: KECIL, SEDANG, atau BESAR
    bool kosong;                    // true jika slot belum terisi
    Kendaraan* kendaraanTerparkir;  // Pointer ke kendaraan, nullptr jika kosong
    std::string kode;               // Kode slot, misal: "A1", "B2", dll

public:
    /**
     * Constructor SlotParkir
     * @param ukuran Ukuran slot (KECIL/SEDANG/BESAR)
     * @param kode   Kode identifikasi slot, misal "A1"
     */
    SlotParkir(UkuranSlot ukuran, const std::string& kode);

    /**
     * Cek apakah slot kosong
     * @return true jika tidak ada kendaraan
     */
    bool isKosong() const;

    /**
     * Isi slot dengan kendaraan
     * @param kendaraan Pointer ke kendaraan yang akan diparkir
     */
    void isi(Kendaraan* kendaraan);

    /**
     * Kosongkan slot (kendaraan keluar)
     */
    void kosongkan();

    /**
     * Getter ukuran slot
     */
    UkuranSlot getUkuran() const;

    /**
     * Getter kode slot
     */
    std::string getKode() const;

    /**
     * Getter pointer kendaraan yang sedang parkir
     * @return nullptr jika slot kosong
     */
    Kendaraan* getKendaraan() const;
};

#endif // SLOTPARKIR_H
