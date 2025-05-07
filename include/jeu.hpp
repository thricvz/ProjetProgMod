#ifndef JEU_H
#define JEU_H
#include "../include/population.hpp"
#include "../include/grille.hpp"
#include <string>
class Jeu{
    Grille grille;
    Population population;
    
    public:
        Jeu(float pLapin,float pRenard);
        void ajouteAnimal(Espece espece,Coord c);
        void joueTour();
        vector<Coord> voisins(Coord c);

        vector<Coord> voisinsVides(Coord c);
        vector<Coord> voisinsEspece(Espece espece,Coord c);
        std::string lettreCase(Coord c);
};

#endif