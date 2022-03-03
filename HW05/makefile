target: hw5

hw5: BoardGame2d.cpp BoardGame2d.h PegSolitaire.cpp PegSolitaire.h main.cpp
	g++ -std=c++11 main.cpp BoardGame2d.cpp PegSolitaire.cpp EightPuzzle.cpp Klotski.cpp -o output
	./output

debug:
	g++ -std=c++11 -g main.cpp BoardGame2d.cpp PegSolitaire.cpp Klotski.cpp -o output
	gdb ./output

memory:
	g++ -std=c++11 -g main.cpp BoardGame2d.cpp PegSolitaire.cpp -o output
	valgrind ./output