#include <iostream>
#include <cstdlib> //Priekš funkcijas rand()

using namespace std;

int main() {
    int n = rand() % 101; // 0 - 100
    int input;
    int meginajums = 0;

    while (meginajums < 10) {
        cout << "Meeginaajums Nr. " << meginajums + 1 << ": "; //meginajums + 1, skaita meginajumu skaitu un attēlo tos
        cin >> input;
        meginajums++; //Šeit katru reizi meginajums (int meginajums = 0;) tiek palielinats ar meginajums = meginajums + 1

        if (n > input) {
            cout << "Skaitlis ir LIELAAKS par ievadiito!" << endl;
        } else if (n < input) {
            cout << "Skaitlis ir MAZAAKS par ievadiito!" << endl;
        } else { // ja nav n > input un nav n < input, tad noteikti ir n == input
            cout << "Skaitlis uzminets no " << meginajums << ". meeginaajuma!" << endl;
            break; //iziet no cilpas un izpilda zemāk esošo bloku
        }
    }

    if (meginajums == 10) {
        cout << "Jus zaudeejaat! Pareizaa atbilde ir: " << n << " !!!" << endl;
    }

    system("pause");
    return 0;
}