ofiles = NumberTester.o main.o
gpp_o = g++ -c -std=c++98

main:$(ofiles)
	g++ -g -std=c++98 $(ofiles) -o main

NumberTester.o: NumberTester.h NumberTester.cpp
	$(gpp_o) NumberTester.cpp

run: main
	./main

valgrind: main
	valgrind -s --leak-check=full ./main

clean:
	rm *.o main