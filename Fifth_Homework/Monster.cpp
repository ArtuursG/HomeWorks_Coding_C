#include "Monster.h"
#include <iostream>
using namespace std;

// Tiek izsaukta Character klase un papildina ar Monster level lauku. Monster manto visu Character un pievieno level
Monster::Monster(string n, int l, int s, int sw_weight, int sw_quality, int sh_size, int sh_protection, int lvl)
    : Character(n, l, s, sw_weight, sw_quality, sh_size, sh_protection), level(lvl) {}

// Atgriež Monster level
int Monster::GetLevel() const { // const nemaina objektu
    return level;
}

void Monster::Print() {
    Character::Print();                 // Izvada name, life, route, sword, shield
    cout << "Level: " << level << endl; // Izvada level
}