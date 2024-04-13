#pragma once
class FullMap
{
private:
	int height, width;
	char** tab;
public:
	FullMap(int x_in,int y_in);
	void auto_fill_tab();
	void fill_tab();
	char** getMap();
	void print_tab();
	~FullMap();
	

};

