mainprogram: main.o hugeint.o
	g++ -o mainprogram main.o hugeint.o
main.o : hugeint.h main.cpp
	g++ -c main.cpp
hugeint.o: hugeint.h hugeint.cpp
	g++ -c hugeint.cpp

clean:
	rm *.o
