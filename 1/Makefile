# Specify the target file and the objects that it depends on
main: main.o
	# Specify the command to create the target file
	g++ main.o -o main

# Specify how to create the object files
main.o: main.cpp
	g++ -c main.cpp

helpers.o: helpers.cpp
	g++ -c helpers.cpp

# Specify a clean target that removes object files and the target
clean:
	rm -f *.o main
