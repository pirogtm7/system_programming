lab: main.o libnames.a
	g++ -o lab main.o -L. -lnames
main.o: main.cpp
	g++ -c main.cpp
libnames.a: resultNames.o fileNames.o
	ar cr libnames.a resultNames.o fileNames.o
resultNames.o: resultNames.cpp
	g++ -c resultNames.cpp
fileNames.o: fileNames.cpp
	g++ -c fileNames.cpp
clean:
	rm -f *.o *.a selNames.txt lab

