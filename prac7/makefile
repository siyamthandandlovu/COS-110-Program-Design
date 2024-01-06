ofiles = Event.o main.o
gpp_o = g++ -c -std=c++98

main:$(ofiles)
	g++ -g -std=c++98 $(ofiles) -o main

Event.o: Event.h Event.cpp
	$(gpp_o) Event.cpp

run: main
	./main

valgrind: main
	valgrind -s --leak-check=full ./main

clean:
	rm *.o main