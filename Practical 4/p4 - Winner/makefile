ofiles = main.o TwoDArray.o CountArray.o SortArray.o SumArray.o
gpp_o = g++ -c -std=c++98

main:$(ofiles)
	g++ -g -std=c++98 $(ofiles) -o main

TwoDArray.o: TwoDArray.h TwoDArray.cpp
	$(gpp_o) TwoDArray.cpp

CountArray.o: CountArray.h CountArray.cpp
	$(gpp_o) CountArray.cpp

SortArray.o: SortArray.h SortArray.cpp
	$(gpp_o) SortArray.cpp

SumArray.o: SumArray.h SumArray.cpp
	$(gpp_o) SumArray.cpp

run: main
	./main

valgrind: main
	valgrind -s --leak-check=full ./main

clean:
	rm *.o main