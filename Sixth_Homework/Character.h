// https://www.w3schools.com/cpp/cpp_classes.asp - klases
// https://www.geeksforgeeks.org/virtual-function-cpp/ - virtual

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <cstring> // char path[10] manipulācijām; memset, sizeof etc.
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
    // Konstruktors ar noklusētām vērtībām (3. MD)
    Character(string n = "Default", int l = 100, int s = 10, int sw_weight = 3, int sw_quality = 5, int sh_size = 2, int sh_protection = 3);

    // Galvenās metodes no 1. un 2. MD
    bool Hit(int damage);
    int Attack();
    int Defence();
    int GetLife() const;
    void Go(char direction);
    //virtual void Print();
    //void SetLife(int l) { life = l; }
    //void AddLife(int l) { life += l; }
    //string GetName() const { return name; }
    void SetLife(int l);
    void AddLife(int l);
    string GetName() const;
    virtual void Print();      // Virtuāla — tiks pārdefinēta Hero/Monster/Boss klasēs
    ~Character();              // Destruktors

    // Operatoru pārslogošana (3. MD)
    Character& operator=(const Character& other);                   // Ievade
    friend istream& operator>>(istream& in, Character& ch);         // Izvade
    friend ostream& operator<<(ostream& out, const Character& ch);  // Piešķiršana
    Character& operator++();    // Prefix ++
    Character operator++(int);  // Postfix ++
    Character& operator--();    // Prefix --
    Character operator--(int);  // Postfix --

    // Salīdzināšana pēc life * strength
    bool operator<(const Character& other) const;
    bool operator>(const Character& other) const;
    bool operator<=(const Character& other) const;
    bool operator>=(const Character& other) const;
    bool operator==(const Character& other) const;
    bool operator!=(const Character& other) const;

    //~Character();
};

#endif