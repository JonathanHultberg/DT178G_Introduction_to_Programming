# Jonathan Hultberg
# 2025-01-13
# DT178G Introduktion till programmering
# Projekt alternativ 2: Contacts

CXXFLAGS = -g -std=c++17
WARNINGS = -Wall -Wextra -Wpedantic
OBJS = main.o MemoryManager.o AddContact.o ContactViewer.o Utility.o Validation.o

run : main
	./main

main : $(OBJS)
	g++ $(WARNINGS) $(CXXFLAGS) $(OBJS) -o main

main.o : main.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c main.cpp

MemoryManager.o : MemoryManager.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c MemoryManager.cpp

AddContact.o : AddContact.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c AddContact.cpp

ContactViewer.o : ContactViewer.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c ContactViewer.cpp	

Utility.o : Utility.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c Utility.cpp

Validation.o : Validation.cpp
	g++ $(WARNINGS) $(CXXFLAGS) -c Validation.cpp

clean:
	@rm -f *.o main