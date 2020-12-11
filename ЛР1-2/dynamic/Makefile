lab: main.o libnames.so
	g++ -o lab main.o -L. -lnames -Wl,-rpath,.
main.o: main.cpp
	g++ -c main.cpp
libnames.so: resultNames.o fileNames.o
	g++ -shared -o libnames.so resultNames.o fileNames.o
resultNames.o: resultNames.cpp
	g++ -c -fPIC resultNames.cpp
fileNames.o: fileNames.cpp
	g++ -c -fPIC fileNames.cpp
clean:
	rm -f *.o *.so selNames.txt lab

