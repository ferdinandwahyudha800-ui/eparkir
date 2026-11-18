#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include "Motor.h"
#include "Mobil.h"
#include "Truk.h"
#include "TanpaDiskon.h"
#include "DiskonMember.h"
#include "HitungDurasi.h"

using namespace std;

// Helper untuk membuat time_t dari jam dan menit tertentu
// pada tanggal yang sama (15 Januari 2024)
time_t buatWaktu(int jam, int menit) {
    tm tm_info = {};
    tm_info.tm_year = 124;  // 2024 (tahun sejak 1900)
    tm_info.tm_mon = 0;     // Januari
    tm_info.tm_mday = 15;   // Tanggal 15
    tm_info.tm_hour = jam;
    tm_info.tm_min = menit;
    tm_info.tm_sec = 0;
    return mktime(&tm_info);
}

// Program test untuk menguji Bagian 3: Diskon & Tarif
int main() {
    cout << "=== TEST BAGIAN 3: DISKON & TARIF ===" << endl;
    cout << endl;

    // Test 1: TanpaDiskon
    cout << "Test 1: TanpaDiskon" << endl;
    cout << "--------------------" << endl;

    TanpaDiskon tanpaDiskon;
    cout << "Nama: " << tanpaDiskon.getNama() << endl;
    cout << "Tarif Rp10.000 -> Rp" << tanpaDiskon.terapkanDiskon(10000) << endl;
    cout << endl;

    // Test 2: DiskonMember (20%)
    cout << "Test 2: DiskonMember (20%)" << endl;
    cout << "--------------------------" << endl;

    DiskonMember diskonMember;
    cout << "Nama: " << diskonMember.getNama() << endl;
    cout << "Tarif Rp10.000 -> Rp" << diskonMember.terapkanDiskon(10000) << endl;
    cout << "  (10.000 - 20% = Rp8.000)" << endl;
    cout << endl;

    // Test 3: HitungDurasi
    cout << "Test 3: HitungDurasi" << endl;
    cout << "--------------------" << endl;

    // 45 menit = 1 jam
    time_t masuk1 = buatWaktu(10, 0);    // 10:00
    time_t keluar1 = buatWaktu(10, 45);  // 10:45 (45 menit)
    cout << "45 menit -> " << HitungDurasi::hitungJam(masuk1, keluar1) << " jam" << endl;

    // 3 jam 10 menit = 4 jam
    time_t masuk2 = buatWaktu(10, 0);    // 10:00
    time_t keluar2 = buatWaktu(13, 10);  // 13:10 (3 jam 10 menit)
    cout << "3 jam 10 menit -> " << HitungDurasi::hitungJam(masuk2, keluar2) << " jam" << endl;

    // Minimal 1 jam (waktu sama)
    time_t masuk3 = buatWaktu(10, 0);
    time_t keluar3 = buatWaktu(10, 0);
    cout << "0 menit -> " << HitungDurasi::hitungJam(masuk3, keluar3) << " jam (minimal)" << endl;

    // Test formatWaktu
    cout << "Format waktu 10:00 -> " << HitungDurasi::formatWaktu(masuk1) << endl;
    cout << "Format waktu 13:10 -> " << HitungDurasi::formatWaktu(keluar2) << endl;
    cout << endl;

    // Test 4: Polimorfisme Diskon*
    cout << "Test 4: Polimorfisme Diskon*" << endl;
    cout << "----------------------------" << endl;

    unique_ptr<Diskon> diskon1 = make_unique<TanpaDiskon>();
    unique_ptr<Diskon> diskon2 = make_unique<DiskonMember>();

    int tarifAsli = 10000;
    cout << "Tarif asli: Rp" << tarifAsli << endl;
    cout << diskon1->getNama() << ": Rp" << diskon1->terapkanDiskon(tarifAsli) << endl;
    cout << diskon2->getNama() << ": Rp" << diskon2->terapkanDiskon(tarifAsli) << endl;
    cout << endl;

    // Test 5: Skenario lengkap - Motor + Diskon
    cout << "Test 5: Skenario Lengkap (Motor + Diskon)" << endl;
    cout << "------------------------------------------" << endl;

    Motor motor("B 1234 XYZ");
    int tarifMotor = motor.hitungTarif(3); // 3 jam: 2000 + 2*1000 = 4000
    cout << "Motor 3 jam: Rp" << tarifMotor << " (2000 + 2x1000)" << endl;
    cout << "  " << tanpaDiskon.getNama() << ": Rp" << tanpaDiskon.terapkanDiskon(tarifMotor) << endl;
    cout << "  " << diskonMember.getNama() << ": Rp" << diskonMember.terapkanDiskon(tarifMotor) << endl;
    cout << "  (4.000 - 20% = Rp3.200)" << endl;
    cout << endl;

    // Test 6: Array polimorfik Diskon*
    cout << "Test 6: Array Polimorfik Diskon*" << endl;
    cout << "--------------------------------" << endl;

    vector<unique_ptr<Diskon>> daftarDiskon;
    daftarDiskon.push_back(make_unique<TanpaDiskon>());
    daftarDiskon.push_back(make_unique<DiskonMember>());

    for (size_t i = 0; i < daftarDiskon.size(); i++) {
        const auto& d = daftarDiskon[i];
        cout << (i + 1) << ". " << d->getNama()
             << " - Tarif Rp10.000 -> Rp" << d->terapkanDiskon(10000) << endl;
    }
    cout << endl;

    cout << "=== SEMUA TEST BAGIAN 3 SELESAI ===" << endl;

    return 0;
}
