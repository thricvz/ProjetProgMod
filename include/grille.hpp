#include <vector>
#include "../include/coord.hpp"

class Grille{
    std::vector<int> grilleIds;
    
    public:
        Grille();
        bool caseVide();
        int getCase();
        void videCase(Coord c);
        void setCase(int idAnimal, Coord coordAnimal);

};