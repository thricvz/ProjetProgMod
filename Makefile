%.o : source/%.cpp
	g++ -g $^ -o $@

testcoord : testcoord.o coord.o
	g++ -g $^ -o $@

	