#pragma once
#include "../include/animal.hpp"
#include <vector>
using namespace std;

class Population{
    vector<Animal*> pop;
    int available_id=0;
    vector<int> reusable_id = vector<int>(0);
    public:
        Population();

        Animal * get(int id);
        vector<int> getIds();

        int reserve();
        void set(Espece e, Coord c);
        void supprime(int i);
};