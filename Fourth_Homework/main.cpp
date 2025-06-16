#include <iostream>
#include "Sword.h"
#include "Shield.h"
#include "Character.h"

using namespace std;

// Funkcija, kas simulē cīņu starp diviem personāžiem
bool Fight(Character &ch1, Character &ch2) {
    if (ch1.GetLife() <= 0 || ch2.GetLife() <= 0) {
        return false; // Ja kāds no personāžiem jau ir miris, atgriež false
    }

    int attackPower = ch1.Attack();
    int defensePower = ch2.Defence();
    int damage = attackPower - defensePower;

    if (damage > 0) {
        ch2.Hit(damage); // Piemēro bojājumus tikai tad, ja uzbrukums ir spēcīgāks par aizsardzību
    }

    return true;
}

int main() {

    // Izveido divus testa personāžus
    Character hero("Arthur", 100, 8, 3, 5, 2, 4);
    Character enemy("Goblin", 50, 5, 2, 3, 1, 2);

    // Kustina personāžus
    // <10 kustības personāžam
    hero.Go('w');
    hero.Go('d');
    hero.Go('a');
    hero.Go('s');

    for (int i = 0; i < 12; i++) { // >10 kustības ienaidniekam
        enemy.Go('s');
    }

    // Cīņa līdz viens personāžs mirst
    while (Fight(hero, enemy)) {} // Tukšs loop: https://softwareengineering.stackexchange.com/questions/419445/is-an-empty-while-loop-bad-practice

    hero.Print();
    enemy.Print();

    // Mēģina uzbrukt un veikt kustību mirušam personāžam
    if (enemy.GetLife() > 0) {
        enemy.Hit(10);  // Iesit tikai tad, ja personāžs ir dzīvs
        enemy.Go('w');  // Kustās tikai tad, ja personāžs ir dzīvs
    } else {
        cout << enemy.GetName() << " is dead and cannot take actions." << endl;
    }

    return 0;
}
