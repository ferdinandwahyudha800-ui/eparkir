#include "Exception.h"

// ===== ParkirPenuhError =====
ParkirPenuhError::ParkirPenuhError(const std::string& msg)
    : pesan(msg) {
}

const char* ParkirPenuhError::what() const noexcept {
    return pesan.c_str();
}

// ===== TiketTidakDitemukanError =====
TiketTidakDitemukanError::TiketTidakDitemukanError(const std::string& idTiket)
    : pesan("Tiket dengan ID '" + idTiket + "' tidak ditemukan") {
}

const char* TiketTidakDitemukanError::what() const noexcept {
    return pesan.c_str();
}

// ===== KendaraanSudahParkirError =====
KendaraanSudahParkirError::KendaraanSudahParkirError(const std::string& platNomor)
    : pesan("Kendaraan dengan plat '" + platNomor + "' sudah berada di dalam gedung") {
}

const char* KendaraanSudahParkirError::what() const noexcept {
    return pesan.c_str();
}
