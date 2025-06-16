// https://www.geeksforgeeks.org/function-overriding-in-cpp/ - override
// https://www.w3schools.com/cpp/cpp_inheritance.asp 

#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Monster.h"

// Here ir Character apakšklase, kurai pievienots experience
class Hero : public Character {
private:
    int experience;

public:
    // Konstruktors - pie Character laukiem klāt nāk arī experience
    Hero(string n, int l, int s, int sw_weight, int sw_quality, int sh_size, int sh_protection, int exp = 0);

    void Kill(Monster& m);     // Kill funkcija – palielina experience par monster dzīvība * līmenis un samazina monster dzīvību līdz 0 (by reference)
    void Print() override;     // Parāda visu info. Pārraksta (override) Character Print funkciju un papildus izvada experience 
};

#endif