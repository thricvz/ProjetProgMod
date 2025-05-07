#include "../include/jeu.hpp"


void Jeu::ajouteAnimal(Espece espece,Coord c){
    int idAnimal = population.set(espece,c);
    
    grille.setCase(idAnimal,c);
}

Jeu::Jeu(float pLapin,float pRenard){
    //calcule le nombre de renards et de lapins a placer
    int Nrenards = static_cast<int>(TAILLEGRILLE*TAILLEGRILLE*pRenard);
    int Nlapins = static_cast<int>(TAILLEGRILLE*TAILLEGRILLE*pLapin);

    srand(0);
    
    while(Nrenards>0){
        //tire une position au hasard
        int x = rand()%TAILLEGRILLE;
        int y = rand()%TAILLEGRILLE;
        Coord emplacement(x,y);
        if(grille.caseVide(emplacement)){
            Nrenards--;
            ajouteAnimal(Espece::renard,emplacement);
        }
            
    }
    
    
    while(Nlapins>0){
        //tire une position au hasard
        int x = rand()%TAILLEGRILLE;
        int y = rand()%TAILLEGRILLE;
        Coord emplacement(x,y);
        if(grille.caseVide(emplacement)){
            Nlapins--;
            ajouteAnimal(Espece::lapin,emplacement);
        }
            
    } 




    //place tous les lapins
    //par defaut les autres cases sont deja vides
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
        if(grille.caseVide(n))
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

void Jeu::comportementLapin(int id){
    Animal * lapin = population.get(id);
    Coord ancienCoord = lapin->getCoord();
    //checker son deplacement
    vector<Coord> casesVoisines = voisinsVides(ancienCoord);
    if(casesVoisines.size()==0){
        return;
    }else if(casesVoisines.size()==1){
        Coord nouvelleCoord = casesVoisines[0];
        lapin->setCoord(nouvelleCoord);
        grille.setCase(-1,ancienCoord);
        grille.setCase(id,nouvelleCoord);
    }else{
        int choixCase = rand()%(casesVoisines.size());
        Coord nouvelleCoord = casesVoisines[choixCase];
        lapin->setCoord(nouvelleCoord);
        grille.setCase(-1,ancienCoord);
        grille.setCase(id,nouvelleCoord);
    }


    //checker reproduction
    if(lapin->seReproduit(casesVoisines.size())){
        ajouteAnimal(Espece::lapin,ancienCoord);
    }
}

void Jeu::comportementRenard(int id){
    Animal * renard = population.get(id);
    Coord ancienCoord = renard->getCoord();
    //checker son deplacement
    vector<Coord> proiesVoisines = voisinsEspece(Espece::lapin,ancienCoord);
    vector<Coord> casesVoisines = voisinsVides(ancienCoord);

    //deux modes de se deplacer : en mangant ou en vaguant

    if(casesVoisines.size()==0){
        //on jeune et on mange
        renard->jeune();

        //check s'il meurt
        if(renard->meurt()){
            grille.setCase(-1,ancienCoord);
            population.supprime(id);
            return ;
        }

        //decide si on a un seul choix ou plusieurs
        if(casesVoisines.size()==0){
            return;
        }else if(casesVoisines.size()==1){
            Coord nouvelleCoord = casesVoisines[0];
            renard->setCoord(nouvelleCoord);
            grille.setCase(-1,ancienCoord);
            grille.setCase(id,nouvelleCoord);
        }else{
            int choixCase = rand()%(casesVoisines.size());
            Coord nouvelleCoord = casesVoisines[choixCase];
            renard->setCoord(nouvelleCoord);
            grille.setCase(-1,ancienCoord);
            grille.setCase(id,nouvelleCoord);
        }
    }else{
        if(proiesVoisines.empty()){
            return ;
        }else if(proiesVoisines.size()==1){
            int idProie = grille.getCase(proiesVoisines[0]);
            Animal *proie = population.get(idProie);
            Coord nouvelleCoord = proie->getCoord();

            renard->setCoord(nouvelleCoord);
            grille.setCase(-1,ancienCoord);
            grille.setCase(id,nouvelleCoord);
            
            population.supprime(proie->getId());
            
        }else{
            int choixProie = rand()%(proiesVoisines.size());
            int idProie = grille.getCase(proiesVoisines[choixProie]);
            Animal *proie = population.get(idProie);
            Coord nouvelleCoord = proie->getCoord();

            renard->setCoord(nouvelleCoord);
            grille.setCase(-1,ancienCoord);
            grille.setCase(id,nouvelleCoord);
            
            population.supprime(proie->getId());
        }
    }


    //checker reproduction
    if(renard->seReproduit(casesVoisines.size())){
        ajouteAnimal(Espece::renard,ancienCoord);
    }
}

void Jeu::joueTour(){
    //moviemnt lapin
    for(auto animal: population.getIds()){
        if(population.get(animal)->getEspece()== Espece::lapin){
            comportementLapin(animal);
        }
    }
    //mouvement des renards
    for(auto animal: population.getIds()){
        if(population.get(animal)!=nullptr && population.get(animal)->getEspece()== Espece::renard){
            comportementRenard(animal);
        }
    }

};


std::string Jeu::lettreCase(Coord c){
    if(grille.caseVide(c))
       return "   ";
    //discover what animal it is
    Animal * animal = population.get(grille.getCase(c));
    if(animal->getEspece() == Espece::lapin)
        return "L";

    return "R";
}