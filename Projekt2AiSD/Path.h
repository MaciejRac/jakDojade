#pragma once
#include "City.h"
class Path
{
public:
	char** maparray;
	int max_height, max_width;
	int time;
	City* destination;
	City* departure;
	//Path(char**s,int height,int width);
	void findingPaths();
};

