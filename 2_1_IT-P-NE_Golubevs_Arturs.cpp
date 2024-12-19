/* 
Uzdevums Nr. 1:
Ar gadījuma ģeneratora palīdzību aizpildiet divdimensiju masīvu NxN ar 
skaitļiem intervālā 10-99, un izvadiet to uz ekrānu. Pagrieziet masīvu uz 
90° pulksteņrādītāju virzienā. Izvadiet rezultātu uz ekrānu. 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>


int main(){

    /*
    srand: ģenerē nejaušus numurus, bet ja apvieno ar time, tad laiks ir 
    unikāls un katru reizi ģenerē unikālus nejaušus numurus.
    Avots: https://stackoverflow.com/questions/4736485/srandtime0-and-random-number-generation 
    */

    std::srand(std::time(0)); 

    int N;

    /*
    std::cout << "Ievadiet skaitli (2 vai 3), lai varetu uzgeneret matricu: ";
    std::cin >> N; Bet šeit bez pārbaude. 
    Respektīvi var ievadīt jebkādu skaitli un programma no tā veidos matricu. 
    */

    //Matricas (N*N) izveidei ierobežota N skaitļa izvēle
    while (true) {
        std::cout << "Ievadiet skaitli (2 vai 3), lai varetu uzgeneret (N*N) matricu: ";
        std::cin >> N;

        if (N >= 2 && N <= 3) {
            break;
        }

        std::cout << "Nepareiza ievade! Skaitlim ir jaabuut 2 vai 3.\n";
    }


    int matrix[N][N];



    /*
    Avots: https://prepinsta.com/cpp-program/rotate-a-matrix-by-90-degree-in-clockwise-direction/
    */

    //Matricas genereesana un izvade
    std::cout << "Uzegeneretaa matrica:\n";
    for (int i = 0; i < N; ++i) {                      //Iterē cauri katrai rindai matrix[i][N]
        for (int j = 0; j < N; ++j) {                  //Iterē cauri katrai rindai matrix[N][j]
            matrix[i][j] = rand() % (99 - 10 + 1) +10; //Ģenerē nejaušu skaitli no 10 līdz 99 un piemēro to matricai matrix[i][j]. Pēc noklusējuma rand(0, RAND_MAX). +10 = rand(10, 99). rand() % (max - min + 1) + min
            std::cout << matrix[i][j] << " ";          //Izdruka, atdala ar atstarpi
        }
        std::cout << "\n";                             //Katra rinda tiek izdrukāta jaunā rindā
    }


    std::cout << "\n";


    //Matricas pagriešana par 90 grādiem
    int matrix90[N][N];

    for (int i = 0; i < N; ++i) {                      //Iterē cauri katrai rindai matrix90[i][N]
        for (int j = 0; j < N; ++j) {                  //Iterē cauri katrai rindai matrix90[N][i]
            matrix90[j][N - 1 - i] = matrix[i][j];     //Savieno matrix[i][j] elementus ar matrix90[j][i] elementiem
        }
    }

    // Print the rotated matrix
    std::cout << "Matrica pagriesta par 90 grādiem: \n";
    for (int i = 0; i < N; ++i) {                      //Iterē cauri katrai pagrieztajai matrix90 i rindai
        for (int j = 0; j < N; ++j) {                  //Iterē cauri katrai pagireztajai matrix90 j rindai
            std::cout << matrix90[i][j] << " ";
        }
        std::cout << "\n";                             //Katra rinda tiek izdrukāta jaunā rindā
    }

    return 0;

}