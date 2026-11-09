#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

/**
 * Exception dasar untuk sistem parkir
 */
class ParkirException : public std::exception {
protected:
    std::string pesan;

public:
    explicit ParkirException(const std::string& msg) : pesan(msg) {}
    
    const char* what() const noexcept override {
        return pesan.c_str();
    }
};

/**
 * Exception ketika parkir penuh - tidak ada slot yang sesuai
 */
class ParkirPenuhError : public ParkirException {
public:
    explicit ParkirPenuhError(const std::string& jenisKendaraan) 
        : ParkirException("Parkir penuh: Tidak ada slot yang tersedia untuk " + jenisKendaraan) {}
};

/**
 * Exception ketika tiket tidak ditemukan saat keluar
 */
class TiketTidakDitemukanError : public ParkirException {
public:
    explicit TiketTidakDitemukanError(const std::string& idTiket) 
        : ParkirException("Tiket tidak ditemukan: " + idTiket) {}
};

/**
 * Exception ketika kendaraan dengan plat yang sama sudah parkir
 */
class KendaraanSudahParkirError : public ParkirException {
public:
    explicit KendaraanSudahParkirError(const std::string& platNomor) 
        : ParkirException("Kendaraan dengan plat " + platNomor + " sudah berada di dalam gedung") {}
};

#endif // EXCEPTION_H
