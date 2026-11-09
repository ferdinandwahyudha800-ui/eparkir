#ifndef KENDARAAN_H
#define KENDARAAN_H

#include <string>
#include <chrono>

// Enum untuk ukuran slot parkir
enum class UkuranSlot {
    KECIL,
    SEDANG,
    BESAR
};

// Kelas abstrak Kendaraan - mendemonstrasikan ABSTRAKSI
class Kendaraan {
protected:
    std::string platNomor;
    std::string pemilik;

public:
    // Constructor
    Kendaraan(const std::string& plat, const std::string& nama);
    
    // Destruktor virtual - wajib untuk kelas polimorfik
    virtual ~Kendaraan() = default;
    
    // Method getter
    std::string getPlatNomor() const;
    std::string getPemilik() const;
    
    // Method virtual murni - harus diimplementasi oleh kelas turunan (POLIMORFISME)
    virtual int hitungTarif(int durasiJam) const = 0;
    virtual UkuranSlot ukuranSlotMinimum() const = 0;
    virtual std::string jenisKendaraan() const = 0;
};

#endif // KENDARAAN_H
