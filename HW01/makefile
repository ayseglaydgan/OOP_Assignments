target: hw1

hw1: solo_test.cpp solo_test.h main.cpp
	g++ -std=c++11 main.cpp solo_test.cpp  -o output
	./output

debug:
	g++ -std=c++11 -g main.cpp solo_test.cpp -o output
	gdb ./output

memory:
	g++ -std=c++11 -g main.cpp solo_test.cpp -o output
	valgrind ./output