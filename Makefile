%.o : source/%.cpp
	g++ -g $^ -c -o $@

test%.o : test/test%.cpp
	g++ -g -c $< -o $@

testcoord : coord.o testcoord.o ensemble.o
	g++ -g $^ -o $@

