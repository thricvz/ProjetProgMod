#include "../include/grille.hpp"


Grille::Grille(){
    grilleIds = vector<int>(TAILLEGRILLE*TAILLEGRILLE);
    for(int i =0;i<TAILLEGRILLE*TAILLEGRILLE;i++){
        grilleIds[i] = -1;
    }
}


bool Grille::caseVide(Coord c){
    return grilleIds[c.toInt()] == -1;
};

int Grille::getCase(Coord c){
    return grilleIds[c.toInt()];
};

void Grille::videCase(Coord c){
    grilleIds[c.toInt()] = -1;
};

void Grille::setCase(int idAnimal, Coord coordAnimal){
    grilleIds[coordAnimal.toInt()]=idAnimal;
};

