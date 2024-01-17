ofiles = main.o
gpp_o = g++ -c -std=c++98

main:$(ofiles)
	g++ -g -std=c++98 $(ofiles) -o main

run: main
	./main

clean:
	rm *.o main