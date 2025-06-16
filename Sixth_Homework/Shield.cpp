#include "Shield.h"

// https://www.w3schools.com/cpp/cpp_constructors.asp - konstruktors
// Konstruktors: inicializē izmēru un aizsardzību atbilstošās robežās
Shield::Shield(int s, int p) {
    if (s < 0) {
        size = 0;
    } else if (s > 4) {
        size = 4;
    } else {
        size = s;
    }

    if (p < 1) {
        protection = 1;
    } else if (p > 5) {
        protection = 5;
    } else {
        protection = p;
    }
}

// Bloķēšanas aprēķins (izmērs * aizsardzība) un piemēro bojājumus
int Shield::Block() {
    int blockValue = size * protection;
    Destruction(); // Piemēro bojājumus pēc bloķēšanas
    return blockValue;
}

// Bojājumi: samazina izmēru, bet ne zemāk par 0
void Shield::Destruction() {
    if (size > 0) {
        size--;
    }
}

// Remonts: palielina izmēru, bet ne augstāk par 4
void Shield::Repair() {
    if (size < 4) {
        size += 2;
        if (size > 4) {
            size = 4; // Nodrošina, ka nepārsniedz maksimālo vērtību
        }
    }
}

// Getteri | https://www.w3schools.com/cpp/cpp_encapsulation.asp
int Shield::GetSize() const {
    return size;
}

int Shield::GetProtection() const {
    return protection;
}