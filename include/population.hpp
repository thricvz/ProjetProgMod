#ifndef POPULATION_H
#define POPULATION_H
#include "../include/animal.hpp"
#include <vector>
using namespace std;

class Population{
    vector<Animal*> pop;
    int idCounter=0;
    public:
        Population();

        Animal * get(int id);
        vector<int> getIds();

        int reserve();
        int set(Espece e, Coord c);
        void supprime(int id);
};

#endif