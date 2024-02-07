all: output

output: main.o mastermind.o code.o response.o
	g++ main.o mastermind.o code.o response.o -o part_b

run:
	output

main.o:
	g++ -c main.cpp

mastermind.o: mastermind.cpp mastermind.hpp 
	g++ -c mastermind.cpp

response.o: response.hpp response.cpp
	g++ -c response.cpp

code.o: code.cpp code.hpp
	g++ -c code.cpp
