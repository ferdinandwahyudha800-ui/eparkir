#include <iostream>
#include <string>
#include <ctime>
#include <stdexcept>

#include "Kendaraan.h"
#include "Motor.h"
#include "Mobil.h"
#include "Truk.h"
#include "SlotParkir.h"
#include "Tiket.h"
#include "Struk.h"

// ─────────────────────────────────────────────
// Helper: nama ukuran slot ke string
// ─────────────────────────────────────────────
std::string namaUkuran(UkuranSlot u) {
    switch (u) {
        case UkuranSlot::KECIL:  return "KECIL";
        case UkuranSlot::SEDANG: return "SEDANG";
        case UkuranSlot::BESAR:  return "BESAR";
        default:                 return "TIDAK DIKETAHUI";
    }
}

// ─────────────────────────────────────────────
// Helper: buat struk dari tiket + waktu keluar
// ─────────────────────────────────────────────
Struk buatStruk(const Tiket& tiket, std::time_t waktuKeluar, int diskon = 0) {
    Kendaraan* k = tiket.getKendaraan();
    SlotParkir* s = tiket.getSlot();

    // Hitung durasi (bulatkan ke atas, minimum 1 jam)
    double selisihDetik = std::difftime(waktuKeluar, tiket.getWaktuMasuk());
    int durasiJam = static_cast<int>(selisihDetik / 3600.0);
    if (selisihDetik > 0 && static_cast<int>(selisihDetik) % 3600 != 0) {
        durasiJam += 1; // bulatkan ke atas
    }
    if (durasiJam < 1) durasiJam = 1;

    int tarifDasar = k->hitungTarif(durasiJam);
    int total = tarifDasar - diskon;
    if (total < 0) total = 0;

    Struk struk;
    struk.idTiket        = tiket.getId();
    struk.platNomor      = k->getPlatNomor();
    struk.jenisKendaraan = k->getJenisKendaraan();
    struk.kodeSlot       = s->getKode();
    struk.waktuMasuk     = tiket.getWaktuMasuk();
    struk.waktuKeluar    = waktuKeluar;
    struk.durasiJam      = durasiJam;
    struk.tarifDasar     = tarifDasar;
    struk.diskon         = diskon;
    struk.totalBayar     = total;
    return struk;
}

// ─────────────────────────────────────────────
// TEST 1: Pembuatan slot dan status awal
// ─────────────────────────────────────────────
void test1_SlotParkir() {
    std::cout << "=== TEST 1: SlotParkir ===\n";

    SlotParkir slotA1(UkuranSlot::KECIL,  "A1");
    SlotParkir slotB1(UkuranSlot::SEDANG, "B1");
    SlotParkir slotC1(UkuranSlot::BESAR,  "C1");

    // Semua slot harus kosong saat baru dibuat
    std::cout << "Slot A1 (" << namaUkuran(slotA1.getUkuran()) << ") kosong: "
              << (slotA1.isKosong() ? "YA" : "TIDAK") << "\n";
    std::cout << "Slot B1 (" << namaUkuran(slotB1.getUkuran()) << ") kosong: "
              << (slotB1.isKosong() ? "YA" : "TIDAK") << "\n";
    std::cout << "Slot C1 (" << namaUkuran(slotC1.getUkuran()) << ") kosong: "
              << (slotC1.isKosong() ? "YA" : "TIDAK") << "\n";

    // Isi slot A1 dengan motor
    Motor motor("B 1234 ZZ");
    slotA1.isi(&motor);
    std::cout << "\nSetelah diisi Motor " << motor.getPlatNomor() << ":\n";
    std::cout << "Slot A1 kosong: " << (slotA1.isKosong() ? "YA" : "TIDAK") << "\n";
    std::cout << "Kendaraan di A1: " << slotA1.getKendaraan()->getPlatNomor() << "\n";

    // Kosongkan slot A1
    slotA1.kosongkan();
    std::cout << "\nSetelah dikosongkan:\n";
    std::cout << "Slot A1 kosong: " << (slotA1.isKosong() ? "YA" : "TIDAK") << "\n";
    std::cout << "Kendaraan di A1 (nullptr): "
              << (slotA1.getKendaraan() == nullptr ? "nullptr (benar)" : "ADA ISI") << "\n";

    // Coba isi slot yang sudah terisi → harus throw exception
    Mobil mobil("D 5678 AB");
    slotB1.isi(&mobil);
    try {
        Mobil mobil2("E 9999 XY");
        slotB1.isi(&mobil2); // harus gagal
        std::cout << "[GAGAL] Seharusnya throw exception!\n";
    } catch (const std::runtime_error& e) {
        std::cout << "\n[OK] Exception saat isi slot penuh: " << e.what() << "\n";
    }

    std::cout << "\n";
}

// ─────────────────────────────────────────────
// TEST 2: Pembuatan tiket
// ─────────────────────────────────────────────
void test2_Tiket() {
    std::cout << "=== TEST 2: Tiket ===\n";

    Mobil mobil("F 4321 CD");
    SlotParkir slot(UkuranSlot::SEDANG, "B2");
    slot.isi(&mobil);

    std::time_t sekarang = std::time(nullptr);
    Tiket tiket("TKT-001", &mobil, &slot, sekarang);

    std::cout << "ID Tiket   : " << tiket.getId() << "\n";
    std::cout << "Plat       : " << tiket.getKendaraan()->getPlatNomor() << "\n";
    std::cout << "Jenis      : " << tiket.getKendaraan()->getJenisKendaraan() << "\n";
    std::cout << "Kode Slot  : " << tiket.getSlot()->getKode() << "\n";

    char buf[32];
    std::tm* tm_info = std::localtime(&sekarang);
    std::strftime(buf, sizeof(buf), "%d-%m-%Y %H:%M:%S", tm_info);
    std::cout << "Waktu Masuk: " << buf << "\n";

    // Tiket dengan nullptr harus throw
    try {
        Tiket tiketBuruk("TKT-BAD", nullptr, &slot, sekarang);
        std::cout << "[GAGAL] Seharusnya throw!\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "[OK] Exception tiket nullptr kendaraan: " << e.what() << "\n";
    }

    std::cout << "\n";
}

// ─────────────────────────────────────────────
// TEST 3: Cetak struk
// ─────────────────────────────────────────────
void test3_Struk() {
    std::cout << "=== TEST 3: Struk ===\n";

    // Simulasi: Truk masuk 3 jam lalu
    std::time_t masuk  = std::time(nullptr) - (3 * 3600);
    std::time_t keluar = std::time(nullptr);

    Truk truk("H 7777 TT");
    SlotParkir slot(UkuranSlot::BESAR, "C3");
    slot.isi(&truk);

    Tiket tiket("TKT-002", &truk, &slot, masuk);
    Struk struk = buatStruk(tiket, keluar, 5000);
    struk.cetak();

    slot.kosongkan();
}

// ─────────────────────────────────────────────
// TEST 4: Skenario lengkap multi-kendaraan
// ─────────────────────────────────────────────
void test4_SkenarioLengkap() {
    std::cout << "=== TEST 4: Skenario Lengkap ===\n";

    // Buat beberapa slot
    SlotParkir slots[] = {
        SlotParkir(UkuranSlot::KECIL,  "A1"),
        SlotParkir(UkuranSlot::KECIL,  "A2"),
        SlotParkir(UkuranSlot::SEDANG, "B1"),
        SlotParkir(UkuranSlot::BESAR,  "C1"),
    };

    // Kendaraan masuk
    Motor  motor("G 1111 MM");
    Mobil  mobil("G 2222 BB");
    Truk   truk ("G 3333 TT");

    std::time_t now = std::time(nullptr);

    slots[0].isi(&motor);
    slots[2].isi(&mobil);
    slots[3].isi(&truk);

    Tiket t1("TKT-003", &motor, &slots[0], now - 1 * 3600);  // 1 jam
    Tiket t2("TKT-004", &mobil, &slots[2], now - 2 * 3600);  // 2 jam
    Tiket t3("TKT-005", &truk,  &slots[3], now - 5 * 3600);  // 5 jam

    // Cetak status slot
    std::cout << "\nStatus slot:\n";
    for (const auto& s : slots) {
        std::cout << "  Slot " << s.getKode()
                  << " [" << namaUkuran(s.getUkuran()) << "] - "
                  << (s.isKosong() ? "KOSONG" : "TERISI oleh " + s.getKendaraan()->getPlatNomor())
                  << "\n";
    }

    // Semua kendaraan keluar, cetak struk
    std::cout << "\nStruk keluar:\n";
    buatStruk(t1, now).cetak();
    buatStruk(t2, now).cetak();
    buatStruk(t3, now, 10000).cetak(); // Truk dapat diskon Rp10.000

    // Kosongkan slot
    slots[0].kosongkan();
    slots[2].kosongkan();
    slots[3].kosongkan();

    std::cout << "Status slot setelah semua keluar:\n";
    for (const auto& s : slots) {
        std::cout << "  Slot " << s.getKode() << " - "
                  << (s.isKosong() ? "KOSONG" : "TERISI") << "\n";
    }
}

// ─────────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────────
int main() {
    std::cout << "=========================================\n";
    std::cout << "     TEST BAGIAN 2: SLOT & TIKET         \n";
    std::cout << "=========================================\n\n";

    test1_SlotParkir();
    test2_Tiket();
    test3_Struk();
    test4_SkenarioLengkap();

    std::cout << "=========================================\n";
    std::cout << "          SEMUA TEST SELESAI             \n";
    std::cout << "=========================================\n";
    return 0;
}
