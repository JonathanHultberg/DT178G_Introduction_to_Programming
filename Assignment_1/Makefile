run: maxminmed
	./maxminmed < values.txt 

maxminmed: maxminmed.o
	g++ -o maxminmed maxminmed_Jonathan_Hultberg.o

maxminmed.o : maxminmed_Jonathan_Hultberg.cpp
	g++ -c maxminmed_Jonathan_Hultberg.cpp

clean:
	@rm -f *.o 