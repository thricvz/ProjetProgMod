#include <iostream>
#include "Ensemble.hpp"
using namespace std;
const int TAILLEGRILLE = 40;


class Coord{
	int x, y;
	
	public :

	Coord(int lig, int col);

	Coord(int n);
	
	int getx() const;
	
	int gety() const;

	int toInt() const;

	Ensemble voisines();
};

ostream& operator<<(ostream& out, Coord c);

bool operator==(Coord c, Coord c2);

bool operator!=(Coord c, Coord c2);

