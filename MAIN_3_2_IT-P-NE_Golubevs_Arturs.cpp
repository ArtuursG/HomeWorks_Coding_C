/*
Uzprogrammēt spēli: “Vārdu minēšana”. 

DONE: 1. Jāsagatavo masīvu ar vismaz 20 vārdiem.
DONE: 2. Uzsākot spēli ar gadījuma ģeneratora palīdzību tiek izvēlēts viens no vārdiem.
DONE: 3. Burtu skaitu jāatspoguļo ar atbilstošo punktu “.” skaitu un pēc veiksmīga minējuma attiecīgā vietā punktu jāaizvieto ar burtu (vairākās vietās ja burti ir vairāki).
Nedarbojās: #include <conio.h> 4. Burtu ievadei jānotiek bez “Enter” nospiešanas.
DONE: 5. Par nepareizo burtu piešķir 1 soda punktu.
DONE: 6. Spēle turpinās kamēr spēlētājs nesavāks 10 soda punktus, vai kamēr burtu vietā neievadīs “0”.
50/50: 7. Pēc katra uzminēta vārda spēlētājam sadeg 5 soda punkti, ja tādi viņam ir (nedrīkst būt negatīvs soda punktu skaits!). Un piedāvāts nākamais vārds (vārdi nedrīkst atkārtoties!).
50/50: 8. Spēles beigās jāizvada uzminēto vārdu skaitu. Vai apsveikumu ja bija uzminēti visi vārdi.
*/


#include <iostream>
#include <string>
#include <vector>
#include <ctime> //srand() un time()
#include "HEADER_3_2_IT-P-NE_Golubevs_Arturs.hpp"

int main() {
    //1. Sagatavo vārdu sarakstu ar vismaz 20 vārdiem
    std::vector<std::string> vardusaraksts = {
        "ābols", "banāns", "ķirsis", "vīnoga", "apelsīns", "citrons", "mango", "persiks", "bumbieris", "plūme",
        "kivi", "laims", "melone", "zemene", "papaija", "vīģe", "guava", "aprikoze", "nektarīns", "datele"
    };

    srand(time(0));

    int sodapunkti = 0;
    int uzminetievardi = 0;

    while (sodapunkti < 10) {
        //2. Izvēlas gadījuma vārdu un inicializē paslēpto vārdu
        std::string izveletaisvards = gad_vards(vardusaraksts);
        std::string pasleptaisvards = pasl_vards(izveletaisvards);
        bool vardsuzminets = false;

        std::cout << "\nJauns vārds izvēlēts! Vārdam ir " << izveletaisvards.size() << " burti.\n";

        while (!vardsuzminets) {
            stavoklis(pasleptaisvards, sodapunkti);

            std::cout << "Ievadi burtu (vai '0', lai pārtrauktu spēli): ";
            char burts;
            std::cin >> burts;

            if (burts == '0') {
                std::cout << "\nSpēle beigusies! Jo tika ievadīta vērtība '0'.\n";
                std::cout << "Uzminētie vārdi: " << uzminetievardi << "\n";
                return 0;
            }

            //3. Apstrādā minēto burtu
            if (mineet(izveletaisvards, pasleptaisvards, burts)) {
                std::cout << "Pareizs minējums!\n";
                if (pasleptaisvards == izveletaisvards) {
                    std::cout << "Apsveicu! Tu uzminēji vārdu: " << izveletaisvards << "\n";
                    uzminetievardi++;
                    vardsuzminets = true;

                    //7. Samazina soda punktus pēc vārda uzminēšanas
                    sodapunkti = samazin_sodus(sodapunkti);
                }
            } else {
                sodapunkti++; //5. Pievieno soda punktu par nepareizu minējumu
                std::cout << "Nepareizs minējums!\n";
            }

            //6. Beidz spēli, ja soda punkti sasniedz 10
            if (sodapunkti >= 10) {
                std::cout << "\nSpēle beigusies! Sakrāti 10 soda punkti.\n";
                std::cout << "Uzminētie vārdi: " << uzminetievardi << "\n";
                return 0;
            }
        }
    }

    //8. Spēles beigās izvada uzminēto vārdu skaitu
    std::cout << "\nSpēle beigusies! Uzminēti: " << uzminetievardi << " vārdi(-s).\n";
    return 0;
}