Run : parser
	./parser

parser : parser_Jonathan_Hultberg.o 
	g++ -o parser parser_Jonathan_Hultberg.o

parser.o : parser_Jonathan_Hultberg.cpp 
	g++ -c parser_Jonathan_Hultberg.cpp

clean:
	@rm -f *.o

