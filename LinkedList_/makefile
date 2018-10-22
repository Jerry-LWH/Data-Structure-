main: main.o DataType.o SortedLinkedList.o
	g++ -g -O0 -Wall -std=c++14 -pedantic-errors -o main main.cpp DataType.o SortedLinkedList.o

main.o: main.cpp
	g++ -g -O0 -Wall -std=c++14 -pedantic-errors -c main.cpp

DataType.o: DataType.cpp DataType.h
	g++ -g -O0 -Wall -std=c++14 -pedantic-errors -c DataType.cpp

SortedLinkedList.o: SortedLinkedList.cpp SortedLinkedList.h
	g++ -g -O0 -Wall -std=c++14 -pedantic-errors -c SortedLinkedList.cpp

clean:
	rm *.o
	rm main
	rm *~

run:
	./main input.txt