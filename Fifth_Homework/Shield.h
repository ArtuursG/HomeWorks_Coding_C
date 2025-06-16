// https://www.w3schools.com/cpp/cpp_classes.asp - klases

#ifndef SHIELD_H
#define SHIELD_H

#include <iostream>
using namespace std;

class Shield {
private:
    int size;
    int protection;

public:
    Shield(int s, int p);       // konstruktors, uzdod laukus size un protection;
    int Block();                // atgriež aizsardzības daudzumu size*protection;
    void Destruction();         // vairoga bojājumi (tiek nocirsti gabali), samazina size par 1;
    void Repair();              // palielina size par 2; 
    int GetSize() const;        // atgriež size;
    int GetProtection() const;  // atgriež protection;
};

#endif