#ifndef HEADER_3_2_IT_P_NE_GOLUBEVS_ARTURS_HPP //https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
#define HEADER_3_2_IT_P_NE_GOLUBEVS_ARTURS_HPP

#include <string>
#include <vector>

std::string gad_vards(const std::vector<std::string>& vardu_saraksts);
std::string pasl_vards(const std::string& vards);
bool mineet(const std::string& vards, std::string& paslepts, char burts);
void stavoklis(const std::string& paslepts, int soda_punkti);
int samazin_sodus(int soda_punkti, int samazinas_apjoms = 5);

#endif