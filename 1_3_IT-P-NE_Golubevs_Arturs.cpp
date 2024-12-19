#include <iostream>
using namespace std;

int main() {
    int small = 1; //analogs "sākums"
    int big = 100; //analogs "beigas"
    int meginajums = 10;
    char storage; //Ievadīto vērtību glabātuve https://www.guru99.com/cpp-char.html?gpp / https://www.educative.io/answers/how-to-accept-a-character-input-in-cpp

    for (int i = 1; i <= meginajums; i++) {
        int minejums = (small + big) / 2; //Vidējā vērtības starp small un big
        cout << "Meeginajums Nr. " << i << ": Vai tas ir " << minejums << "? ('+' ja lielaaks, '-' ja mazaaks, 'w' ja pareizi):"<< endl;
        cin >> storage; //Lietotāja izvēle tiek saglabāta glabātuvē

        if (storage == 'w') { //w = for WIN
            cout << "Cipars ir uzmineets " << i << " meeginaajumos!" << endl;
            return 0; //Pārtrauc programmu, jo skaitlis uzminēts
        } else if (storage == '+') { //"+" = lielāks
            small = minejums + 1;
        } else if (storage == '-') { // "-" = mazāks
            big = minejums - 1;
        }
    }
    
    cout << "Nevareeju uzmineet Tevis izveeleeto ciparu :(((" << endl; //Ja meginajums == 10

    system("pause");
    return 0;
}