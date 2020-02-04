#all: build/main.o
#	g++ -std=c++17 build/main.o build/Alarm.o -o ./build/output
#
#build/main.o: src/main.cpp src/Alarm.cpp include/Alarm.h
#	g++ -c src/main.cpp -o build/main.o
#
#build/Alarm.o: src/Alarm.cpp include/Alarm.h
#	g++ -c src/Alarm.cpp -o build/Alarm.o
#run:
#	make all
#	./build/output.o
#clean:
#	rm -f ./build/*.o
all:
	g++ -std=c++17 -Wall -Wextra -Og -g3 -o ./build/a.o ./src/main.cpp ./src/Alarm.cpp

Alarm: src/Alarm.cpp include/Alarm.h
	g++ -c -std=c++17 -Wall -Wextra -Og -g3 -I include -o ./build/Alarm.o ./src/Alarm.cpp

Display: src/Display.cpp include/Display.h
	g++ -c -std=c++17 -Wall -Wextra -Og -g3 -I include -o ./build/Display.o ./src/Display.cpp

Generator: src/Generator.cpp include/Generator.h
	g++ -c -std=c++17 -Wall -Wextra -Og -g3 -I include -o ./build/Generator.o ./src/Generator.cpp

Pipe: src/Pipe.cpp include/Pipe.h
	g++ -c -std=c++17 -Wall -Wextra -Og -g3 -I include -o ./build/Pipe.o ./src/Pipe.cpp
run:
	make all
	./build/a.o
clean:
	rm -f ./build/a.o