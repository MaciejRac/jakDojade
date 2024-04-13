#pragma once
#include"Path.h"
#include "CitiesList.h"

class PathList
{
    CitiesList* citylist;
    struct Connection {
        Path* path;
        Connection* next;
    };
    struct DijkstraElement{
        DijkstraElement* next;
        int w;
        Path* path;
        City* beggining;
        City* destiny;
    };
    Connection* entries = nullptr;

public:
    PathList(CitiesList* citylist_in);
    void getPath(char** maparray, int height, int width);
    void printPath();
    void flights(char* departure_in, char* destination_in, int time_in);
    void dijkstraAlgorythm(char* source, char* destination, int mode);
    bool isPath(City* departure_in, City* destination_in, int time_in);
private:
    void addPath(City* departure_in, City* destination_in, int time_in);
    Path* findPath(char* name);
    int pathCount();

};

