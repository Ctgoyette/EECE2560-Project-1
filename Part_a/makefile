all: output run

output: main.o code.o	
	g++ main.o code.o -o output

run: output
	output

main.o: main.cpp
	g++ -c main.cpp

code.o: code.cpp code.hpp
	g++ -c code.cpp

