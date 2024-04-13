#include "City.h"
City::~City() {
    delete[] name;
}
void City::setNode(int number) {
    node = number;
}
//City* City::getCity(char**tab) {
//    return tab[x_pos][y_pos];
//}
