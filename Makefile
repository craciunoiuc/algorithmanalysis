CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: algo1.o algo2.o algo3.o main.o

RadixSort: algo1.o main.o
	$(CC) main.o algo1.o -o RadixSort $(CFLAGS)

ShellSort: algo2.o main.o
	$(CC) main.o algo2.o -o ShellSort $(CFLAGS)

TimSort: algo3.o main.o
	$(CC) main.o algo3.o -o TimSort $(CFlAGS)

main.o: main.cpp
	$(CC) main.cpp -c $(CFLAGS)

algo.o: algo.cpp
	$(CC) algo.cpp -c $(CFLAGS)

algo1.o: algo1.cpp
	$(CC) algo1.cpp -c $(CFLAGS)

algo2.o: algo2.cpp
	$(CC) algo2.cpp -c $(CFLAGS)

algo3.o: algo3.cpp
	$(CC) algo3.cpp -c $(CFLAGS)

generator: generator.cpp
	$(CC) generator.cpp -o generator $(CFLAGS)

.PHONY: clean
clean:
	rm -rf *.o
