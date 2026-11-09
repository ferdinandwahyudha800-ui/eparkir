#ifndef KENDARAAN_H
#define KENDARAAN_H

#include <string>

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

    /**
     * Getter untuk plat nomor
     */
    std::string getPlatNomor() const;

    /**
     * Getter untuk jenis kendaraan
     */
    std::string getJenisKendaraan() const;
};

#endif // KENDARAAN_H
