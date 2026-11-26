#ifndef GEDUNG_PARKIR_H
#define GEDUNG_PARKIR_H

#include <ctime>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Diskon.h"
#include "Kendaraan.h"
#include "SlotParkir.h"
#include "Struk.h"
#include "Tiket.h"

class GedungParkir {
private:
    std::string namaGedung;
    std::vector<SlotParkir> daftarSlot;
    std::map<std::string, std::unique_ptr<Tiket>> tiketAktif;
    std::vector<std::unique_ptr<Kendaraan>> kendaraanAktif;
    int totalPendapatan;
    int counterTiket;

    SlotParkir* cariSlotKosong(UkuranSlot ukuranMinimum);
    bool cekPlatSudahAda(const std::string& plat) const;
    std::string generateIdTiket();

public:
    GedungParkir(int jumlahKecil, int jumlahSedang, int jumlahBesar);
    GedungParkir(const std::string& nama,
                 int jumlahKecil,
                 int jumlahSedang,
                 int jumlahBesar);

    Tiket* masuk(std::unique_ptr<Kendaraan> kendaraan, std::time_t waktuMasuk);
    Struk keluar(const std::string& idTiket,
                 std::time_t waktuKeluar,
                 const Diskon& diskon);

    void tampilkanStatus() const;
    bool isPlatSudahParkir(const std::string& platNomor) const;
    int getTotalPendapatan() const;
};

#endif // GEDUNG_PARKIR_H
