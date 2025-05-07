#include "../include/coord.hpp"
#include "../include/population.hpp"

Population::Population(){
    vector<Animal*> pop = vector<Animal*>(0);    
}

Animal * Population::get(int id){
    for(int i=0;i<pop.size();i++){
        if(pop[i]->getId()==id)
            return pop[i];
    }
    return nullptr;
}

vector<int> Population::getIds(){
    vector<int> ids;
    for (int i=0;i<pop.size();i++){
        ids.push_back(pop[i]->getId());
    }
    return ids;
}

int Population::reserve(){
    if(reusable_id.size()!=0){
        int id = reusable_id.at(0);
        reusable_id.erase(reusable_id.begin());
        pop[id] = nullptr;
    }
    else{

        int id = available_id;
        available_id++;
        pop.push_back(nullptr);
        //mettre a jour l'identifiant
        return id;
    }
}


int Population::set(Espece e, Coord c){
    int idAnimal = reserve();
    pop[idAnimal] = new Animal(idAnimal,e,c);
    return idAnimal;
};


void Population::supprime(int id){
    Animal *animalAtuer = get(id);
    pop[id] = nullptr;
    delete animalAtuer;
    //ne pas enlever la case du animal tuer car utilise dans id
    reusable_id.push_back(id);
};


