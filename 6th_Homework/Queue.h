#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

// Rindas (Queue) šablons (FIFO — First In, First Out)
template <typename T> // Šablona klase, kas strādā ar jebkāda veida datiem
class Queue {
private:
    T data[100];     // Masīvs, kurā glabā elementus (maksimums 100 vienības)
    int front;
    int rear;
    int count;

public:
    Queue() : front(0), rear(0), count(0) {} // Konstruktors: inicializē tukšu rindu

    // Pievieno elementu rindas beigās
    void enqueue(const T& x) {
        if (count < 100) {              // Pārbauda vai rinda nav pilna, 
            data[rear++] = x;           // Ieliek elementu un palielina rear indeksu,
            count++;                    // Palielina elementu skaitu
        } else {
            cout << "Queue is full!" << endl;
        }
    }

    // dequeue(): noņem elementu no rindas sākuma
    void dequeue() {
    if (count > 1) { 
        front += 2;
        count -= 2;
    } else if (count == 1) {
        front++;
        count--;
    } else {
        cout << "Queue is empty!" << endl;
    }
}

    // PrintQueue(): izvada visus rindas elementus
    void PrintQueue() const {
        for (int i = front; i < rear; i++) {
            cout << "[" << i - front + 1 << "] "; // Numurēšana sākas no 1
            cout << data[i] << endl;              // Izvade izmanto pārslogoto `<<
        }
    }

    // Sort(): sakārto rindas elementus pēc operatora `<`
    void Sort() {
        for (int i = front; i < rear - 1; i++) {
            for (int j = i + 1; j < rear; j++) {
                if (data[j] < data[i]) {
                    swap(data[i], data[j]);     // Samainām vietām, ja nav pareizā secībā
                }
            }
        }
    }
};

#endif
