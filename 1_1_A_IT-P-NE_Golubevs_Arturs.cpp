// A - programma

#include <iostream>
using namespace std;

bool palindroms(const string& n)  //Funkcija, kas pārbauda vai ievadītā vērtība ir Palindroms. const string& - https://www.quora.com/What-does-const-string-in-C++-mean
{
    int length = n.size(); //aprēķina virknes garumu
    for (int i = 0; i < length / 2; i++) //Pārbauda tikai ABC, jo palindroms sastāv no ABC CBA
    {
        if (n[i] != n[length - i - 1]) //Salīdzina palindroma sākumu (ABC) un beigas (CBA)
        {
            return false; //Ja ACB != CBA, tad false, jo tas nav palindroms
        }
    }
    return true; //Ja ACB == CBA, tad true, jo ir palindroms
}

int main() {
    string n;
    cout << "Ievadiet ciparu: "; //123321, 456654, 789987, 101101, 654456, 121
    cin >> n;

    if (palindroms(n)) 
    {
        cout <<"Ievaditais numurs - " << n << ", ir palindroms!\n";
    } else 
    {
        cout << "Ievaditais numurs - " << n <<", nav palindroms!\n";
    }

    system("pause");
    return 0;
    
}
