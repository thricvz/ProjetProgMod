Ensemble.o : Ensemble.cpp
	g++ -c Ensemble.cpp -o Ensemble.o

coord.o : coord.cpp
	g++ -c coord.cpp -o coord.o

testCoord : coord.o testCoord.cpp Ensemble.cpp
	g++ coord.o testCoord.cpp -o testCoord

testEnsemble : Ensemble.o testEnsemble.cpp
	g++ Ensemble.o testEnsemble.cpp -o testEnsemble

main : coord.o main.cpp
	g++ coord.o main.cpp -o main

clean :
	rm main testCoord testEnsemble
