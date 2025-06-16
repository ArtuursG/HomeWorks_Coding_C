// https://www.w3schools.com/cpp/cpp_classes.asp - klases
// https://www.geeksforgeeks.org/virtual-function-cpp/ - virtual

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <cstring> // char path[10]; memset, sizeof etc.
#include "Sword.h"
#include "Shield.h"

using namespace std;

class Character {
private:
    string name;
    int life;
    int strength;
    char path[10]; // maršruts, saglabā pēdējos 10 iešanas virzienus ( w-forward, s-backward, a-left, d-right);
    Sword sw;
    Shield sh;

public:
    Character(string n, int l, int s, int sw_weight, int sw_quality, int sh_size, int sh_protection); // konstruktors, inicializē name un life, un sw, sh parametrus;
    bool Hit(int damage);       // samazina personāža dzīvi par parametra vērtību, atgriež vai personāžs ir dzīvs;
    int Attack();               // aprēķina un atgriež uzbrukuma spēku pēc formulas strength+sw.Damage();
    int Defence();              // aprēķina un atgriež aizsardzības spēku pēc formulas strength/2+sh.Block();
    int GetLife() const;        // atgriež personāža dzīves daudzumu;
    void Go(char direction);    // pievieno iešanas virzienu;
    
    // 2. MD
    virtual void Print();       
    void SetLife(int l) { life = l; } // 2. uzd. iestata jaunu dzīvību
    void AddLife(int l) { life += l; } // 2. uzd. palielina dzīvību
    
    // void Print();               // izvada vārdu, dzīvs (tad izvada arī dzīves punktu skaitu), vai miris, maršrutu, informāciju par vairogu un zobenu.
    ~Character();               // destruktors, izvada ziņojumu “Game over for name”;
    string GetName() const { return name; } // Iegūst vārdu;


};

#endif