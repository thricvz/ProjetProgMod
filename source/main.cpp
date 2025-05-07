#include "../include/jeu.hpp"

int ntours =  10;
int main(){
	Jeu simulation(0.3,0.1);
	while(ntours >0){
		simulation.joueTour();
	}
	return 0;
}