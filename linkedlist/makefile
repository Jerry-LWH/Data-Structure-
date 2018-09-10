main: main.o List.o
	g++ -o main main.o List.o

main.o: main.cpp List.h
	g++ -g -O0 -Wall -std=c++14 -pedantic-errors -c main.cpp

List.o: List.cpp List.h
	g++ -g -O0 -Wall -std=c++14 -pedantic-errors -c List.cpp
