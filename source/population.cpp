#include "../include/coord.hpp"
#include "../include/population.hpp"

Population::Population(){
    vector<Animal*> pop = vector<Animal*>(0);
    
}

Animal * Population::get(int id){
    return pop[id];
}

vector<int> Population::getIds(){
    vector<int> sousPop;
    for (int i=0;i<pop.size();i++){
        sousPop.push_back(pop[i]->id);
    }
    return sousPop;
}

int Population::reserve(){
    int id = last_id;
    last_id++;
    pop.push_back(NULL);
    //mettre a jour l'identifiant
    return id;
}


void Population::set(Espece e, Coord c){
    int idAnimal = reserve();
    pop[idAnimal] = new Animal(idAnimal,e,c);
};


void Population::supprime(int i){
    Animal *animalAtuer = get(i);
    pop.pop_back();
    delete animalAtuer;
    last_id--;
};


