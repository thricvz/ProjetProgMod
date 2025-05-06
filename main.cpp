#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "coord.hpp"

int main(int argc, const char** argv){
    Coord c = Coord(50);
	cout<<c<<endl;
	Ensemble e = Ensemble();
	cout<<e<<endl;
}