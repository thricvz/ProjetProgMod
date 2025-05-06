#include "doctest.h"
#include "Ensemble.hpp"

Ensemble::Ensemble(){
	t=vector<int>(MAXCARD);
	card=0;
}

void Ensemble::affiche(ostream& out) const{
	if(card==0) return;
	out<<"| ";
	for (int i=0;i<card;i++){
		out<<t[i]<<" | ";
	}
	out<<endl;
}

vector<int> Ensemble::getvec() const{
	return t;
}

bool Ensemble::estVide() const{
	if (card==0) return true;
	return false;
}

int Ensemble::cardinal() const{
	return card;
}

void Ensemble::ajoute(int o){
	if (card+1>MAXCARD) throw invalid_argument("Out of range");
	t[card]=o;
	card++;
	return;
}

int Ensemble::tire(){
	srand(time(NULL));
	if(card-1<0) throw invalid_argument("Out of range");
	int alea = rand() % card;
	alea = t[alea];
	t[alea]=0;
	card--;
	return alea;
}

ostream& operator<<(ostream& out, Ensemble e){
	e.affiche(out);
	return out;
}
