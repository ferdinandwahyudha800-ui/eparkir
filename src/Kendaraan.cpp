#include "Kendaraan.h"

/**
 * Implementasi constructor Kendaraan
 */
Kendaraan::Kendaraan(const std::string& plat, const std::string& jenis)
    : platNomor(plat), jenisKendaraan(jenis) {
    // Constructor dasar untuk semua kendaraan
}

/**
 * Getter untuk plat nomor
 */
std::string Kendaraan::getPlatNomor() const {
    return platNomor;
}

/**
 * Getter untuk jenis kendaraan
 */
std::string Kendaraan::getJenisKendaraan() const {
    return jenisKendaraan;
}
