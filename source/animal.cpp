#include "../include/animal.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int FoodInit = 5;
int FoodLapin = 5;
int FoodReprod = 8;
int MaxFood = 10;
int ProbBirthRenard = 5;
int ProbBirthLapin = 30;
int MinFreeBirthLapin = 4;

Animal::Animal(){
    id = -1;   
    Coord Coord(0);
}

Animal::Animal(int identifiant,Espece e, Coord c){
    id = identifiant;
    coordonne = c;
    espece = e;
    food = FoodInit;
};

int Animal::getId(){
    return id;
};

Coord Animal::getCoord(){
    return coordonne;
};

void Animal::setCoord(Coord c){
    coordonne = c;
};

Espece Animal::getEspece(){
    return espece;
};

bool Animal::seReproduit(int casesLibres){
    if(espece==Espece::lapin && casesLibres>=MinFreeBirthLapin ){
        int tirage = rand()%100;
        if(tirage < ProbBirthLapin)
            return true;
    //cas ou c'est un renard
    }
    
    if (espece==Espece::renard && food >= FoodReprod){
        int tirage = rand()%100;
        if(tirage < ProbBirthRenard)
            return true;
    }
    
    return false;
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