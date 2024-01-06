comp: studentmain.o matrix.o
	g++ studentmain.o matrix.o -o comp

studentmain.o: studentmain.cpp
	g++ -c studentmain.cpp

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

clean:
	rm *.o comp