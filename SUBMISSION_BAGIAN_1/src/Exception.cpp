#include "../include/Exception.h"

// ========== ParkirPenuhError ==========

ParkirPenuhError::ParkirPenuhError(const std::string& jenisKendaraan) {
    pesan = "ERROR: Tidak ada slot parkir yang tersedia untuk " + jenisKendaraan;
}

const char* ParkirPenuhError::what() const noexcept {
    return pesan.c_str();
}

// ========== TiketTidakDitemukanError ==========

TiketTidakDitemukanError::TiketTidakDitemukanError(int idTiket) {
    pesan = "ERROR: Tiket dengan ID #" + std::to_string(idTiket) + " tidak ditemukan";
}

const char* TiketTidakDitemukanError::what() const noexcept {
    return pesan.c_str();
}

// ========== KendaraanSudahParkirError ==========

KendaraanSudahParkirError::KendaraanSudahParkirError(const std::string& platNomor) {
    pesan = "ERROR: Kendaraan dengan plat nomor " + platNomor + " sudah parkir di dalam gedung";
}

const char* KendaraanSudahParkirError::what() const noexcept {
    return pesan.c_str();
}
