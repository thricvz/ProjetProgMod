#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "coord.hpp"


TEST_SUITE_BEGIN("Constructeur");

TEST_CASE("Cunstructeur vide"){
    Ensemble e;
    CHECK(e.estVide());
    
}

TEST_SUITE_END();

TEST_SUITE_BEGIN("Cardinal");

TEST_CASE("Ensemble vide"){
    Ensemble e;
    CHECK(e.cardinal()==0);
    
}

TEST_CASE("Ensemble non Vide"){
    Ensemble e;
    e.ajoute(4);
    e.ajoute(2);
    e.ajoute(2);
    CHECK_MESSAGE(e.cardinal()==3,"Le cardinal doit etre de 3 , pourtant est de" << e.cardinal());
    
}


TEST_SUITE_END();


TEST_SUITE_BEGIN("Methode ajoute et tire");

TEST_CASE("Ajoute interdit"){
    Ensemble e;
    for(int i=0;i<MAXCARD;i++){
        e.ajoute(3);
    }
    CHECK_THROWS_AS(e.ajoute(5),std::invalid_argument);

    
}

TEST_CASE("AJOUTE interdit"){
    Ensemble e;
    for(int i=0;i<MAXCARD;i++){
        e.ajoute(3);
    }
    CHECK_THROWS_AS(e.ajoute(5),std::invalid_argument);

    
};


TEST_CASE("TIRE interdit"){
    Ensemble e;
    CHECK_THROWS_AS(e.tire(),std::invalid_argument);
    
};



TEST_CASE("TIRE fonctionnement correct"){
    Ensemble e;
    e.ajoute(4);
    e.ajoute(3);
    e.tire();
    CHECK(e.cardinal()==1);
    e.tire();
    CHECK(e.estVide());
}

TEST_SUITE_END();

int main(int argc, const char** argv){
  doctest::Context context(argc, argv);
  int test_result = context.run();
  if (context.shouldExit()) return test_result;


  return 0;
};
