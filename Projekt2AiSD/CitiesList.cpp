#define _CRT_SECURE_NO_WARNINGS
#include "CitiesList.h"
#include <string.h>
#include <cstring>
#include <iostream>

void CitiesList::addAny(char* name, size_t nameLen, int x_in, int y_in, bool isCity) {
    Entry* newEntry = new Entry;
    newEntry->next = entries;
    entries = newEntry;
    entries->city = new City;
    entries->city->isCity = isCity;
    entries->city->name = new char[nameLen];
    strncpy(entries->city->name, name, nameLen);
    entries->city->x_pos = x_in;
    entries->city->y_pos = y_in;
}
void CitiesList::addCity(char* name, size_t nameLen,int x_in,int y_in) { //dodajemy na koniec 
    addAny(name, nameLen, x_in, y_in, true);
}
void CitiesList::addCrossing(int x_in, int y_in) {
    char name[256];
    snprintf(name, 256, "Crossing %d", counter);
    addAny(name, strlen(name)+1, x_in, y_in, false);
    counter++;
}
City* CitiesList::getFirst() {
   return entries == nullptr ? nullptr : entries->city;
}
City* CitiesList::find(char* name) {
    Entry* temp = entries;

    // Check for empty list.
    if (entries == NULL) {
        //std::cout << "List empty" << std::endl;
        return 0;
    }

    // Traverse the list.
    while (temp != NULL) {
        if (temp->city->isCity) {
            if (strcmp(name, temp->city->name) == 0)
                return temp->city;
            temp = temp->next;
        }
        else
            temp = temp->next;
    }
   /* while (entries != nullptr) {
        if (strcmp(name, temp->city->name) == 0)
            return temp->city;
        temp->next;
    }*/
    return 0;
}
City* CitiesList::find(int x_in,int y_in) {
    Entry* temp = entries;

    // Check for empty list.
    if (entries == NULL) {
        //std::cout << "List empty" << std::endl;
        return 0;
    }

    // Traverse the list.
    while (temp != NULL) {
            if ( temp->city->x_pos == x_in&& temp->city->y_pos == y_in)
                return temp->city;
            else
                temp = temp->next;
       

    }
    /* while (entries != nullptr) {
         if (strcmp(name, temp->city->name) == 0)
             return temp->city;
         temp->next;
     }*/
    return 0;
}

CitiesList::~CitiesList() {
    while (entries != nullptr) {
        auto toDelete = entries;
        entries = toDelete->next;

        delete toDelete->city;
        delete toDelete;
    }
}
char* CitiesList::nextDelete(char* s) { //szukanie znakow w lancuchu
    while ((*s == '.' || *s == '#' || *s == '*') && *s != '\0') {
        s++;
        /* if (*s == '*' || *s == '.' || *s== '#')
             break;
         z = s;*/
    }
    return ((*s != '#' && *s != '*' && *s != '.'&&*s!='\0') ? isEnd(s) : NULL);
}
char* CitiesList::isEnd(char* token) {
    auto l = strlen(token) + 1;
    char* copy = new char[l];
    strncpy(copy, token, l);
    copy[l] = 0;
    char* tok;
    char korektor[] = "#.*";
    tok = strtok(copy, korektor);
    while (tok != NULL) {
        tok = strtok(NULL, korektor);
    }
    return copy;
}
void CitiesList::getCity(char** maparray,int height,int width) {
    for (int i = 0; i < height; i++) {
            maparray[i][width];
            if (nextDelete(maparray[i]) == NULL)
                continue;
            else {
                if (i == 0) {
                    for (int k = i; k < i + 2; k++) {
                        if (getPos3(maparray[i]) == 0) {
                            for (int l = getPos3(maparray[i]); l < getPos3(maparray[i]) + 2; l++)
                                if (maparray[k][l] == '*')
                                    if(!isExisting(l,k))
                                        addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);
                                    else {

                                    }
                                else {
                                }
                        }
                        else {
                            for (int l = getPos3(maparray[i]) - 1; l < getPos3(maparray[i]) + 2; l++)
                                if (maparray[k][l] == '*')
                                    if (!isExisting(l, k))
                                        addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);
                                    else {

                                    }
                                else {
                                }
                        }

                        //for (int k = i ; k < i + 2; k++) {
                        if (getPos(maparray[i]) + getPos3(maparray[i]) == width - 1) {//tu zmieniam i na k
                            for (int l = getPos(maparray[i]) + getPos3(maparray[i]) - 1; l < getPos(maparray[i]) + getPos3(maparray[i]) + 1; l++)//tu zmieniam i na k
                                if (maparray[k][l] == '*')
                                    if (!isExisting(l, k))
                                        addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);//tu zmieniam i na k oprocz ostatniego
                                    else {

                                    }
                                else {

                                }
                        }
                        else {
                            for (int l = getPos(maparray[i]) + getPos3(maparray[i]) - 1; l < getPos(maparray[i]) + getPos3(maparray[i]) + 2; l++)//tu zmieniam i na k
                                if (maparray[k][l] == '*')
                                    if (!isExisting(l, k))
                                        addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);//tu zmieniam i na k oprocz ostatniego
                                    else {

                                    }
                                else {

                                }
                        }
                    }
                   // }
                }
                else if (i == height - 1) {
                    for (int k = i - 1; k < i + 1; k++) {
                        if (getPos3(maparray[i]) == 0) {
                            for (int l = getPos3(maparray[i]); l < getPos3(maparray[i]) + 2; l++)
                                if (maparray[k][l] == '*')
                                    if (!isExisting(l, k))
                                        addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);
                                    else {

                                    }
                                else {
                                }
                        }
                        else {
                            for (int l = getPos3(maparray[i]) - 1; l < getPos3(maparray[i]) + 2; l++)
                                if (maparray[k][l] == '*')
                                    if (!isExisting(l, k))
                                        addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);
                                    else {

                                    }
                                else {
                                }
                        }
                    
                    //for (int k = i - 1; k < i + 1; k++) {
                        if (getPos(maparray[i]) + getPos3(maparray[i]) == width - 1) {
                            for (int l = getPos(maparray[i]) + getPos3(maparray[i]) - 1; l < getPos(maparray[i]) + getPos3(maparray[i]) + 1; l++)
                                if (maparray[k][l] == '*')
                                    if (!isExisting(l, k))
                                        addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);
                                    else {

                                    }
                                else {

                                }
                        }
                        else {
                            for (int l = getPos(maparray[i]) + getPos3(maparray[i]) - 1; l < getPos(maparray[i]) + getPos3(maparray[i]) + 2; l++)
                                if (maparray[k][l] == '*')
                                    if (!isExisting(l, k))
                                        addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);
                                    else {

                                    }
                                else {

                                }
                        }
                    }
                }
                else {
                    for (int k = i - 1; k < i + 2; k++) {
                        if (getPos3(maparray[i]) == 0) {
                            for (int l = getPos3(maparray[i]); l < getPos3(maparray[i]) + 2; l++) //zmieniam 1 na 2 po get pos
                                if (maparray[k][l] == '*')
                                    if (!isExisting(l, k))
                                        addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);
                                    else {

                                    }
                                    else {
                                }
                        }
                        else {
                            for (int l = getPos3(maparray[i]) - 1; l < getPos3(maparray[i]) + 2; l++) //tez na 2
                                if (maparray[k][l] == '*')
                                    if (!isExisting(l, k))
                                        addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);
                                    else {

                                    }
                                else {
                                }
                        }
                        //for (int k = i - 1; k < i + 2; k++) {
                            if (getPos(maparray[i]) + getPos3(maparray[i]) == width - 1) {
                                for (int l = getPos(maparray[i]) + getPos3(maparray[i]) - 1; l < getPos(maparray[i]) + getPos3(maparray[i]) + 1; l++)
                                    if (maparray[k][l] == '*')
                                        if (!isExisting(l, k))
                                            addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);
                                        else {

                                        }
                                    else {

                                    }
                            }
                            else {
                                for (int l = getPos(maparray[i]) + getPos3(maparray[i]) - 1; l < getPos(maparray[i]) + getPos3(maparray[i]) + 2; l++) //i tu na 2
                                    if (maparray[k][l] == '*')
                                        if (!isExisting(l, k))
                                            addCity(nextDelete(maparray[i]), strlen(nextDelete(maparray[i])) + 1, l, k);
                                        else {

                                        }
                                    else {

                                    }
                            }
                        //}
                    }
                }
            }
    }
}

void CitiesList::getCrossing(char** maparray, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0) {
                if (j == 0) {
                    continue;
                }
                else if (j == width - 1)
                {
                    continue;
                }
                else {
                    if (maparray[i][j] == '#' && ((maparray[i][j + 1] == '#'|| maparray[i][j + 1] == '*') && (maparray[i + 1][j] == '#'|| maparray[i + 1][j] == '*') && (maparray[i][j - 1] == '#'|| maparray[i][j - 1] == '*'))) {
                        addCrossing(j, i);
                        maparray[i][j] = '$';
                    }
                    
                    else {

                    }
                }
            }
            else if (i == height - 1) {
                if (j == 0) {
                    continue;
                }
                else if (j == width - 1)
                {
                    continue;
                }
                else {
                    if (maparray[i][j] == '#' && ((maparray[i][j + 1] == '#'|| maparray[i][j + 1] == '*') && (maparray[i][j - 1] == '#'|| maparray[i][j - 1] == '*') && (maparray[i - 1][j] == '#'|| maparray[i - 1][j] == '*'))) {
                        addCrossing(j, i);
                        maparray[i][j]='$';
                    }
                        
                    else {

                    }
                }
            }
            else {
                if (j == 0) {
                    if (maparray[i][j] == '#' && ((maparray[i][j + 1] == '#'|| maparray[i][j + 1] == '*') && (maparray[i + 1][j] == '#'|| maparray[i + 1][j] == '*') && (maparray[i - 1][j] == '#'|| maparray[i - 1][j] == '*')))
                    {
                        addCrossing(j, i);
                        maparray[i][j] = '$';
                    }
                    else {

                    }

                }
                else if (j == width - 1)
                {
                    if (maparray[i][j] == '#' && ((maparray[i][j - 1] == '#'|| maparray[i][j - 1] == '*') && (maparray[i + 1][j] == '#'|| maparray[i + 1][j] == '*') && (maparray[i - 1][j] == '#'|| maparray[i - 1][j] == '*')))
                    {
                        addCrossing(j, i);
                        maparray[i][j] = '$';
                    }
                    else {

                    }

                }
                else {
                    if (maparray[i][j] == '#' && (((maparray[i][j + 1] == '#'|| maparray[i][j + 1] == '*') && (maparray[i + 1][j] == '#'|| maparray[i + 1][j] == '*') && (maparray[i - 1][j] == '#'|| maparray[i - 1][j] == '*')) ||
                        ((maparray[i][j + 1] == '#'|| maparray[i][j + 1] == '*') && (maparray[i + 1][j] == '#'|| maparray[i + 1][j] == '*') && (maparray[i][j - 1] == '#'|| maparray[i][j - 1] == '*')) ||
                        ((maparray[i + 1][j] == '#'|| maparray[i + 1][j] == '*') && (maparray[i - 1][j] == '#'|| maparray[i - 1][j] == '*') && (maparray[i][j - 1] == '#'|| maparray[i][j - 1] == '*')) ||
                        ((maparray[i][j + 1] == '#'|| maparray[i][j + 1] == '*') && (maparray[i - 1][j] == '#'|| maparray[i - 1][j] == '*') && (maparray[i][j - 1] == '#'|| maparray[i][j - 1] == '*'))))
                    {
                        addCrossing(j, i);
                        maparray[i][j] = '$';
                    }
                    else {

                    }
                }
            }
        }
    }
}

void CitiesList::printCities() {

        Entry* temp = entries;

        // Check for empty list.
        if (entries == NULL) {
           // std::cout << "List empty" << std::endl;
            return;
        }

        // Traverse the list.
        while (temp != NULL) {
            if(temp->city->isCity==true)
                std::cout << temp->city->name << " "<< temp->city->x_pos<< " " << temp->city->y_pos<<std::endl;
            else
                std::cout << temp->city->name << " " << temp->city->x_pos << " " << temp->city->y_pos << std::endl;
            temp = temp->next;
        }
    
}
int CitiesList::getPos3(char* s) { //szukanie znakow w lancuchu
    int j = 0;
    while ((*s == '.' || *s == '#' || *s == '*') && *s != '\0') {
        s++;
        j++;
        /* if (*s == '*' || *s == '.' || *s== '#')
             break;
         z = s;*/
    }
    return ((*s != '#' && *s != '*' && *s != '.' && *s != '\0') ? j : NULL);
}
bool CitiesList::isExisting(int width, int height)
{
    Entry* temp = entries;
    if (entries == NULL)
        return false;
    do{
        if (temp->city->x_pos == width && temp->city->y_pos == height) {
            return true;
       }
        temp = temp->next;
    } while (temp != NULL);
    return false;
}
void CitiesList::getCityfromline(char** line, int height, int width)
{
    //if (k==0) {
    //    //if(getPos3(line[]))
    //    for (k; k < k + 2; k++) {

    //    }
    //}
    //else if (k == height - 1){

    //}
    //else {

    //}
    bool wewnatrzCiagu = false;
    int poczatekCiaguX = -1;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j <width; j++) {
            char znak = line[i][j];

            if (!wewnatrzCiagu && znak != '#' && znak != '*' && znak != '.') {
                wewnatrzCiagu = true;
                poczatekCiaguX = j;
               
            }
            if (wewnatrzCiagu && (znak == '#' || znak == '*' || znak == '.' || j == width - 1)) {
                wewnatrzCiagu = false;
                int koniecCiaguX = 0;
                if (j == width - 1&& (znak != '#' && znak != '*' && znak != '.')) {
                    koniecCiaguX = j ;
                }
                else {
                    koniecCiaguX = j - 1;
                }
                int dlugosc = koniecCiaguX - poczatekCiaguX + 1;
                char* miasto =new char[dlugosc+1];
                for (int l = poczatekCiaguX, k=0; l < koniecCiaguX + 2; l++,k++) {
                    miasto[k] = line[i][l];
                }
                miasto[dlugosc] = '\0';
                //std::cout << "Ci¹g znaków znaleziony od [" << poczatekCiaguX << "][" << i<< "] do [" << koniecCiaguX << "][" << i << "]" << std::endl;
                if (i == 0) {
                    if (poczatekCiaguX == 0) {
                        for (int k = i; k < i + 2; k++) {
                            for (int l = poczatekCiaguX; l < poczatekCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }
                    else if (poczatekCiaguX== width - 1) {
                        for (int k = i; k < i + 2; k++) {
                            for (int l = poczatekCiaguX-1; l < poczatekCiaguX + 1; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }

                    }
                    else {
                        for (int k = i; k < i + 2; k++) {
                            for (int l = poczatekCiaguX-1; l < poczatekCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }

                    }
                }
                else if (i == height - 1) {
                    if (poczatekCiaguX == 0) {
                        for (int k = i-1; k < i + 1; k++) {
                            for (int l = poczatekCiaguX; l < poczatekCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }

                    }
                    else if (poczatekCiaguX == width - 1) {
                        for (int k = i-1; k < i + 1; k++) {
                            for (int l = poczatekCiaguX - 1; l < poczatekCiaguX + 1; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }

                    }
                    else {
                        for (int k = i-1; k < i + 1; k++) {
                            for (int l = poczatekCiaguX - 1; l < poczatekCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }

                    }

                }
                else {
                    if (poczatekCiaguX == 0) {
                        for (int k = i - 1; k < i + 2; k++) {
                            for (int l = poczatekCiaguX; l < poczatekCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }
                    else if (poczatekCiaguX == width - 1) {
                        for (int k = i - 1; k < i + 2; k++) {
                            for (int l = poczatekCiaguX - 1; l < poczatekCiaguX + 1; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }
                    else {
                        for (int k = i - 1; k < i + 2; k++) {
                            for (int l = poczatekCiaguX - 1; l < poczatekCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }
                }


                if (i == 0) {
                    if (koniecCiaguX == 0) {
                        for (int k = i; k < i + 2; k++) {
                            for (int l = koniecCiaguX; l < koniecCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }
                    else if (koniecCiaguX == width - 1) {
                        for (int k = i; k < i + 2; k++) {
                            for (int l = koniecCiaguX-1; l < koniecCiaguX + 1; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }
                    else {
                        for (int k = i; k < i + 2; k++) {
                            for (int l = koniecCiaguX - 1; l < koniecCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }
                }
                else if (i == height - 1) {
                    if (koniecCiaguX == 0) {
                        for (int k = i-1; k < i + 1; k++) {
                            for (int l = koniecCiaguX; l < koniecCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }

                    }
                    else if (koniecCiaguX == width - 1) {
                        for (int k = i-1; k < i + 1; k++) {
                            for (int l = koniecCiaguX - 1; l < koniecCiaguX + 1; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }
                    else {
                        for (int k = i-1; k < i + 1; k++) {
                            for (int l = koniecCiaguX - 1; l < koniecCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }

                }
                else {
                    if (koniecCiaguX == 0) {
                        for (int k = i - 1; k < i + 2; k++) {
                            for (int l = koniecCiaguX; l < koniecCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }
                    else if (koniecCiaguX == width - 1) {
                        for (int k = i - 1; k < i + 2; k++) {
                            for (int l = koniecCiaguX - 1; l < koniecCiaguX + 1; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }
                    else {
                        for (int k = i - 1; k < i + 2; k++) {
                            for (int l = koniecCiaguX - 1; l < koniecCiaguX + 2; l++) {
                                if (line[k][l] == '*') {
                                    if (!isExisting(l, k)) {
                                        addCity(miasto, strlen(miasto)+1, l, k);
                                    }
                                    else {

                                    }
                                }
                                else {

                                }
                            }
                        }
                    }
                }
                delete[]miasto;
            }
        }
    }

}
int CitiesList::getPos(char* s) { //do szukania konca nazwy
    while ((*s == '.' || *s == '#' || *s == '*') && *s != '\0') {
        s++;
        /* if (*s == '*' || *s == '.' || *s== '#')
             break;
         z = s;*/
    }
    return ((*s != '#' && *s != '*' && *s != '.' && *s != '\0') ? getPos2(s) : NULL);
}
int CitiesList::getPos2(char* token) { // koniec nazwy
    auto l = strlen(token) + 1;
    char* copy = new char[l];
    strncpy(copy, token, l);
    copy[l] = 0;
    char* tok;
    char korektor[] = "#.*";
    tok = strtok(copy, korektor);
    while (tok != NULL) {
        //std::cout << tok << " tutaj jest przed kropka" << std::endl;
        tok = strtok(NULL, korektor);
    }
    return (int)strlen(copy);
}

int CitiesList::countCities() {
      Entry* temp = entries;
      int counter=0;
        // Check for empty list.
        if (entries == NULL) {
            //std::cout << "List empty" << std::endl;
            return counter;
        }

        // Traverse the list.
        do {
            counter++;
            temp = temp->next;
        } while (temp != NULL);
        return counter;
}