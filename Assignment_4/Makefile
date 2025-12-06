CXXFLAGS = -g -std=c++17
WARNINGS = -Wall -Wextra -Wpedantic
OBJS = main.o readFormat.o copyToVec.o sortByVal.o print.o

run : main
	./main

main : $(OBJS)
	g++ $(OBJS) -o main

main.o : main.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c main.cpp

readFormat.o : readFormat.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c readFormat.cpp

copyToVec.o : copyToVec.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c copyToVec.cpp

sortByVal.o : sortByVal.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c sortByVal.cpp

print.o : print.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c print.cpp

clean:
	@rm -f *.o main