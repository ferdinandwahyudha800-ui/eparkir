#include "SlotParkir.h"
#include <stdexcept>

/**
 * Constructor: buat slot kosong dengan ukuran dan kode tertentu
 */
SlotParkir::SlotParkir(UkuranSlot ukuran, const std::string& kode)
    : ukuran(ukuran), kosong(true), kendaraanTerparkir(nullptr), kode(kode) {
}

/**
 * Kembalikan status kosong/terisi
 */
bool SlotParkir::isKosong() const {
    return kosong;
}

/**
 * Isi slot dengan kendaraan
 * Lempar exception jika slot sudah terisi
 */
void SlotParkir::isi(Kendaraan* kendaraan) {
    if (!kosong) {
        throw std::runtime_error("Slot " + kode + " sudah terisi.");
    }
    if (kendaraan == nullptr) {
        throw std::invalid_argument("Kendaraan tidak boleh nullptr.");
    }
    kendaraanTerparkir = kendaraan;
    kosong = false;
}

/**
 * Kosongkan slot saat kendaraan keluar
 */
void SlotParkir::kosongkan() {
    kendaraanTerparkir = nullptr;
    kosong = true;
}

UkuranSlot SlotParkir::getUkuran() const {
    return ukuran;
}

std::string SlotParkir::getKode() const {
    return kode;
}

Kendaraan* SlotParkir::getKendaraan() const {
    return kendaraanTerparkir;
}
