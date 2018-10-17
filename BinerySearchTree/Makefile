main: main.o itemType.o BinaryTree.o
	g++ -g -O0 -Wall -std=c++14 -pedantic-errors -o main Main.o itemType.o BinaryTree.o

main.o: Main.cpp
	g++ -g -O0 -Wall -std=c++14 -pedantic-errors -c Main.cpp


BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -g -O0 -Wall -std=c++14 -pedantic-errors -c BinaryTree.cpp


itemType.o: itemType.cpp itemType.h
	g++ -g -O0 -Wall -std=c++14 -pedantic-errors -c itemType.cpp

clean:
	rm *.o
	rm main
	rm *~

run:
	./main input.txt
