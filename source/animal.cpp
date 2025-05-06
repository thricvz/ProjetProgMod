#include "../include/animal.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Animal::Animal(){
    id = -1;   
};

Animal::Animal(int identifiant,Espece e, Coord c){
    id = identifiant;
    coordonne = c;
    espece = e;
    food = FoodInit;
};

int Animal::getId(){
    return id;
};

int Animal::getCoord(){
    return coordonne;
};

void Animal::setCoord(Coord c){
    coordonne = c;
};

Espece Animal::getEspece(){
    return espece;
};

bool Animal::seReproduit(int casesLibres){
    if(espece==Espece::lapin){
        if(casesLibres>=MinFreeBirthLapin){
            //effectue le tirage au sort
            srand(time(0));
            int tirage = rand()%100;
            //regarde si les probabilites sont bonnes
            if(tirage < static_cast<int>(ProbBirthLapin*100))
                return true;
            else 
                return false;
        } 
    //cas ou c'est un renard   
    }else{
        if(food >= FoodReprod){
            srand(time(0));
            int tirage = rand()%100;
            //regarde si les probabilites sont bonnes
            if(tirage < static_cast<int>(ProbBirthRenard*100))
                return true;
            else 
                return false;   
        }
    }
}


bool Animal::meurt(){
    if(food == 0){
        return true;
    }
    return false;
}


void Animal::mange(){
    if(food+FoodLapin > MaxFood){
        food = MaxFood;
    }else{
        food+=FoodLapin;
    }
}

void Animal::jeune(){
    food--;   
}