CXXFLAGS = -g -std=c++17
WARNINGS = -Wall -Wextra -Wpedantic
OBJS = main.o isSorted.o val.o which.o merg.o

run : main
	./main

main : $(OBJS)
	g++ $(OBJS) -o main

main.o : main.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c main.cpp

isSorted.o : isSorted.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c isSorted.cpp

val.o : val.cpp
	g++  $(WARNINGS) $(CXXFLAGS) -c val.cpp

which.o: which.cpp
	g++  $(WARNINGS) $(CXXFLAGS) -c which.cpp

merg.o : merg.cpp
	g++  $(WARNINGS) $(CXXFLAGS) -c merg.cpp

clean:
	@rm -f *.o main