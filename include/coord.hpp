#ifndef COORD_H
#define COORD_H
#include <iostream>
#include "../include/ensemble.hpp"

using namespace std;
const int TAILLEGRILLE = 40;


class Coord{
	int x, y;
	
	public :

	Coord(int lig, int col);
	Coord();
	Coord(int n);
	
	int getx() const;
	
	int gety() const;

	int toInt() const;

	Ensemble voisines();
};

ostream& operator<<(ostream& out, Coord c);

bool operator==(Coord c, Coord c2);

bool operator!=(Coord c, Coord c2);


#endif