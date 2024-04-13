#include "Map.h"
#include <iostream>
#include<cstdio>

using namespace std;

FullMap::FullMap(int x_in, int y_in) {
	width = x_in;
	height = y_in;
	tab = new char* [height];
	for (int i = 0; i < height; i++) {
		tab[i] = new char[width+1];
	}
}
FullMap::~FullMap() {
	//cout << "niszcze swiat" <<endl;
	for (int i = 0; i < height; i++) {
		delete[] tab[i];
	}
	delete[] tab;
}
void FullMap::auto_fill_tab() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			tab[i][j] = (i+1 % 10) + 48;
		}
	}
}
 void FullMap::fill_tab() {
	char s;
	for (int i = 0; i < height; i++) {
		tab[i][width] = 0;
		for (int j = 0; j < width; j++) {
			cin >> tab[i][j];
			//s = getchar();
			//if (s == '\n') {
			//	//cin>>tab[i][j];
			//	s = getchar();
			//	tab[i][j] = s;
			//}
			//else {
			//	tab[i][j] = s;
			//}
		}
	}
}
char** FullMap::getMap() {
	return tab;
}
void FullMap::print_tab() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << tab[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
