CC=gcc
FLAGS= -Wall -c

all: main.o treeTrie.o frequency

frequency: treeTrie.o main.o
		$(CC) -Wall -g -fPIC -o frequency treeTrie.o main.o -lm

treeTrie.o: treeTrie.c treeTrie.h
		$(CC) $(FLAGS) -fPIC -c treeTrie.c
main.o: main.c treeTrie.c treeTrie.h
		$(CC) $(FLAGS) -fPIC -c main.c

.PHONY: clean all

clean:	
		rm -f *.o frequency