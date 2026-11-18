#include "TanpaDiskon.h"

/**
 * Implementasi terapkanDiskon - tidak ada potongan
 * Mengembalikan tarif asli tanpa perubahan
 */
int TanpaDiskon::terapkanDiskon(int tarifAsli) const {
    return tarifAsli;
}

/**
 * Implementasi getNama - nama strategi "Tanpa Diskon"
 */
std::string TanpaDiskon::getNama() const {
    return "Tanpa Diskon";
}
