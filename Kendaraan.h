#ifndef KENDARAAN_H
#define KENDARAAN_H

#include <string>
#include <map>
#include <vector>
#include <memory>

/**
 * Enum untuk ukuran slot parkir
 */
enum class UkuranSlot {
    KECIL,
    SEDANG,
    BESAR
};

/**
 * Kelas abstrak Kendaraan - mendemonstrasikan ABSTRAKSI
 * Menyediakan interface umum untuk semua jenis kendaraan
 */
class Kendaraan {
protected:
    std::string platNomor;
    std::string jenisKendaraan;
    
    // DICTIONARY - menyimpan properti tambahan kendaraan (metadata)
    // Contoh: warna, tahun, pemilik, catatan khusus, dll
    std::map<std::string, std::string> propertiTambahan;

public:
    /**
     * Constructor
     * @param plat Nomor plat kendaraan
     * @param jenis Jenis kendaraan (Motor/Mobil/Truk)
     */
    Kendaraan(const std::string& plat, const std::string& jenis);
    
    /**
     * Virtual destructor - PENTING untuk polimorfisme
     * Memastikan destructor kelas turunan dipanggil dengan benar
     */
    virtual ~Kendaraan() = default;

    /**
     * Method virtual murni - menghitung tarif parkir
     * Setiap kendaraan punya aturan tarif berbeda
     * @param durasiJam Durasi parkir dalam jam (sudah dibulatkan ke atas)
     * @return Total tarif dalam Rupiah
     */
    virtual int hitungTarif(int durasiJam) const = 0;

    /**
     * Method virtual murni - menentukan ukuran slot minimum
     * @return Ukuran slot yang dibutuhkan
     */
    virtual UkuranSlot ukuranSlotMinimum() const = 0;

    // ========================================
    // GETTER - Sudah ada sebelumnya
    // ========================================
    
    /**
     * Getter untuk plat nomor
     */
    std::string getPlatNomor() const;

    /**
     * Getter untuk jenis kendaraan
     */
    std::string getJenisKendaraan() const;

    // ========================================
    // SETTER - Menambahkan kemampuan mengubah data
    // ========================================
    
    /**
     * Setter untuk plat nomor (jika ada perubahan plat)
     * @param plat Nomor plat baru
     */
    void setPlatNomor(const std::string& plat);
    
    /**
     * Setter untuk jenis kendaraan
     * @param jenis Jenis kendaraan baru
     */
    void setJenisKendaraan(const std::string& jenis);

    // ========================================
    // DICTIONARY - Method untuk kelola properti tambahan
    // ========================================
    
    /**
     * Menambah/update properti tambahan kendaraan
     * @param key Nama properti (contoh: "warna", "tahun", "pemilik")
     * @param value Nilai properti
     */
    void setProperti(const std::string& key, const std::string& value);
    
    /**
     * Mendapatkan nilai properti tambahan
     * @param key Nama properti
     * @return Nilai properti (string kosong jika tidak ada)
     */
    std::string getProperti(const std::string& key) const;
    
    /**
     * Mengecek apakah properti tertentu ada
     * @param key Nama properti
     * @return true jika properti ada
     */
    bool hasProperti(const std::string& key) const;
    
    /**
     * Mendapatkan semua properti tambahan
     * @return Map semua properti
     */
    std::map<std::string, std::string> getAllProperti() const;
    
    /**
     * Menghapus properti tertentu
     * @param key Nama properti yang akan dihapus
     */
    void hapusProperti(const std::string& key);
};

// ========================================
// GENERIC/TEMPLATE - Fungsi utilitas fleksibel
// ========================================

/**
 * Template function untuk menghitung total tarif dari koleksi kendaraan
 * GENERIC: Bisa digunakan untuk vector, list, atau container apapun
 * @param container Koleksi kendaraan (vector, list, dll)
 * @param durasiJam Durasi parkir
 * @return Total tarif semua kendaraan
 */
template<typename Container>
int hitungTotalTarif(const Container& container, int durasiJam) {
    int total = 0;
    for (const auto& kendaraan : container) {
        if (kendaraan) {  // Cek pointer tidak null
            total += kendaraan->hitungTarif(durasiJam);
        }
    }
    return total;
}

/**
 * Template function untuk filter kendaraan berdasarkan kriteria
 * GENERIC: Bisa filter dengan kondisi apapun
 * @param container Koleksi kendaraan
 * @param predicate Fungsi/lambda untuk filter
 * @return Vector kendaraan yang memenuhi kriteria
 */
template<typename T, typename Predicate>
std::vector<T> filterKendaraan(const std::vector<T>& container, Predicate predicate) {
    std::vector<T> hasil;
    for (const auto& item : container) {
        if (predicate(item)) {
            hasil.push_back(item);
        }
    }
    return hasil;
}

/**
 * Template function untuk menghitung rata-rata tarif
 * GENERIC: Fleksibel untuk berbagai tipe container
 * @param container Koleksi kendaraan
 * @param durasiJam Durasi parkir
 * @return Rata-rata tarif (0 jika container kosong)
 */
template<typename Container>
double hitungRataRataTarif(const Container& container, int durasiJam) {
    if (container.empty()) return 0.0;
    
    int total = hitungTotalTarif(container, durasiJam);
    return static_cast<double>(total) / container.size();
}

#endif // KENDARAAN_H
