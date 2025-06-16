// https://www.w3schools.com/cpp/cpp_inheritance.asp
// https://www.geeksforgeeks.org/function-overriding-in-cpp/

#ifndef BOSS_H
#define BOSS_H

#include "Monster.h"
#include "Hero.h"

// Boss klase ir Monster apakšklase, kurai pievienots heads
class Boss : public Monster {
private:
    int heads; // Bosa galvu skaits

public:

    // Konstruktors – papildus Monster laukiem klāt nāk galvu skaits
    Boss(string n, int l, int s, int sw_weight, int sw_quality, int sh_size, int sh_protection, int lvl, int h);

    int GetHeads() const;      // Atgriež galvu skaitu
    void Eat(Hero& h);         // Apēd Hero: paņem dzīvību, palielina dzīvības Bosam un palielina heads (by reference)
    void Print() override;     // Izvada arī heads, kopā ar citu informāciju
};

#endif