#pragma once
#include "../include/coord.hpp"
using namespace std;
#define FoodInit  5 ;
#define FoodLapin  5 ;
#define FoodReprod 8 ;
#define MaxFood  10 ;
#define ProbBirthRenard  0.05 ;
#define ProbBirthLapin  0.30 ;
#define MinFreeBirthLapin 4;
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

