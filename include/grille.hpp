#include <vector>
#include "../include/coord.hpp"

class Grille{
    std::vector<int> grilleIds;
    
    public:
        Grille();
        bool caseVide(Coord c);
        int getCase(Coord c);
        void videCase(Coord c);
        void setCase(int idAnimal, Coord coordAnimal);

};