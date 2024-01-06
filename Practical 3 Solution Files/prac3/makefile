ofiles = studentmain.o chesspiece.o chessboard.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

studentmain.o: studentmain.cpp chesspiece.h chessboard.h
	$(gpp_o) studentmain.cpp

chesspiece.o: chesspiece.cpp chesspiece.h
	$(gpp_o) chesspiece.cpp

chessboard.o: chessboard.cpp chessboard.h chesspiece.h
	$(gpp_o) chessboard.cpp

run: main
	./main

clean:
	rm *.o main