#include <vector>
#include <ctime>
const int MAXCARD = 10;
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