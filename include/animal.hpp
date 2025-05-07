#pragma once
#include "../include/coord.hpp"
using namespace std;

enum class Espece {lapin,renard};
extern int FoodInit = 5 ;
extern int FoodLapin = 5 ;
extern int FoodReprod = 8 ;
extern int MaxFood = 10 ;
extern float ProbBirthRenard = 0.05 ;
extern float ProbBirthLapin = 0.30 ;
extern int MinFreeBirthLapin = 4;

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

