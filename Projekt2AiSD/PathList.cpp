#include "PathList.h"
#include "CitiesList.h"
#include <iostream>

PathList::PathList(CitiesList* citylist_in) {
    citylist = citylist_in;
}

void PathList::addPath(City* departure_in, City* destination_in, int time_in) {
    Connection* newEntry = new Connection;
    newEntry->next = entries;
    entries = newEntry;
    entries->path = new Path;
    entries->path->departure = departure_in;
    entries->path->destination = destination_in;
    entries->path->time = time_in;
}

void PathList::getPath(char** maparray, int height, int width) {
    CitiesList::Entry* temp = citylist->entries;
   
    /*if (entries == NULL) {
        std::cout << "List empty" << std::endl;
    }*/

    while (temp != NULL) {
        int x, y, repeat = 0;
        int time = 0;
        bool direction1 = false, direction2 = false, direction3 = false, direction4 = false;
        bool find = false;
        y = temp->city->y_pos;
        x = temp->city->x_pos;
        while (find == false) {
            if (y < height - 1) {
                if ((maparray[y + 1][x] == '*'|| maparray[y + 1][x] == '$') && repeat != 2) {
                    time++;
                    if (time != 1 || !direction1) {
                        if (isPath(temp->city, citylist->find(x, y + 1), time)) {
                            addPath(temp->city, citylist->find(x, y + 1), time);
                            addPath(citylist->find(x, y + 1), temp->city, time);
                        }
                        y = temp->city->y_pos;
                        x = temp->city->x_pos;
                        if (time == 1)
                            direction1 = true;
                        time = 0;
                        continue;
                    }
                    else {
                        time--;
                    }
                }
                else if (maparray[y + 1][x] == '#') {
                    maparray[y + 1][x] = '.';
                    time++;
                    y = y + 1;
                    repeat = 1;
                    continue;
                }
                else {}
            }
            if (y > 0) {
                if ((maparray[y - 1][x] == '*'|| maparray[y - 1][x] == '$') && repeat != 1) {
                    time++;
                    if (time != 1 || !direction2) {
                        if (isPath(temp->city, citylist->find(x, y - 1), time)) {
                            addPath(temp->city, citylist->find(x, y - 1), time);
                            addPath(citylist->find(x, y - 1), temp->city, time);
                        }
                        y = temp->city->y_pos;
                        x = temp->city->x_pos;
                        if (time == 1)
                            direction2 = true;
                        time = 0;
                        continue;
                    }
                    else {
                        time--;
                    }
                }
                else if (maparray[y - 1][x] == '#' && y > 0) {
                    maparray[y - 1][x] = '.';
                    time++;
                    y = y - 1;
                    repeat = 2;
                    continue;
                }
                else {}
            }
            if (x < width - 1) {
                if ((maparray[y][x + 1] == '*'|| maparray[y][x + 1] == '$') && repeat != 4) {
                    time++;
                    if (time != 1 || !direction3) {
                        if (isPath(temp->city, citylist->find(x + 1, y), time)) {
                            addPath(temp->city, citylist->find(x + 1, y), time);
                            addPath(citylist->find(x + 1, y), temp->city, time);
                        }
                        y = temp->city->y_pos;
                        x = temp->city->x_pos;
                        if (time == 1)
                            direction3 = true;
                        time = 0;
                        continue;
                    }
                    else {
                        time--;
                    }
                }
                else if (maparray[y][x + 1] == '#') {
                    maparray[y][x + 1] = '.';
                    time++;
                    x = x + 1;
                    repeat = 3;
                    continue;
                }
                else {}
            }
            if (x > 0) {
                if ((maparray[y][x - 1] == '*'|| maparray[y][x - 1] == '$') && repeat != 3) {
                    time++;
                    if (time != 1 || !direction4) {
                        if (isPath(temp->city, citylist->find(x - 1, y), time)) {
                            addPath(temp->city, citylist->find(x - 1, y), time);
                            addPath(citylist->find(x - 1, y), temp->city, time);
                        }
                        y = temp->city->y_pos;
                        x = temp->city->x_pos;
                        if(time==1)
                            direction4 = true;
                        time = 0;
                        continue;
                    }
                    else {
                        time--;
                    }
                }
                else if (maparray[y][x - 1] == '#') {
                    maparray[y][x - 1] = '.';
                    time++;
                    x = x - 1;
                    repeat = 4;
                    continue;
                }
                else {}

            }
            find = true;
            break;
        }
        temp = temp->next;
    }
}
void PathList::flights(char* departure_in, char* destination_in, int time_in) {
    addPath(citylist->find(departure_in), citylist->find(destination_in), time_in);
   // addPath(citylist->find(destination_in), citylist->find(departure_in), time_in);
}
void PathList::printPath() {
    Connection* temp = entries;

    // Check for empty list.
    if (entries == NULL) {
       // std::cout << "List empty" << std::endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        if (temp->path->departure->isCity == true)
            std::cout << temp->path->departure->name << " ";
        else
            std::cout << temp->path->departure->name << " ";
        if (temp->path->destination->isCity == true)
            std::cout << temp->path->destination->name << " ";
        else
            std::cout << temp->path->destination->name << " ";
        std::cout << temp->path->time << std::endl;
        temp = temp->next;
    }
}
int PathList::pathCount() {
    Connection* temp = entries;
    int counter = 0;
    // Check for empty list.
    if (entries == NULL) {
       // std::cout << "List empty" << std::endl;
        return counter;
    }

    // Traverse the list.
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}
Path* PathList::findPath(char*name) {
    citylist->find(name);
    Connection* temp = entries;
    //Path path;

    // Check for empty list.
    if (entries == NULL) {
        //std::cout << "List empty" << std::endl;
        return 0;
    }

    // Traverse the list.
    while (temp != NULL) {
        if (temp->path->departure->isCity) {
            if (strcmp(name, temp->path->departure->name) == 0) {
                return temp->path;
            }
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

struct slistEl
{
    slistEl* next;
    int v, w;           // numer wêz³a docelowego i waga krawêdzi
};

const int MAXINT = 2147483647;

int getNodeIndex(char* name, City** names, int len) {
    for (int i = 0; i < len; i++) {
        if (strcmp(name, names[i]->name) == 0) return i;
    }
    return -1;
}
void PathList::dijkstraAlgorythm(char* source,char* destination, int mode) {
    using namespace std;

    int i, j, v, n, m, u, x, y, sptr, * d, * p, * S;
    bool* QS;           
    slistEl** graf;     // Tablica list s¹siedztwa
    slistEl* pw,*rw;
    City** allNodes;
    n = citylist->countCities();
    allNodes = new City* [n];
    i = 0;
    v = -1;
    for (CitiesList::Entry* entry = citylist->entries; entry != NULL; entry = entry->next) {
        allNodes[i] = entry->city;
        if (strcmp(entry->city->name, source) == 0) 
            v = i;
        i++;
    }
    m = pathCount();

    // Tworzymy tablice dynamiczne
    d = new int[n];          // koszty dojœcia
    p = new int[n];          // poprzednicy
    QS = new bool[n];        // przeszedl przez algorytm
    graf = new slistEl * [n]; // Tablica list s¹siedztwa
    S = new int[n];          
    sptr = 0;                 

    for (i = 0; i < n; i++)
    {
        d[i] = MAXINT;
        p[i] = -1;
        QS[i] = false;
        graf[i] = NULL;
    }

    // lista krawêdzi
   // i = 0;
    for (Connection* connection = entries; connection != NULL; connection = connection->next)
    {
        x = getNodeIndex(connection->path->departure->name, allNodes, n);
        y = getNodeIndex(connection->path->destination->name, allNodes, n);
        pw = new slistEl;      // Tworzymy element listy s¹siedztwa
        pw->v = y;             // Wierzcho³ek docelowy krawêdzi
        pw->w = connection->path->time;      // Waga krawêdzi
        pw->next = graf[x];
        graf[x] = pw;       // Element do³¹czamy do listy
      //  i++;
    }

    d[v] = 0;             
    // Wyznaczamy œcie¿ki
    for (i = 0; i < n; i++)
    {
        // Wierzcholek o najmniejszym koszcie d
        for (j = 0; QS[j]; j++);
            for (u = j++; j < n; j++)
                if (!QS[j] && (d[j] < d[u]))
                    u = j;
        QS[u] = true; //znaleziony wierzcholek najmniejszy koszt
        
        // Modyfikujemy odpowiednio wszystkich s¹siadów u, którzy s¹ w Q
        for (pw = graf[u]; pw; pw = pw->next)
            if (!QS[pw->v] && (d[pw->v] > d[u] + pw->w))
            {
                d[pw->v] = d[u] + pw->w;
                p[pw->v] = u;
            }
    }
    
    //cout << "Droga z " << source << " do " << destination << endl;
    if (mode == 1) {
        for (i = 0; i < n; i++)
        {
            if (strcmp(allNodes[i]->name, destination) == 0)
            {
                int lastSptr = -1;
                for (j = i; j > -1; j = p[j]) {
                    lastSptr = sptr;
                    S[sptr++] = j;
                }
              
                //if(d[i]!=MAXINT)
               // if (d[i] != MAXINT) {
                    cout << d[i] << " ";
                    while (lastSptr > 1)
                        if (allNodes[S[--lastSptr]]->isCity == true)
                            cout << allNodes[S[lastSptr]]->name << " ";
                    cout << endl;
                //}
               
                
            }
        }
    }
    else if (mode == 0) {
        for (i = 0; i < n; i++)
        {
            if (strcmp(allNodes[i]->name, destination) == 0)
            {
                //if (d[i] != MAXINT) {
                    cout << d[i] << endl;
                //}
            }
        }
    }
    else{}
    delete[] allNodes;
    delete[] d;
    delete[] p;
    delete[] QS;
    delete[] S;

    for (i = 0; i < n; i++)
    {
        pw = graf[i];
        while (pw)
        {
            rw = pw;
            pw = pw->next;
            delete rw;
        }
    }

    delete[] graf;

   
}

bool PathList::isPath(City* departure_in, City* destination_in, int time_in)
{
    Connection* temp = entries;

    // Check for empty list.
    if (entries == NULL) {
        // std::cout << "List empty" << std::endl;
        return true;
    }

    // Traverse the list.
    while (temp != NULL) {
        if (temp->path->departure->name == departure_in->name && temp->path->destination->name == destination_in->name && temp->path->time <= time_in)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}
