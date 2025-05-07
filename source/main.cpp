#include "../include/jeu.hpp"

int ntours =  10;
int main(){
	Jeu simulation(0.3,0.1);
	while(ntours >0){
		simulation.joueTour();
		ntours--;
	}
	return 0;
}