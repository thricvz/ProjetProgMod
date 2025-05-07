#include "../include/jeu.hpp"
#include <iostream>
#include<unistd.h>

void afficherGrilleVide(Jeu &sim) {
    const int taille = 40;
    
    Coord currentCord;
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
			currentCord =  Coord(i,j);
			
            std::cout << sim.lettreCase(currentCord);  // Deux espaces pour une meilleure lisibilité
        }
        std::cout << "\n";  // Nouvelle ligne après chaque rangée
    }
}


int ntours =  10;
int main(){
	Jeu simulation(0.3,0.1);
	while(ntours >0){
        
        afficherGrilleVide(simulation);
        simulation.joueTour();
		ntours--;

        std::cout << "Tour numero: " << ntours << std::endl;
        std::cout << "========================================================================================"<< std::endl; 
        std::cout << std::endl;
        
        sleep(1);
	}

	return 0;
}