ofiles = main.o TwoDArray.o 
gpp_o = g++ -c -std=c++98

main:$(ofiles)
	g++ -g -std=c++98 $(ofiles) -o main

Task1.o: Task1.cpp
	$(gpp_o) Task1.cpp

TwoDArray.o: TwoDArray.h TwoDArray.cpp
	$(gpp_o) TwoDArray.cpp

run: main
	./main

valgrind: main
	valgrind -s --leak-check=full ./main

clean:
	rm *.o main