#include "HitungDurasi.h"
#include <ctime>

/**
 * Implementasi hitungJam
 * Formula:
 * 1. Hitung selisih detik antara keluar dan masuk
 * 2. Konversi ke menit (detik / 60)
 * 3. Pembulatan ke atas: (menit + 59) / 60
 * 4. Minimal 1 jam (sesuai PRD)
 *
 * Contoh:
 * - 45 menit -> (45 + 59) / 60 = 1 jam
 * - 190 menit (3 jam 10 menit) -> (190 + 59) / 60 = 4 jam
 */
int HitungDurasi::hitungJam(std::time_t masuk, std::time_t keluar) {
    int detik = static_cast<int>(keluar - masuk);
    int menit = detik / 60;
    int jam = (menit + 59) / 60; // Pembulatan ke atas
    if (jam < 1) jam = 1; // Minimal 1 jam
    return jam;
}

/**
 * Implementasi formatWaktu
 * Mengubah time_t menjadi string format "HH:MM:SS"
 */
std::string HitungDurasi::formatWaktu(std::time_t waktu) {
    std::tm* tm_info = std::localtime(&waktu);
    char buffer[9]; // "HH:MM:SS" + null terminator
    std::strftime(buffer, sizeof(buffer), "%H:%M:%S", tm_info);
    return std::string(buffer);
}
