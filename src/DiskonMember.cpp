#include "DiskonMember.h"

/**
 * Implementasi terapkanDiskon - potongan 20% untuk member
 * Formula: tarifAsli * (100 - PERSENTASE_DISKON) / 100
 * Contoh: Rp10.000 -> Rp10.000 - (10.000 * 20 / 100) = Rp8.000
 */
int DiskonMember::terapkanDiskon(int tarifAsli) const {
    int potongan = tarifAsli * PERSENTASE_DISKON / 100;
    return tarifAsli - potongan;
}

/**
 * Implementasi getNama - nama strategi "Diskon Member 20%"
 */
std::string DiskonMember::getNama() const {
    return "Diskon Member 20%";
}
