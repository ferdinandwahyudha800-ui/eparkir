#ifndef HITUNG_DURASI_H
#define HITUNG_DURASI_H

#include <ctime>
#include <string>

/**
 * Kelas utilitas HitungDurasi - helper untuk perhitungan durasi parkir
 * Menyediakan method static untuk menghitung durasi dan memformat waktu.
 * Tidak perlu diinstansiasi (semua method bersifat static).
 */
class HitungDurasi {
public:
    /**
     * Hitung durasi parkir dalam jam, dibulatkan ke atas
     * Minimal 1 jam (sesuai PRD).
     * Contoh: 30 menit = 1 jam, 3 jam 10 menit = 4 jam
     * @param masuk Waktu masuk parkir
     * @param keluar Waktu keluar parkir
     * @return Durasi dalam jam (minimal 1)
     */
    static int hitungJam(std::time_t masuk, std::time_t keluar);

    /**
     * Format waktu menjadi string yang dapat dibaca
     * @param waktu Waktu yang akan diformat
     * @return String waktu dalam format "HH:MM:SS"
     */
    static std::string formatWaktu(std::time_t waktu);
};

#endif // HITUNG_DURASI_H
