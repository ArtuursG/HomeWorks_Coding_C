#include "Sword.h"

using namespace std;

// https://www.w3schools.com/cpp/cpp_constructors.asp - konstruktors
// Konstruktors: inicializē svaru un kvalitāti atbilstošās robežās
Sword::Sword(int w, int q) {
    if (w < 2) {
        weight = 2;
    } else if (w > 5) {
        weight = 5;
    } else {
        weight = w;
    }

    if (q < 1) {
        quality = 1;
    } else if (q > 6) {
        quality = 6;
    } else {
        quality = q;
    }
}


// Bojājumu aprēķins (svars * kvalitāte) un nolietojuma piemērošana
int Sword::Damage() {
    int damage = weight * quality;
    WearAndTear(); // Piemēro nolietojumu pēc bojājumu nodarīšanas
    return damage;
}

// Nolietojums: samazina kvalitāti, bet ne zemāk par 1
void Sword::WearAndTear() {
    if (quality > 1) {
        quality--;
    }
}

// Asināšana: palielina kvalitāti, bet ne augstāk par 6
void Sword::Sharpen() {
    if (quality < 6) {
        quality += 2;
        if (quality > 6) {
        quality = 6; // Nodrošina, ka nepārsniedz maksimālo vērtību
        }
    }
}

// Getteri | https://www.w3schools.com/cpp/cpp_encapsulation.asp
int Sword::GetWeight() const {
    return weight;
}

int Sword::GetQuality() const {
    return quality;
}