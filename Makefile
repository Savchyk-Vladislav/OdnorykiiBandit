all: main

main: main.cpp
	g++ main.cpp -o prog -w
	./prog
