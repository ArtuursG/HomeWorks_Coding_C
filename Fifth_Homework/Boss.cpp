#include "Boss.h"
#include <iostream>
using namespace std;

// Mantošana no Character -> Monster -> Boss
Boss::Boss(string n, int l, int s, int sw_weight, int sw_quality, int sh_size, int sh_protection, int lvl, int h)
    : Monster(n, l, s, sw_weight, sw_quality, sh_size, sh_protection, lvl), heads(h) {}

// Atgriež Boss head skaitu
int Boss::GetHeads() const {
    return heads;
}

void Boss::Eat(Hero& h) {
    AddLife(h.GetLife()); // palielina boss dzīvību par hero dzīvību
    heads += 1;           // + vēl viena galva
    h.SetLife(0);         // Hero 0hp
}

void Boss::Print() {
    Monster::Print();     // Tiek pārņemta izvade no Monster un Character
    cout << "Heads: " << heads << endl;
}