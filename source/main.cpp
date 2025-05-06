#define DOCTEST_CONFIG_IMPLEMENT
#include "../include/doctest.h"
#include "../include/coord.hpp"

int main(int argc, const char** argv){
    Coord c = Coord(50);
	cout<<c<<endl;
	Ensemble e = Ensemble();
	cout<<e<<endl;
}