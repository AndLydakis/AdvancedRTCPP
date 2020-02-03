all:
	g++ -std=c++17 -Og -g3 -o ./build/a.o ./src/main.cpp
run:
	make all
	./build/a.o
clean:
	rm -f ./build/a.o
