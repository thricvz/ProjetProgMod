#ifndef ENSEMBLE_H
#define ENSEMBLE_H
#include <vector>
#include <ctime>
#include <ostream>
extern const int MAXCARD;

using namespace std;

class Ensemble{
	vector<int> t;
	int card;

	public : 

	Ensemble();

	void affiche(ostream& out) const;

	bool estVide() const;

	int cardinal() const;

	vector<int> getvec() const;

	void ajoute(int o);

	int tire();
};



ostream& operator<<(ostream& out, Ensemble e);
#endif