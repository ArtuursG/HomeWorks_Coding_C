// https://www.w3schools.com/cpp/cpp_classes.asp - klases

#ifndef SWORD_H
#define SWORD_H

#include <iostream>
using namespace std;

class Sword {
    private:
        int weight;
        int quality;

    public:
        Sword(int w, int q);    // konstruktors, uzdod laukus weight un quality;
        int Damage();           // atgriež bojājumu daudzumu weight*quality;
        void WearAndTear();     // ieroča nolietojums, samazina quality par 1;
        void Sharpen();         // palielina quality par 2;
        int GetWeight() const;  // atgriež weight;
        int GetQuality() const; // atgriež quality;
};

#endif