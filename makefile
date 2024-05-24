proj1.x: main.o bgp.o
	g++ -o proj1.x main.o bgp.o

main.o: main.cpp bgp.h
	g++ -c main.cpp

bgp.o: bgp.cpp bgp.h
	g++ -c bgp.cpp

clean:
	rm *.o proj1.x
