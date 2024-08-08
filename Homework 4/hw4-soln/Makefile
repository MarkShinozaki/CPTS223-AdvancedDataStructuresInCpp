# Makefile

CC = g++ -Wall

all: main

MaxSubSum.o: MaxSubSum.h MaxSubSum.cc
	$(CC) -c MaxSubSum.cc

main: MaxSubSum.o main.cc
	$(CC) -o main MaxSubSum.o main.cc

clean:
	/bin/rm -f *.o main
