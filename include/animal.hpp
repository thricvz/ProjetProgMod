#ifndef ANIMAL_H
#define ANIMAL_H
#include "../include/coord.hpp"
using namespace std;

extern int FoodInit;
extern int FoodLapin;
extern int FoodReprod; 
extern int MaxFood;
extern int ProbBirthRenard;
extern int ProbBirthLapin;
extern int MinFreeBirthLapin;

enum class Espece {lapin,renard};

class Animal{
	Espece espece;
	Coord coordonne;
	int id;
	int food;
	public:
		Animal();
		Animal(int identifiant,Espece e, Coord c);

		int getId();
		Coord getCoord();

		void setCoord(Coord c);
		Espece getEspece();
	
		//propre a lapin
		bool seReproduit(int casesLibres);

		//propres a renard
		bool meurt();
		void mange();
		void jeune();
};

#endif