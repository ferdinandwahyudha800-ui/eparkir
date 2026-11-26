#ifndef STRUK_H
#define STRUK_H

#include <string>
#include <ctime>

/**
 * Struct Struk - merangkum data transaksi parkir
 * Diisi saat kendaraan keluar, lalu dicetak ke console
 */
struct Struk {
    std::string idTiket;
    std::string platNomor;
    std::string jenisKendaraan;
    std::string kodeSlot;
    std::time_t waktuMasuk;
    std::time_t waktuKeluar;
    int durasiJam;
    int tarifDasar;
    int diskon;
    int totalBayar;

    /**
     * Tampilkan struk parkir ke console
     */
    void cetak() const;
};

#endif // STRUK_H
