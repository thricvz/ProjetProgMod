#include "coord.hpp"
using namespace std;

class enum Espece {lapin,renard};

class Animal{
	Espece esp;
	int id, food;
	Coord coor;

	Animal();
	Animal(int i,Espece e, Coord c);

	int getId() const;
	int getCoord() const;
	void setCoord();
	Espece getEspece() const;
	void affiche() const;	
	bool meurt() const;
	bool seReproduit() const;
	void mange();
	void jeune();
}