// https://www.w3schools.com/cpp/cpp_inheritance.asp
// https://www.geeksforgeeks.org/function-overriding-in-cpp/

#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"

// Monster klase ir Character apakšklase, kurai pievienots levels
class Monster : public Character {
protected:
    int level;

public:
    // Konstruktors – pie Character laukiem klāt nāk arī līmenis
    Monster(string n, int l, int s, int sw_weight, int sw_quality, int sh_size, int sh_protection, int lvl);

    int GetLevel() const;   // Funkcija, kas atgriež līmeni
    void Print() override;  // Pārraksta Print funkciju un izvada arī monstera līmeni
};

#endif