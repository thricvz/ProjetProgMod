#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "coord.hpp"

//TEST VARIABLE GLOBALE TAILLE GRILLE
TEST_CASE("Test variable Globale TAILLEGRILLE" ){

    CHECK_MESSAGE(TAILLEGRILLE == 40,"La variable doit avoir la taille 40 mais est de taille " << TAILLEGRILLE);
};

//TEST CONSTRUCTEUR AVEC COORD X,Y 
TEST_SUITE_BEGIN("CONSTRUCTEUR COORD avec  parametres x,y ");


TEST_CASE("COORDONNEE VALIDE" ){

    Coord coordTest(0,2);
    CHECK_MESSAGE(coordTest.getx()==0,"Cordonnée x est incorrecte : attendu 0 , obtenu" << coordTest.getx());
    CHECK_MESSAGE(coordTest.gety()==2,"Cordonnée y est incorrecte : attendu 0 , obtenu" << coordTest.gety());
};



TEST_SUITE_END();


//SURCHARGE OPERATEURS
TEST_SUITE_BEGIN("SURCHARGE OPERATEURS");


TEST_CASE("OPERATEUR ==" ){

    Coord coordTest(0,2);
    Coord coordTest2(0,2);
    CHECK(coordTest==coordTest2);
    
};
TEST_CASE("OPERATEUR == 2" ){

    Coord coordTest(0,2);
    Coord coordTest2(34,5);
    CHECK(!(coordTest==coordTest2));
    
};

TEST_CASE("OPERATEUR !=" ){

    Coord coordTest(25,2);
    Coord coordTest2(0,2);
    CHECK(coordTest!=coordTest2);
    
};
TEST_CASE("OPERATEUR != 2" ){

    Coord coordTest(34,5);
    Coord coordTest2(34,5);
    CHECK(!(coordTest!=coordTest2));
    
};


TEST_SUITE_END();

//CONSTRUCTOR
TEST_SUITE_BEGIN("CONSTRUCTEUR COORD avec unique parametre ");


TEST_CASE("COORDONNEE VALIDE" ){

    Coord coordTest(2);
    CHECK_MESSAGE(coordTest.getx()==0,"Cordonnée x est incorrecte : attendu 0 , obtenu" << coordTest.getx());
    CHECK_MESSAGE(coordTest.gety()==2,"Cordonnée y est incorrecte : attendu 0 , obtenu" << coordTest.gety());
};

TEST_SUITE_END();

// to INT FUNCTION

TEST_CASE("TO INT FUNCTION" ){

    Coord coordTest(2);
    CHECK_MESSAGE(coordTest.toInt()==2,"Retour incorrect : attendu 2 , obtenu :" << coordTest.toInt());
};


TEST_CASE("TO INT FUNCTION 2" ){

    Coord coordTest(39);
    CHECK_MESSAGE(coordTest.toInt()==39,"Retour incorrect : attendu 39 , obtenu :" << coordTest.toInt());
};







int main(int argc, const char** argv){
  doctest::Context context(argc, argv);
  int test_result = context.run();
  if (context.shouldExit()) return test_result;



  return 0;
};
