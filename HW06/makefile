target: hw6

hw6:
	g++ -std=c++11 main.cpp -o output
	./output

output:
	g++ -std=c++11 main.cpp -o output
	./output > output.txt

debug:
	g++ -std=c++11 -g main.cpp -o output
	gdb ./output

memory:
	g++ -std=c++11 -g main.cpp -o output
	valgrind ./output

clear:
	rm -f output.txt
	rm -f output