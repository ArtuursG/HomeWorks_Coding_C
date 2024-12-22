#include <iostream>
#include <cstdlib> //rand()
#include "HEADER_3_2_IT-P-NE_Golubevs_Arturs.hpp"

//Uzsākot spēli ar gadījuma ģeneratora palīdzību tiek izvēlēts viens no vārdiem
std::string gad_vards(const std::vector<std::string>& vardu_saraksts) {
    return vardu_saraksts[rand() % vardu_saraksts.size()];
}

//Burtu skaitu jāatspoguļo ar atbilstošo punktu “.” skaitu 
std::string pasl_vards(const std::string& vards) {
    return std::string(vards.size(), '.'); 
}

//Apstrādā spēlētāja minēto burtu
bool mineet(const std::string& vards, std::string& paslepts, char burts) {
    bool pareizs = false;
    for (size_t i = 0; i < vards.size(); i++) {
        if (vards[i] == burts && paslepts[i] != burts) {
            paslepts[i] = burts;
            pareizs = true;
        }
    }
    return pareizs;
}

void stavoklis(const std::string& paslepts, int soda_punkti) {
    std::cout << "\nUzmini vārdu: " << paslepts << "\n";
    std::cout << "Soda punkti: " << soda_punkti << "\n";
}

//Pēc katra uzminēta vārda spēlētājam sadeg 5 soda punkti
int samazin_sodus(int soda_punkti, int samazinas_apjoms) {
    return std::max(0, soda_punkti - samazinas_apjoms); //https://en.cppreference.com/w/cpp/algorithm/max
}