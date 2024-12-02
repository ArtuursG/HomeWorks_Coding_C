// B - programma
// ABC CBA
// A = 1 - 9, 9 jo 0 nevar būtt pirmais cipars
// B = 0 - 10, kopā 10 iespējas
// C = 0 - 10, kopā 10 iespējas
// 9 x 10 x 10 = 900 iespējamas 6-ciparu kombinācijas.

#include <iostream>
using namespace std;

int main() {
    int n = 0;

    for (int i = 100; i <= 999; i++) { //Atrod visus 3-ciparu skaitļus sākot ar 100 un beidzot ar 999
            int abc = i; //3-ciparu skaitlis
            int cba = (i % 10) * 100 + ((i / 10) % 10) * 10 + (i / 100); //ABC. C = simti (CBA), B = desmiti (BA), A = vieni (A)

            int palindroms = abc * 1000 + cba; //123*1000 = 123000; 123000 + 321 = 123321
            

            cout << palindroms << " | ";

            n++;
        }

    
    cout << "\nKopaa 6-ciparu palindromi ir: " << n << endl; //Kopējais n (Palindromu) skaits

    system("pause");
    return 0;
    
}