#include <iostream>
#include <ctime>
#include <cstdlib> // rand, srand. Rand() bez srand() ģenerēs vienus un tos pašus skaitļus katru reizi.
#include "Hero.h"
#include "Monster.h"
#include "Boss.h"

using namespace std;

// Funkcija, kas ģenerē nejaušu virzienu [w, s, a, d]
char randomDirection() {
    char options[] = { 'w', 's', 'a', 'd' };
    return options[rand() % 4];
}

int main() {
    srand(time(0)); //  inicializē nejaušo skaitļu ģeneratoru

    // Izveidots viens objekts no katras klases
    Hero h("Hero1", 100, 10, 3, 5, 3, 4);           // (name, life, strength, sword weight, sword quality, shield size, shield protection) + experience = 0
    Monster m("Monster1", 60, 7, 2, 4, 2, 3, 2);    // (name, life, strength, sword weight, sword quality, shield size, shield protection) + level = 2
    Boss b("Boss1", 150, 12, 4, 6, 4, 5, 5, 1);     // (name, life, strength, sword weight, sword quality, shield size, shield protection) + level = 5 (Monster) un heads = 1 (Boss)


    // Izvada sākotnējo stāvokli
    cout << "\n Sākotnējais stāvoklis: " << endl;
    h.Print(); // info par Hero. Character + exp
    m.Print(); // infor par Monster. Character + lvl
    b.Print(); // info par Boss Character + lvl + heads

    // Hero nogalina Monster, Boss apēd Hero
    h.Kill(m); // Hero nogalina Monster. Iegūst pieredzi, monster zaudē dzīvību.
    b.Eat(h);  // Boss "apēd" Hero. Iegūst viņa dzīvību, palielina heads.

    // Izvada stāvokli pēc Kill un Eat darbībām
    cout << "\n Pēc KILL un EAT: " << endl;
    h.Print(); // Izvada info par Hero (name, life, exp, route...)
    m.Print(); // Izvada info par Monster (life un lvl)
    b.Print(); // Izvada info par Boss (life, lvl un heads)

    // Izveido Character pointeru masīvu ar 9 dažādiem objektiem (testam) (mantošana + polimorfisms)
    Character* characters[9] = {
        new Hero("H1", 100, 10, 3, 5, 2, 3),
        new Hero("H2", 90, 8, 2, 4, 1, 2),
        new Hero("H3", 110, 12, 4, 5, 3, 4),
        new Monster("M1", 60, 7, 2, 3, 2, 3, 2),
        new Monster("M2", 70, 6, 2, 4, 2, 2, 3),
        new Monster("M3", 65, 8, 3, 5, 3, 3, 4),
        new Boss("B1", 150, 12, 4, 6, 4, 5, 5, 2),
        new Boss("B2", 140, 11, 3, 5, 3, 4, 4, 1),
        new Boss("B3", 160, 13, 5, 6, 4, 5, 6, 3)
    };

    // Izvada visu 9 objektu sākotnējo stāvokli
    cout << "\n Visu 9 objektu sākotnējais stāvoklis: " << endl;
    for (int i = 0; i < 9; i++) {
        cout << "[" << i + 1 << "]" << endl; // no 1 līdz 9, nevis 0 līdz 8
        characters[i]->Print();
    }

    // 5 reizes katram objektam - pievieno nejaušu kustību un nejaušu triecienu (5–10)
    for (int step = 0; step < 5; step++) {
        for (int i = 0; i < 9; i++) {
            characters[i]->Go(randomDirection()); // No Character klases (w, s, a, d)
            characters[i]->Hit(rand() % 6 + 5); // nejaušs bojājums/trieciens 5–10. Piemēram, šādi: rand() % 6 -> skaitlis no 0 līdz 5 + 5 -> pārvērš to par 5 līdz 10
        }
    }

    // Izvada stāvokli pēc 5 iterācijām
    cout << "\n  Visi 9 objekti pēc 5 iterācijām: " << endl;
    for (int i = 0; i < 9; i++) {
        cout << "[" << i + 1 << "]" << endl;
        characters[i]->Print();
    }

    return 0;
}
