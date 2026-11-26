#ifndef TIKET_H
#define TIKET_H

#include <string>
#include <ctime>
#include "Kendaraan.h"
#include "SlotParkir.h"

/**
 * Kelas Tiket - mendemonstrasikan ASOSIASI
 * Tiket menghubungkan Kendaraan dan SlotParkir melalui pointer.
 * Tiket tidak memiliki Kendaraan/Slot (tidak ada ownership),
 * hanya berasosiasi dengan keduanya.
 */
class Tiket {
private:
    std::string id;         // Format: TKT-001, TKT-002, dst.
    Kendaraan* kendaraan;   // Asosiasi ke kendaraan yang parkir
    SlotParkir* slot;       // Asosiasi ke slot yang digunakan
    std::time_t waktuMasuk; // Waktu kendaraan masuk (unix timestamp)

public:
    /**
     * Constructor Tiket
     * @param id       ID unik tiket, misal "TKT-001"
     * @param kendaraan Pointer ke kendaraan
     * @param slot      Pointer ke slot parkir
     * @param waktu     Waktu masuk (std::time_t)
     */
    Tiket(const std::string& id, Kendaraan* kendaraan,
          SlotParkir* slot, std::time_t waktu);

    /**
     * Getter ID tiket
     */
    std::string getId() const;

    /**
     * Getter pointer kendaraan
     */
    Kendaraan* getKendaraan() const;

    /**
     * Getter pointer slot
     */
    SlotParkir* getSlot() const;

    /**
     * Getter waktu masuk
     */
    std::time_t getWaktuMasuk() const;
};

#endif // TIKET_H
