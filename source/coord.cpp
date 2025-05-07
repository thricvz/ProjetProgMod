#include "../include/coord.hpp"

Coord::Coord(){
	x = y = NULL;
}
Coord::Coord(int lig, int col){
	if (lig >= TAILLEGRILLE or col >= TAILLEGRILLE or lig<0 or col<0) throw invalid_argument("Mauvaises coordonnées");
	x=lig;
	y=col;
}

Coord::Coord(int n){
	if (n>TAILLEGRILLE*TAILLEGRILLE - 1 or n<0) throw invalid_argument("Out of range");
	x=n/TAILLEGRILLE;
	y=n%TAILLEGRILLE;
}
	
int Coord::getx() const{
	return x;
}
	
int Coord::gety() const{
	return y;
}

int Coord::toInt() const{
	return x*TAILLEGRILLE+y;
}

Ensemble Coord::voisines(){
	Ensemble e;
	for (int i=max(y-1,0);i<=min(y+1,TAILLEGRILLE-1);i++){
		for(int j=max(x-1,0);j<=min(x+1,TAILLEGRILLE-1);j++){
			if ((i,j)!=(x,y)) e.ajoute(Coord{i,j}.toInt());
		}
	}
	return e;
}

ostream& operator<<(ostream& out, Coord c){
	out<<"("<<c.getx()<<","<<c.gety()<<")";
	return out;
}

bool operator==(Coord c, Coord c2){
	return c.getx()==c2.getx() and c.gety()==c2.gety();
}

bool operator!=(Coord c, Coord c2){
	return !(c==c2);
}








