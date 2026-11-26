#include "GedungParkir.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cctype>
#include <stdexcept>

#include "Exception.h"
#include "HitungDurasi.h"

namespace {
std::string nomorDenganLebar(int nomor, int lebar) {
    std::ostringstream stream;
    stream << std::setfill('0') << std::setw(lebar) << nomor;
    return stream.str();
}

std::string normalisasiPlat(const std::string& plat) {
    std::string hasil;
    for (char karakter : plat) {
        if (!std::isspace(static_cast<unsigned char>(karakter))) {
            hasil.push_back(
                static_cast<char>(std::toupper(static_cast<unsigned char>(karakter))));
        }
    }
    return hasil;
}

std::string namaUkuran(UkuranSlot ukuran) {
    switch (ukuran) {
        case UkuranSlot::KECIL: return "Kecil";
        case UkuranSlot::SEDANG: return "Sedang";
        case UkuranSlot::BESAR: return "Besar";
    }
    return "Tidak diketahui";
}
}

GedungParkir::GedungParkir(int jumlahKecil,
                           int jumlahSedang,
                           int jumlahBesar)
    : GedungParkir("Parkir Pintar", jumlahKecil, jumlahSedang, jumlahBesar) {
}

GedungParkir::GedungParkir(const std::string& nama,
                           int jumlahKecil,
                           int jumlahSedang,
                           int jumlahBesar)
    : namaGedung(nama), totalPendapatan(0), counterTiket(0) {
    if (jumlahKecil < 0 || jumlahSedang < 0 || jumlahBesar < 0) {
        throw std::invalid_argument("Jumlah slot tidak boleh negatif.");
    }

    for (int i = 1; i <= jumlahKecil; ++i) {
        daftarSlot.emplace_back(UkuranSlot::KECIL,
                                "A" + nomorDenganLebar(i, 1));
    }
    for (int i = 1; i <= jumlahSedang; ++i) {
        daftarSlot.emplace_back(UkuranSlot::SEDANG,
                                "B" + nomorDenganLebar(i, 1));
    }
    for (int i = 1; i <= jumlahBesar; ++i) {
        daftarSlot.emplace_back(UkuranSlot::BESAR,
                                "C" + nomorDenganLebar(i, 1));
    }
}

SlotParkir* GedungParkir::cariSlotKosong(UkuranSlot ukuranMinimum) {
    const int minimum = static_cast<int>(ukuranMinimum);
    for (int ukuran = minimum; ukuran <= static_cast<int>(UkuranSlot::BESAR); ++ukuran) {
        for (SlotParkir& slot : daftarSlot) {
            if (slot.isKosong() &&
                static_cast<int>(slot.getUkuran()) == ukuran) {
                return &slot;
            }
        }
    }
    return nullptr;
}

bool GedungParkir::cekPlatSudahAda(const std::string& plat) const {
    const std::string platDicari = normalisasiPlat(plat);
    for (const auto& entri : tiketAktif) {
        const Tiket* tiket = entri.second.get();
        if (normalisasiPlat(tiket->getKendaraan()->getPlatNomor()) ==
            platDicari) {
            return true;
        }
    }
    return false;
}

bool GedungParkir::isPlatSudahParkir(const std::string& platNomor) const {
    return cekPlatSudahAda(platNomor);
}

std::string GedungParkir::generateIdTiket() {
    ++counterTiket;
    return "TKT-" + nomorDenganLebar(counterTiket, 3);
}

Tiket* GedungParkir::masuk(std::unique_ptr<Kendaraan> kendaraan,
                           std::time_t waktuMasuk) {
    if (!kendaraan) {
        throw std::invalid_argument("Kendaraan tidak boleh nullptr.");
    }
    if (cekPlatSudahAda(kendaraan->getPlatNomor())) {
        throw KendaraanSudahParkirError(kendaraan->getPlatNomor());
    }

    SlotParkir* slot = cariSlotKosong(kendaraan->ukuranSlotMinimum());
    if (slot == nullptr) {
        throw ParkirPenuhError(kendaraan->getJenisKendaraan());
    }

    Kendaraan* kendaraanPointer = kendaraan.get();
    slot->isi(kendaraanPointer);
    kendaraanAktif.push_back(std::move(kendaraan));

    const std::string idTiket = generateIdTiket();
    auto tiket = std::make_unique<Tiket>(
        idTiket, kendaraanPointer, slot, waktuMasuk);
    Tiket* tiketPointer = tiket.get();
    tiketAktif.emplace(idTiket, std::move(tiket));
    return tiketPointer;
}

Struk GedungParkir::keluar(const std::string& idTiket,
                           std::time_t waktuKeluar,
                           const Diskon& diskon) {
    auto ditemukan = tiketAktif.find(idTiket);
    if (ditemukan == tiketAktif.end()) {
        throw TiketTidakDitemukanError(idTiket);
    }

    Tiket* tiket = ditemukan->second.get();
    Kendaraan* kendaraan = tiket->getKendaraan();
    SlotParkir* slot = tiket->getSlot();

    int durasiJam = HitungDurasi::hitungJam(
        tiket->getWaktuMasuk(), waktuKeluar);
    int tarifDasar = kendaraan->hitungTarif(durasiJam);
    int totalBayar = diskon.terapkanDiskon(tarifDasar);
    int potonganDiskon = tarifDasar - totalBayar;

    Struk struk;
    struk.idTiket = tiket->getId();
    struk.platNomor = kendaraan->getPlatNomor();
    struk.jenisKendaraan = kendaraan->getJenisKendaraan();
    struk.kodeSlot = slot->getKode();
    struk.waktuMasuk = tiket->getWaktuMasuk();
    struk.waktuKeluar = waktuKeluar;
    struk.durasiJam = durasiJam;
    struk.tarifDasar = tarifDasar;
    struk.diskon = potonganDiskon;
    struk.totalBayar = totalBayar;

    slot->kosongkan();
    totalPendapatan += totalBayar;
    tiketAktif.erase(ditemukan);

    for (auto iter = kendaraanAktif.begin(); iter != kendaraanAktif.end(); ++iter) {
        if (iter->get() == kendaraan) {
            kendaraanAktif.erase(iter);
            break;
        }
    }

    return struk;
}

void GedungParkir::tampilkanStatus() const {
    int kecilKosong = 0;
    int kecilTotal = 0;
    int sedangKosong = 0;
    int sedangTotal = 0;
    int besarKosong = 0;
    int besarTotal = 0;

    for (const SlotParkir& slot : daftarSlot) {
        switch (slot.getUkuran()) {
            case UkuranSlot::KECIL:
                ++kecilTotal;
                if (slot.isKosong()) ++kecilKosong;
                break;
            case UkuranSlot::SEDANG:
                ++sedangTotal;
                if (slot.isKosong()) ++sedangKosong;
                break;
            case UkuranSlot::BESAR:
                ++besarTotal;
                if (slot.isKosong()) ++besarKosong;
                break;
        }
    }

    std::cout << "\n================================================\n";
    std::cout << "STATUS GEDUNG PARKIR - " << namaGedung << "\n";
    std::cout << "================================================\n";
    std::cout << "Slot Kecil : " << kecilKosong << "/" << kecilTotal << " kosong\n";
    std::cout << "Slot Sedang: " << sedangKosong << "/" << sedangTotal << " kosong\n";
    std::cout << "Slot Besar : " << besarKosong << "/" << besarTotal << " kosong\n";
    std::cout << "Total Pendapatan: Rp " << totalPendapatan << "\n";
    std::cout << "================================================\n";
}

int GedungParkir::getTotalPendapatan() const {
    return totalPendapatan;
}
