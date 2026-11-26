#include "Tiket.h"
#include <stdexcept>

/**
 * Constructor Tiket
 */
Tiket::Tiket(const std::string& id, Kendaraan* kendaraan,
             SlotParkir* slot, std::time_t waktu)
    : id(id), kendaraan(kendaraan), slot(slot), waktuMasuk(waktu) {
    if (kendaraan == nullptr) {
        throw std::invalid_argument("Kendaraan tidak boleh nullptr pada Tiket.");
    }
    if (slot == nullptr) {
        throw std::invalid_argument("Slot tidak boleh nullptr pada Tiket.");
    }
}

std::string Tiket::getId() const {
    return id;
}

Kendaraan* Tiket::getKendaraan() const {
    return kendaraan;
}

SlotParkir* Tiket::getSlot() const {
    return slot;
}

std::time_t Tiket::getWaktuMasuk() const {
    return waktuMasuk;
}
