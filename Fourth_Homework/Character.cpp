#include "Character.h"

// https://www.w3schools.com/cpp/cpp_constructors.asp - konstruktors
// Konstruktors: inicializē vārdu, dzīvību, spēku, zobenu un vairogu
Character::Character(string n, int l, int s, int sw_weight, int sw_quality, int sh_size, int sh_protection)
    : name(n), life((l > 0) ? l : 1), strength(s), sw(sw_weight, sw_quality), sh(sh_size, sh_protection) { // Pielieto inicializācijas sarakstu
    
        // Inicializē maršrutu ar '-'
    for (int i = 0; i < 10; i++) {
        path[i] = '-';
    }
}


// Samazina dzīvību pēc trāpījuma, atgriež vai personāžs ir dzīvs
bool Character::Hit(int damage) {
    if (life > 0) {
        life -= damage;
        if (life < 0) life = 0; // Nodrošina, ka dzīvības vērtība nekļūst negatīva
    }
    return life > 0;
}

// Aprēķina uzbrukuma spēku
int Character::Attack() {
    if (life > 0) {
        return strength + sw.Damage();
    }
    return 0; // Miruši personāži nevar uzbrukt
}

// Aprēķina aizsardzību
int Character::Defence() {
    if (life > 0) {
        return (strength / 2) + sh.Block();
    }
    return 0; // Miruši personāži nevar aizsargāties
}

// Iegūst dzīvības punktus
int Character::GetLife() const {
    return life;
}

// Saglabā kustības virzienu (derīgi tikai w, s, a, d)
void Character::Go(char direction) {
    if (life > 0 && (direction == 'w' || direction == 's' || direction == 'a' || direction == 'd')) {
        for (int i = 8; i >= 0; i--) {
            path[i + 1] = path[i];
        }
        path[0] = direction;
    }
}

// Izvada informāciju par personāžu
void Character::Print() {
    cout << "Name: " << name << endl;

    if (life > 0) {
        cout << "Status: Alive (" << life << " HP)" << endl;
    } else {
        cout << "Status: Dead" << endl;
    }

    cout << "Path: ";
    for (char c : path) {
        cout << c;
    }
    cout << endl;

    cout << "Sword - Weight: " << sw.GetWeight() << ", Quality: " << sw.GetQuality() << endl;
    cout << "Shield - Size: " << sh.GetSize() << ", Protection: " << sh.GetProtection() << endl;
}


// Destruktora ziņojums
Character::~Character() {
    cout << "Game over for " << name << endl;
}