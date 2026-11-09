#include "Kendaraan.h"

// Implementasi constructor
Kendaraan::Kendaraan(const std::string& plat, const std::string& nama)
    : platNomor(plat), pemilik(nama) {
}

// Implementasi getter
std::string Kendaraan::getPlatNomor() const {
    return platNomor;
}

std::string Kendaraan::getPemilik() const {
    return pemilik;
}
