main: main.o Sorting.o
	g++ -g -O0 -Wall -std=c++14 -pedantic-errors -o main main.o Sorting.o


main.o: main.cpp
        g++ -g -O0 -Wall -std=c++14 -pedantic-errors -c main.cpp


Sorting.o: Sorting.cpp Sorting.h
        g++ -g -O0 -Wall -std=c++14 -pedantic-errors -c Sorting.cpp

clean:
	rm *.o
	rm main
	rm *~

run:
	./main ordered.txt
