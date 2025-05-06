%.o : source/%.cpp
	g++ -g $^ -c -o $@

test%.o : test/test%.cpp
	g++ -g -c $< -o $@

testcoord : coord.o testcoord.o ensemble.o
	g++ -g $^ -o $@

testensemble: ensemble.o testensemble.o
	g++ -g $^ -o $@
	
clean: 
	rm *.o testcoord
