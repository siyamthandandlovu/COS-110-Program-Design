ofiles = Passenger.o Cargo.o SecretCargo.o main.o
gpp_o = g++ -c -std=c++98

main:$(ofiles)
	g++ -g -std=c++98 $(ofiles) -o main

Passenger.o: Passenger.h Passenger.cpp
	$(gpp_o) Passenger.cpp

Cargo.o: Cargo.h Cargo.cpp
	$(gpp_o) Cargo.cpp

SecretCargo.o: SecretCargo.h SecretCargo.cpp
	$(gpp_o) SecretCargo.cpp

run: main
	./main

clean:
	rm *.o main