#include "../include/coord.hpp"
#include "../include/population.hpp"

Population::Population(){
    vector<Animal*> pop = vector<Animal*>(0);    
}

Animal * Population::get(int id){
    for(int i=0;i<pop.size();i++){
        if(pop[i]->getId()==id){
            return pop[i];
        }
    }
    return nullptr;
}

vector<int> Population::getIds(){
    vector<int> ids = vector<int>(0);
    for (int i=0;i<pop.size();i++){
        ids.push_back(pop[i]->getId());
    }
    return ids;
}

int Population::reserve(){

    int id = idCounter;
    idCounter++;
    return id;
}


int Population::set(Espece e, Coord c){
    int idAnimal = reserve();
    pop.push_back(new Animal(idAnimal,e,c));
    return idAnimal;
};


void Population::supprime(int id){


    
        Animal *animalAtuer = get(id);
        //decouvre l'indice
        int indexSup=0;
        for(;indexSup<pop.size();indexSup++){
            if(pop[indexSup]->getId()==id)
                break;
        }
        pop.erase(pop.begin()+indexSup);
        delete animalAtuer;

}

