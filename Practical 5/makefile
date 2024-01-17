ofiles = NumberTester.o ValueDependantTester.o ValueIndependantTester.o IsDivisible.o IsGreater.o IsSmaller.o IsEvenOdd.o IsPrimeNumber.o TesterInterface.o main.o
gpp_o = g++ -c -std=c++98

main:$(ofiles)
	g++ -g -std=c++98 $(ofiles) -o main

NumberTester.o: NumberTester.h NumberTester.cpp
	$(gpp_o) NumberTester.cpp

ValueDependantTester.o: ValueDependantTester.h ValueDependantTester.cpp
	$(gpp_o) ValueDependantTester.cpp

ValueIndependantTester.o: ValueIndependantTester.h ValueIndependantTester.cpp
	$(gpp_o) ValueIndependantTester.cpp

IsDivisible.o: IsDivisible.h IsDivisible.cpp
	$(gpp_o) IsDivisible.cpp

IsGreater.o: IsGreater.h IsGreater.cpp
	$(gpp_o) IsGreater.cpp

IsSmaller.o: IsSmaller.h IsSmaller.cpp
	$(gpp_o) IsSmaller.cpp

IsEvenOdd.o: IsEvenOdd.h IsEvenOdd.cpp
	$(gpp_o) IsEvenOdd.cpp

IsPrimeNumber.o: IsPrimeNumber.h IsPrimeNumber.cpp
	$(gpp_o) IsPrimeNumber.cpp

TesterInterface.o: TesterInterface.h TesterInterface.cpp
	$(gpp_o) TesterInterface.cpp

run: main
	./main

valgrind: main
	valgrind -s --leak-check=full ./main

clean:
	rm *.o main