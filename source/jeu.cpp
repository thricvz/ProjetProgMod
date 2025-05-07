#include "../include/jeu.hpp"



void Jeu::ajouteAnimal(Espece espece,Coord c){
    int idAnimal{0};
    idAnimal = population.reserve();
    population.set(espece,c);
    grille.setCase(idAnimal,c);
}

Jeu::Jeu(float pLapin,float pRenard){
    for(int casei =0;casei<TAILLEGRILLE;casei++){
        Coord currentCord(casei);
        //commence par tirer au hasard pour le lapin
        srand(time(0));
        int tirage{rand()%100};
        if(tirage <= static_cast<int>(pLapin*100)){
            ajouteAnimal(Espece::lapin,currentCord);

        }else if(tirage <= static_cast<int>(pRenard*100)){
            ajouteAnimal(Espece::lapin,currentCord);
       
        }else{
            //on guarde la case vide

        }
    }
};


vector<Coord> Jeu::voisins(Coord c){
    //8 cases 
    vector<Coord> neighbor = vector<Coord>(0);
    vector<int> relativePos = {-1,0,1};

    for(auto x_incr: relativePos){
        for(auto y_incr: relativePos){
            
            int newx =  c.getx()+x_incr;
            int newy = c.gety()+y_incr;
            //make sure to not add our current position
            if(newx != c.getx() || newy != c.gety()){
                
                //verifier si la coordonnee est valide
                if((newx >=0 && newx < TAILLEGRILLE) && (newy >=0 && newy < TAILLEGRILLE) ){
                    Coord tempCoord(newx,newy);
                    neighbor.push_back(tempCoord);
                }
            }
        }
    }
    
    return neighbor;
};
vector<Coord> Jeu::voisinsVides(Coord c){
    vector<Coord> neighbor = vector<Coord>(0);
    for (auto n: voisins(c)){
        if(grille.caseVide(c))
        neighbor.push_back(n);
    }
    
    return neighbor;
};

vector<Coord> Jeu::voisinsEspece(Espece espece,Coord c){
    vector<Coord> neighbor = vector<Coord>(0);
    for (auto n: voisins(c)){
        int id = grille.getCase(n);
        if(population.get(id)!=nullptr)
        neighbor.push_back(n);
    }
    
    return neighbor;
};


void Jeu::joueTour(){
    //deplace dabord tous les lapins
    for(auto idAnimal: population.getIds()){
        //check si c'est un lapin
        if(population.get(idAnimal)->getEspece()==Espece::lapin){
            Animal * lapin = population.get(idAnimal);
            //choix du deplacement
            std::vector<Coord> voisinsLapin = voisinsVides(lapin->getCoord());
            srand(0);
            int choix = rand()%voisinsLapin.size(); 
            Coord nouvelleCase= voisinsLapin[choix];

            //decide s'il se reproduit ou pas
            if(lapin->seReproduit(voisinsLapin.size())){
                ajouteAnimal(Espece::lapin,nouvelleCase);
            }else{
                //mets a jour la grille
                grille.setCase(-1,lapin->getCoord());
                grille.setCase(lapin->getId(),nouvelleCase);
                lapin->setCoord(nouvelleCase);
            }
        }
    }
    
    //comportement des renards
    for(auto idAnimal: population.getIds()){
        //check si c'est un renard
        if(population.get(idAnimal)->getEspece()==Espece::renard){
            Animal * renard = population.get(idAnimal);
            //choix du deplacement
            std::vector<Coord> voisinsRenard = voisinsEspece(Espece::lapin,renard->getCoord());
            if(voisinsRenard.size()!=0){
                renard->mange();
                //choisis sa proie
                int choixVictime;

                if(voisinsRenard.size()>1){
                    srand(0);
                    choixVictime =  rand()% voisinsRenard.size();
                }else{
                    choixVictime = 0;
                }
                int idlapinDevore =  grille.getCase(voisinsRenard[choixVictime]);
                Animal* lapinDevore = population.get(idlapinDevore);
                

                //decide si le renard se reproduit ou pas
                if(renard->seReproduit(0)){
                    ajouteAnimal(Espece::renard,renard->getCoord());
                }else{
                    grille.setCase(-1,renard->getCoord());
                }
                grille.setCase(renard->getId(),lapinDevore->getCoord());
                renard->setCoord(lapinDevore->getCoord());
                population.supprime(lapinDevore->getId());

            }else{
                renard->jeune();
                if(renard->meurt()){
                    grille.setCase(-1,renard->getCoord());
                    population.supprime(renard->getId());
                }
            }
        }
    }
    
    
    

};