#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

// Exception khusus untuk parkir penuh
class ParkirPenuhError : public std::exception {
private:
    std::string pesan;

public:
    explicit ParkirPenuhError(const std::string& msg);
    const char* what() const noexcept override;
};

// Exception khusus untuk tiket tidak ditemukan
class TiketTidakDitemukanError : public std::exception {
private:
    std::string pesan;

public:
    explicit TiketTidakDitemukanError(const std::string& idTiket);
    const char* what() const noexcept override;
};

// Exception khusus untuk kendaraan sudah parkir
class KendaraanSudahParkirError : public std::exception {
private:
    std::string pesan;

public:
    explicit KendaraanSudahParkirError(const std::string& platNomor);
    const char* what() const noexcept override;
};

#endif // EXCEPTION_H
