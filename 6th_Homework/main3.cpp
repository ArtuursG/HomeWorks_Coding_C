#include <iostream>
#include "Character.h"
#include "Queue.h"

using namespace std;

int main() {
    Queue<Character> CharacterQueue; // Izveido tukšu rindu, kurā glabās Character objektus

    // Pievieno 10 Character objektus rindai (FIFO princips) 
    // https://www.geeksforgeeks.org/fifo-first-in-first-out-approach-in-programming/
    for (int i = 0; i < 10; i++) {
        Character ch("Char" + to_string(i + 1), 100 - i * 5, 10 + i); // Katra objekta dzīvība samazinās par 5, spēks palielinās pa 1
        CharacterQueue.enqueue(ch);
    }

    cout << "\n Sākotnējā rinda " << endl;
    CharacterQueue.PrintQueue();

    cout << "\n Sakārtota rinda (pēc life + strength) " << endl;
    CharacterQueue.Sort();
    CharacterQueue.PrintQueue();

    // Izņem 5 pirmos (vecākos) elementus no rindas
    cout << "\n Pēc 5x izņemšanām " << endl;
    for (int i = 0; i < 5; i++) {
        CharacterQueue.dequeue(); // Noņem no rindas sākuma
    }
    CharacterQueue.PrintQueue(); // Izvada atlikušo rindu

    return 0;
}
