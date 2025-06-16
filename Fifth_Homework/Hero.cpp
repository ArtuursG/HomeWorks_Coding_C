#include "Hero.h"
#include <iostream>
using namespace std;

Hero::Hero(string n, int l, int s, int sw_weight, int sw_quality, int sh_size, int sh_protection, int exp) // name, life, strenght, sword weight, sword quality, shield size, shield def, exp - no Hero obj.
    : Character(n, l, s, sw_weight, sw_quality, sh_size, sh_protection), experience(exp) {} // Tiek izsaukts Character konstruktors *laikam. 

void Hero::Kill(Monster& m) {                 // & = reference jeb atsauce (esošs objekts) un m = mainīgais, kas tiek izmantots funkcijā
    experience += m.GetLife() * m.GetLevel(); // experience += dzīvība * līmenis
    m.SetLife(0);                             // Monster dead 0hp
}

// Izvada visu par Character + Hero exp.
void Hero::Print() {
    Character::Print(); // Mantots no Character klases
    cout << "Experience: " << experience << endl;
}