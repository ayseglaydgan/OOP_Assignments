target: hw1

hw1: DayOfYearSet.cpp DayOfYearSet.h main.cpp
	g++ -std=c++11 main.cpp DayOfYearSet.cpp  -o output
	./output

debug:
	g++ -std=c++11 -g main.cpp DayOfYearSet.cpp -o output
	gdb ./output

memory:
	g++ -std=c++11 -g main.cpp DayOfYearSet.cpp -o output
	valgrind ./output