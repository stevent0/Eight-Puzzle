
all: main

main: main.o EightPuzzleNode.o Solver.o
	g++ -O2 -o main main.o EightPuzzleNode.o Solver.o 

main.o: src/main.cpp
	g++ -c src/main.cpp 

EightPuzzleNode.o: src/EightPuzzleNode.cpp
	g++ -c src/EightPuzzleNode.cpp

Solver.o: src/Solver.cpp
	g++ -c src/Solver.cpp

clean:
	rm *.o main
