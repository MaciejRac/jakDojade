#pragma once
class City
{
public:
    int x_pos, y_pos;
    char* name;
    bool isCity;
    int crossing_number;
    int node;
   // City* getCity(char**tab);
    ~City();
    void setNode(int number );
};

