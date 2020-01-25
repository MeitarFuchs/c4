CC=gcc
FLAGS=-Wall -c

all:frequency

frequency: main.o
	$(CC) -Wall -o frequency treeTrie.o main.o

treeTrie.o: treeTrie.c treeTrie.h
	$(CC) $(FLAGS) treeTrie.c

main.o: main.c
	$(CC) $(FLAGS) treeTrie.c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a frequency a.out
