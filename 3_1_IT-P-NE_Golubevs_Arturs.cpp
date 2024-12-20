/*
1. uzdevums:
Programma pieprasa laiku formātā hh:mm:ss un pārbauda ievades korektumu, 
izvadot atbilstošu ziņojumu (3 varianti), piemēram: 

23:09:03 – pareizs laiks un formāts,
2:2:2 - nepareizs formāts,
12:02:94 - nepareizs laiks,
14.05.35 - nepareizs formāts,
qw2:we34 - nepareizs formāts.

*/

#include <iostream>
#include <string>  // lenght() - https://cplusplus.com/reference/string/string/length/, stoi() - https://cplusplus.com/reference/string/stoi/
#include <sstream> // stringstream() - https://cplusplus.com/reference/sstream/stringstream/, getline() - https://cplusplus.com/reference/string/string/getline/

bool timeformat(const std::string& time) {
    int semicolon = 0;

    for (char c : time) {
        if (c == ':') {
            semicolon++;
        
          // Pārbauda vai nav kāds lieks simbols, vai arī punkts '.'
          //14.05.35 un qw2:we34 apstājās te
        } else if (!std::isdigit(c) && c != ':') {
            std::cout << "Nepareizs formāts";
            return false;
        }
    }

    if (semicolon != 2) {
        std::cout << "Laika formāts nav pareizs";
        return false;
    }

    std::stringstream colonsplit(time);
    std::string hh, mm, ss;

    //atdala ievadīto time. Atdalītājs ir ':'
    //Piemēram, time = '23:09:03'
    std::getline(colonsplit, hh, ':'); // '23: stop'
    std::getline(colonsplit, mm, ':'); // '09: stop'
    std::getline(colonsplit, ss, ':'); // '03 stop'

    //Ja string garums nav 2, tad "Nepareizs fromāts"
    //2:2:2 tiek apturēts pie šī nosacījuma
    if (hh.length() != 2 || mm.length() != 2 || ss.length() != 2) {
        std::cout << "Nepareizs formāts";
        return false;
    }

    //Pārbauda char c pēc ASCII tabulas, kur '23', '2' = 50 un '3' = 51 un ja nosacījums ir false, neizpildās if bloks. '0' = un '9' =
    //Ja, piemēram, hh = '2', tas netiks apstrādāts, jo pārbaudīts iepriekšējā nosacījumā hh.length() != 2
    for (char c : hh) {
        if (c < '0' || c > '9') {
            std::cout << "Nepareizs formāts";
            return false;
        }
    }

    for (char c : mm) {
        if (c < '0' || c > '9') {
            std::cout << "Nepareizs formāts";
            return false;
        }
    }

    for (char c : ss) {
        if (c < '0' || c > '9') {
            std::cout << "Nepareizs formāts";
            return false;
        }
    }

    //std::stoi - pārveido no string uz integer. Ja hh = '02', tad pārveidos uz int 2
    int hours = std::stoi(hh);
    int minutes = std::stoi(mm);
    int seconds = std::stoi(ss);

    //23:09:03 izpildās un tiek izvadīts "Pareizs laiks un formāts"
    if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59) {
        std::cout << "Pareizs laiks un formāts";
        return true;
    } else { //12:02:94 apstājās te
        std::cout << "Nepareizs laiks";
        return false;
    }
}
    

int main() {
    std::string time;

    std::cout << "Ievadiet laiku (hh:mm:ss): \n";
    std::cin >> time;

    bool result = timeformat(time);

    //Nav obligāti
    //std::cout << "Rezultāts: " << (result ? "Pareizs" : "Nepareizs") << std::endl;

    return 0;
}