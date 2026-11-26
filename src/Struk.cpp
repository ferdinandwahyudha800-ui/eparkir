#include "Struk.h"
#include <iostream>
#include <iomanip>
#include <ctime>

/**
 * Cetak struk parkir ke console dengan format rapi
 */
void Struk::cetak() const {
    // Format waktu ke string yang mudah dibaca
    auto formatWaktu = [](std::time_t t) -> std::string {
        char buf[32];
        std::tm* tm_info = std::localtime(&t);
        std::strftime(buf, sizeof(buf), "%d-%m-%Y %H:%M:%S", tm_info);
        return std::string(buf);
    };

    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "          STRUK PARKIR E-PARKIR         \n";
    std::cout << "========================================\n";
    std::cout << std::left << std::setw(18) << "ID Tiket"
              << ": " << idTiket << "\n";
    std::cout << std::left << std::setw(18) << "Plat Nomor"
              << ": " << platNomor << "\n";
    std::cout << std::left << std::setw(18) << "Jenis Kendaraan"
              << ": " << jenisKendaraan << "\n";
    std::cout << std::left << std::setw(18) << "Kode Slot"
              << ": " << kodeSlot << "\n";
    std::cout << "----------------------------------------\n";
    std::cout << std::left << std::setw(18) << "Waktu Masuk"
              << ": " << formatWaktu(waktuMasuk) << "\n";
    std::cout << std::left << std::setw(18) << "Waktu Keluar"
              << ": " << formatWaktu(waktuKeluar) << "\n";
    std::cout << std::left << std::setw(18) << "Durasi"
              << ": " << durasiJam << " jam\n";
    std::cout << "----------------------------------------\n";
    std::cout << std::left << std::setw(18) << "Tarif Dasar"
              << ": Rp " << tarifDasar << "\n";
    std::cout << std::left << std::setw(18) << "Diskon"
              << ": Rp " << diskon << "\n";
    std::cout << std::left << std::setw(18) << "TOTAL BAYAR"
              << ": Rp " << totalBayar << "\n";
    std::cout << "========================================\n";
    std::cout << "        Terima kasih telah parkir!      \n";
    std::cout << "========================================\n\n";
}
