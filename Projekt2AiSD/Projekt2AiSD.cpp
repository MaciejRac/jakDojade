// Projekt2AiSD.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Map.h"
#include "CitiesList.h"
#include"PathList.h"

using namespace std;
void hash_fuction() {

}
char* getline(bool& endOfFile) {
    size_t lenmax = 100, count = 0;
    char* buffer = (char*)malloc(lenmax);
    int c;

    if (buffer == NULL)
        return NULL;
    endOfFile = false;
    while (true) {
        if (count >= lenmax) {
            lenmax += 100;
            char* newBuffer = (char*)realloc(buffer, lenmax);

            if (newBuffer == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = newBuffer;
        }

        c = fgetc(stdin);
        if (c == EOF) {
            endOfFile = true;
            buffer[count] = '\0';
            //koniec wczytywania
            break;
        }
        if (c == '\n') {
            buffer[count] = '\0';
            break;
        }
        buffer[count] = c;
        ++count;
    }
    return buffer;
}

int main()
{
   //bool EOFs = NULL;
    int height, width,flights,command,mode;
    CitiesList firstmap;
    PathList firstpathlist(&firstmap);
    cin >> width >> height;
    char departure[20];
    char destination[20];
   //char* str=0;
    //width++;
    /*
    for (int i = 0; i < height; i++) {
        str = getline(EOFs);
        cout << str << endl;
    }
    */
    //cout << nextDelete(tab2)<<endl;
    FullMap m(width, height);
    m.fill_tab();
    //m.print_tab();
    //Bcin >> flights;
    //firstmap.getCity(m.getMap(), height, width);
    firstmap.getCityfromline(m.getMap(), height, width);
    firstmap.getCrossing(m.getMap(), height, width);
    //firstmap.printCities();
    /*if (firstmap.getFirst()->isCity)
        cout << firstmap.getFirst()->name << endl;
    else
        cout << firstmap.getFirst()->crossing_number << endl;*/

    firstpathlist.getPath(m.getMap(), height, width);
    //firstpathlist.printPath();
    cin >> flights;
    for (int i = 0; i < flights; i++) {
        int time=0;
        cin >> departure;
        cin >> destination;
        cin >> time;
        firstpathlist.flights( departure, destination ,time );
    }
    cin >> command;
    for (int i = 0; i < command; i++) {
        cin >> departure;
        cin >> destination;
        cin >> mode;
        if (mode == 0 || mode == 1) {
            firstpathlist.dijkstraAlgorythm(departure, destination, mode);
        }
        else {
            cout << "blad" << endl;
        }
    }
    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
