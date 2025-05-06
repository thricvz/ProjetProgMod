#include "../include/coord.hpp"
using namespace std;

enum class Espece {lapin,renard};
int FoodInit = 5 ;
int FoodLapin = 5 ;
int FoodReprod = 8 ;
int MaxFood = 10 ;
float ProbBirthRenard = 0.05 ;
float ProbBirthLapin = 0.30 ;
int MinFreeBirthLapin = 4;

class Animal{
	Espece espece;
	Coord coordonne;
	int id;
	int food;
	public:
		Animal();
		Animal(int identifiant,Espece e, Coord c);

		int getId();
		int getCoord();

		void setCoord(Coord c);
		Espece getEspece();
	
		//propre a lapin
		bool seReproduit(int casesLibres);

		//propres a renard
		bool meurt();
		void mange();
		void jeune();
};

