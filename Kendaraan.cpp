#include "Kendaraan.h"

/**
 * Implementasi constructor Kendaraan
 */
Kendaraan::Kendaraan(const std::string& plat, const std::string& jenis)
    : platNomor(plat), jenisKendaraan(jenis) {
    // Constructor dasar untuk semua kendaraan
}

// ========================================
// GETTER - Implementation
// ========================================

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

// ========================================
// SETTER - Implementation
// ========================================

/**
 * Setter untuk plat nomor
 */
void Kendaraan::setPlatNomor(const std::string& plat) {
    platNomor = plat;
}

/**
 * Setter untuk jenis kendaraan
 */
void Kendaraan::setJenisKendaraan(const std::string& jenis) {
    jenisKendaraan = jenis;
}

// ========================================
// DICTIONARY - Implementation
// ========================================

/**
 * Menambah/update properti tambahan
 */
void Kendaraan::setProperti(const std::string& key, const std::string& value) {
    propertiTambahan[key] = value;
}

/**
 * Mendapatkan nilai properti
 */
std::string Kendaraan::getProperti(const std::string& key) const {
    auto it = propertiTambahan.find(key);
    if (it != propertiTambahan.end()) {
        return it->second;
    }
    return "";  // Return string kosong jika tidak ditemukan
}

/**
 * Cek apakah properti ada
 */
bool Kendaraan::hasProperti(const std::string& key) const {
    return propertiTambahan.find(key) != propertiTambahan.end();
}

/**
 * Get semua properti
 */
std::map<std::string, std::string> Kendaraan::getAllProperti() const {
    return propertiTambahan;
}

/**
 * Hapus properti
 */
void Kendaraan::hapusProperti(const std::string& key) {
    propertiTambahan.erase(key);
}
