#include <ctime>
#include <iostream>
#include <memory>

#include "DiskonMember.h"
#include "GedungParkir.h"
#include "HitungDurasi.h"
#include "Mobil.h"
#include "Motor.h"
#include "TanpaDiskon.h"
#include "Truk.h"

namespace {
std::time_t waktuPadaJam(int jam, int menit) {
    std::tm waktu = {};
    waktu.tm_year = 124;
    waktu.tm_mon = 0;
    waktu.tm_mday = 15;
    waktu.tm_hour = jam;
    waktu.tm_min = menit;
    waktu.tm_sec = 0;
    return std::mktime(&waktu);
}

void cetakMasuk(const char* jenis,
                const std::string& plat,
                Tiket* tiket) {
    std::cout << "\n[" << HitungDurasi::formatWaktu(tiket->getWaktuMasuk()) << "] "
              << jenis << " " << plat << " masuk\n"
              << "  -> Slot: " << tiket->getSlot()->getKode()
              << " (" << (tiket->getSlot()->getUkuran() == UkuranSlot::KECIL
                             ? "KECIL"
                             : tiket->getSlot()->getUkuran() == UkuranSlot::SEDANG
                                   ? "SEDANG"
                                   : "BESAR")
              << ")\n"
              << "  -> Tiket: " << tiket->getId() << "\n";
}
}

int main() {
    std::cout << "================================================\n"
              << "SIMULASI PARKIR PINTAR v1.0\n"
              << "================================================\n";

    GedungParkir gedung("Parkir Pintar", 2, 2, 1);

    try {
        std::time_t masukMotor = waktuPadaJam(10, 0);
        auto motor1 = std::make_unique<Motor>("B 1234 XYZ");
        Tiket* tiket1 = gedung.masuk(std::move(motor1), masukMotor);
        cetakMasuk("Motor", "B 1234 XYZ", tiket1);

        TanpaDiskon tanpaDiskon;
        std::time_t keluarMotor = waktuPadaJam(10, 45);
        Struk struk1 = gedung.keluar(
            tiket1->getId(), keluarMotor, tanpaDiskon);
        std::cout << "\n[10:45] Motor B 1234 XYZ keluar (" << struk1.idTiket << ")\n";
        std::cout << "  -> Durasi: " << struk1.durasiJam << " jam\n";
        std::cout << "  -> Tarif: Rp " << struk1.tarifDasar << "\n";
        std::cout << "  -> Diskon: " << tanpaDiskon.getNama() << "\n";
        std::cout << "  -> Total Bayar: Rp " << struk1.totalBayar << "\n";

        DiskonMember diskonMember;
        std::time_t masukMobil = waktuPadaJam(11, 0);
        auto mobil1 = std::make_unique<Mobil>("D 5678 ABC");
        Tiket* tiket2 = gedung.masuk(std::move(mobil1), masukMobil);
        cetakMasuk("Mobil", "D 5678 ABC", tiket2);

        Struk struk2 = gedung.keluar(
            tiket2->getId(), waktuPadaJam(14, 10), diskonMember);
        struk2.cetak();

        std::time_t masukTruk = waktuPadaJam(12, 0);
        auto truk1 = std::make_unique<Truk>("B 9001 TRK");
        Tiket* tiket3 = gedung.masuk(std::move(truk1), masukTruk);
        cetakMasuk("Truk", "B 9001 TRK", tiket3);
        Struk struk3 = gedung.keluar(
            tiket3->getId(), waktuPadaJam(17, 0), tanpaDiskon);
        struk3.cetak();

        auto motor2 = std::make_unique<Motor>("B 2001 MTR");
        gedung.masuk(std::move(motor2), waktuPadaJam(8, 0));
        auto motor3 = std::make_unique<Motor>("B 2002 MTR");
        gedung.masuk(std::move(motor3), waktuPadaJam(8, 5));

        try {
            gedung.masuk(std::make_unique<Motor>("B 2003 MTR"),
                         waktuPadaJam(8, 10));
            std::cerr << "TES GAGAL: slot kecil seharusnya sudah penuh.\n";
        } catch (const ParkirPenuhError& error) {
            std::cout << "\n[TEST] Parkir penuh: " << error.what() << "\n";
        }

        try {
            gedung.masuk(std::make_unique<Motor>("B 2002 MTR"),
                         waktuPadaJam(8, 15));
            std::cerr << "TES GAGAL: plat duplikat seharusnya ditolak.\n";
        } catch (const KendaraanSudahParkirError& error) {
            std::cout << "[TEST] Plat duplikat: " << error.what() << "\n";
        }

        try {
            gedung.keluar("TKT-PALSUS", waktuPadaJam(9, 0), tanpaDiskon);
            std::cerr << "TES GAGAL: tiket palsu seharusnya ditolak.\n";
        } catch (const TiketTidakDitemukanError& error) {
            std::cout << "[TEST] Tiket tidak ditemukan: " << error.what() << "\n";
        }
    } catch (const ParkirException& error) {
        std::cerr << "\nERROR: " << error.what() << "\n";
        return 1;
    } catch (const std::exception& error) {
        std::cerr << "\nERROR: " << error.what() << "\n";
        return 1;
    }

    gedung.tampilkanStatus();
    return 0;
}
