#pragma once
#include "City.h"
class CitiesList
{
private:
  /*  friend char* nextDelete(char* s);
    friend char* isEnd(char* token);*/
public:
    int counter = 0;
    struct Entry {
        City* city;
        Entry* next;
        Entry* prev;
    };
    Entry* entries = nullptr;

    char* nextDelete(char* s);
    
    char* isEnd(char* token);
    
    void addCity(char* name, size_t nameLen, int x_in, int y_in);

    void addCrossing(int x_in, int y_in);

    void addAny(char* name, size_t nameLen, int x_in, int y_in, bool isCity);

    void getCrossing(char** maparray, int height, int width);

    City* getFirst();

    City* find(char* name);

    City* find(int x_in,int y_in);

    int getPos(char* s);

    int getPos2(char* s);

    int getPos3(char* s);

    bool isExisting(int height, int width);

    void getCityfromline(char** line, int height, int width);

    void getCity(char** maparray, int height, int width);

    void printCities();

    int countCities();

    ~CitiesList();
};

