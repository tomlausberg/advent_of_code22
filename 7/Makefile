CC = g++
CFLAGS = -std=c++11 -O2

all: main

main: main.o filesystem.o
	$(CC) $(CFLAGS) main.o filesystem.o -o main

main.o: main.cpp filesystem.hpp
	$(CC) $(CFLAGS) -c main.cpp

filesystem.o: filesystem.cpp filesystem.hpp
	$(CC) $(CFLAGS) -c filesystem.cpp

clean:
	rm -f *.o main
